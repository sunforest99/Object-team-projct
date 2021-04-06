#include "stdafx.h"

Scene* InGameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = InGameScene::create();

	scene->addChild(layer);

	return scene;
}

InGameScene::InGameScene()
{
	rkeycheck = false;
	lkeycheck = false;
}
InGameScene::~InGameScene()
{
	player->release();
}

bool InGameScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------InGameScene Log Start-----------");

	InitBG();
	InitObj();

	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("bgm/dragon_flight.mp3", true);

	this->schedule(schedule_selector(InGameScene::SceneUpdate), 0.0f);
	this->schedule(schedule_selector(InGameScene::MonsterUpdate), 3.0f);
	this->schedule(schedule_selector(InGameScene::MeteoUpdate), 2.0f);

	// 터치 이벤트를 ONE_BY_ONE 형식으로 받겠다
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	// 키보드 이벤트 리스너 생성
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(InGameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(InGameScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void InGameScene::InitBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	bg1 = Sprite::create("background/01.png");
	bg1->setAnchorPoint(Vec2::ZERO);
	bg1->setScale(D_BASE_SACLE);
	bg1->setPosition(Vec2::ZERO);
	this->addChild(bg1, SET_Z_ORDER::E_BACKGROUND);

	bg2 = Sprite::create("background/01.png");
	bg2->setAnchorPoint(Vec2::ZERO);
	bg2->setScale(D_BASE_SACLE);
	bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(bg2, SET_Z_ORDER::E_BACKGROUND);
}

void InGameScene::InitObj()
{
	// 플레이어 객체 생성 및 초기화
	player = new Player();
	player->Init();
	this->addChild(player, SET_Z_ORDER::E_PLAYER);
}

void InGameScene::MeteoUpdate(float dt)
{
	meteo = new Meteo();
	meteo->Init();
	this->addChild(meteo, SET_Z_ORDER::E_METEO);
	v_meteo.push_back(meteo);
	meteo->release();
}

void InGameScene::MonsterUpdate(float dt)
{
	for (int i = 1; i < 6; i++)
	{
		monster = new Monster();
		monster->Init();
		monster->SpriteSetPotionX(200.f * i);
		log("y: %f", monster->GetSprite()->getPositionY());
		this->addChild(monster, SET_Z_ORDER::E_MONSTER);
		v_monster.push_back(monster);
		monster->release();
	}
}

/**
 * @brief InGameScene 업데이트 부분 이미지 움직임 담당
 * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
 **/
void InGameScene::SceneUpdate(float dt)
{
	bg1->setPosition(Vec2(0, bg1->getPositionY() - D_BACKGROUND_SPEED));
	bg2->setPosition(Vec2(0, bg2->getPositionY() - D_BACKGROUND_SPEED));
	if (bg1->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		bg1->setPositionY(D_DESIGN_HEIGHT);
	}
	if (bg2->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		bg2->setPositionY(D_DESIGN_HEIGHT);
	}

	if (rkeycheck == true && player->GetSprite()->getPositionX() < D_DESIGN_WIDTH - 125 && player->GetUnithp() > 0)
		player->AddPosX(10.f);
	else if (lkeycheck == true && 0 + 125 < player->GetSprite()->getPositionX() && player->GetUnithp() > 0)
		player->MinPosX(10.f);


	// 몬스터 업데이트 및 충돌
	for (auto it = v_monster.begin(); it != v_monster.end(); it++)
	{
		if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT * 2)
		{
			this->removeChild((*it));
			it = v_monster.erase(it);
		}

		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(player->GetSprite()->getBoundingBox()))
		{
			// TODO 충돌 되었을때 처리
			// player->ReduceHp(1);
		}
	}

	// 메테오 업데이트 및 충돌
	for (auto it = v_meteo.begin(); it != v_meteo.end(); it++)
	{
		if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT * 2)
		{
			this->removeChild((*it));
			it = v_meteo.erase(it);
		}

		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(player->GetSprite()->getBoundingBox()))
		{
			// TODO 충돌 되었을때 처리
			// player->ReduceHp(1);
		}
	}
}

/**
 * @brief 마우스 클릭 또는 터치 했을때 호출되는 callback 함수
 * @param Touch* touch 터치한 곳의 정보
 * @param  Event* unused_event 이벤트 종류
 **/
bool InGameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	if (player->GetUnithp() > 0)
		player->SetPos(touch->getLocation());

	return true;
}

void InGameScene::onTouchMoved(Touch* touch, Event* unused_event)
{
	if (0 + 125 < touch->getLocation().x && touch->getLocation().x < D_DESIGN_WIDTH - 125 && player->GetUnithp() > 0)
	{
		player->SetPos(touch->getLocation());
	}
}

void InGameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		rkeycheck = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		lkeycheck = true;
}

void InGameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		rkeycheck = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		lkeycheck = false;
}