#include "stdafx.h"

Scene* StartScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StartScene::create();

	scene->addChild(layer);

	return scene;
}

bool StartScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------StartScene Log Start-----------");
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("bgm/dragon_flight2.mp3", true);

	srand(time(NULL));
	bgindex = rand() % 3;
	charindex = rand() % 3;

	bg1 = Sprite::create(_bgname[bgindex]);
	bg1->setAnchorPoint(Vec2::ZERO);
	bg1->setScale(D_BASE_SACLE);
	bg1->setPosition(Vec2::ZERO);
	this->addChild(bg1, 0);

	bg2 = Sprite::create(_bgname[bgindex]);
	bg2->setAnchorPoint(Vec2::ZERO);
	bg2->setScale(D_BASE_SACLE);
	bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(bg2, 0);

	logo = Sprite::create("ui/logo.png");
	logo->setScale(D_BASE_SACLE);
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 500));
	this->addChild(logo, 1);

	character = Sprite::create(_charname[charindex]);
	character->setScale(1.3f);
	character->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
	this->addChild(character, 0);

	label = Label::createWithTTF("Touch to Start", "fonts/Marker Felt.ttf", 70);
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 500));
	this->addChild(label, 1);

	this->schedule(schedule_selector(StartScene::SceneUpdate), 0.0f);

	// 터치 이벤트를 ONE_BY_ONE 형식으로 받겠다
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

/**
 * @brief StartScene 업데이트 부분 이미지 움직임 담당
 * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
 **/
void StartScene::SceneUpdate(float dt)
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
	
	label->setOpacity(label->getOpacity() - 3);
}

/**
 * @brief 마우스 클릭 또는 터치 했을때 호출되는 callback 함수
 * @param Touch* touch 터치한 곳의 정보
 * @param  Event* unused_event 이벤트 종류
 **/
bool StartScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// Scene 전환
	Director::getInstance()->replaceScene(InGameScene::createScene());
	return true;
}