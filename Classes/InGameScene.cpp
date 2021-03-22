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

	this->schedule(schedule_selector(InGameScene::SceneUpdate), 0.0f);

	// 터치 이벤트를 ONE_BY_ONE 형식으로 받겠다
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

void InGameScene::InitBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	bg1 = Sprite::create("background/01.png");
	bg1->setAnchorPoint(Vec2::ZERO);
	bg1->setScale(D_BASE_SACLE);
	bg1->setPosition(Vec2::ZERO);
	this->addChild(bg1, 0);

	bg2 = Sprite::create("background/01.png");
	bg2->setAnchorPoint(Vec2::ZERO);
	bg2->setScale(D_BASE_SACLE);
	bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(bg2, 0);
}

void InGameScene::InitObj()
{
	// 플레이어 객체 생성 및 초기화
	player = new Player();
	player->Init();
	this->addChild(player);

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

	// 플레이어 업데이트
	player->Update();
}

/**
 * @brief 마우스 클릭 또는 터치 했을때 호출되는 callback 함수
 * @param Touch* touch 터치한 곳의 정보
 * @param  Event* unused_event 이벤트 종류
 **/
bool InGameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	player->SetPos(touch->getLocation());

	log("%f %f", player->GetPos().x, player->GetPos().y);
	return true;
}

void InGameScene::onTouchMoved(Touch* touch, Event* unused_event)
{
	player->SetPos(touch->getLocation());
}