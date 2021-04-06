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
	// �������� �ȵ�!!
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

	// ��ġ �̺�Ʈ�� ONE_BY_ONE �������� �ްڴ�
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	// Ű���� �̺�Ʈ ������ ����
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
	// �÷��̾� ��ü ���� �� �ʱ�ȭ
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
 * @brief InGameScene ������Ʈ �κ� �̹��� ������ ���
 * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
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


	// ���� ������Ʈ �� �浹
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
			// TODO �浹 �Ǿ����� ó��
			// player->ReduceHp(1);
		}
	}

	// ���׿� ������Ʈ �� �浹
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
			// TODO �浹 �Ǿ����� ó��
			// player->ReduceHp(1);
		}
	}
}

/**
 * @brief ���콺 Ŭ�� �Ǵ� ��ġ ������ ȣ��Ǵ� callback �Լ�
 * @param Touch* touch ��ġ�� ���� ����
 * @param  Event* unused_event �̺�Ʈ ����
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