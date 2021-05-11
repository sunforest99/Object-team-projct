#include "stdafx.h"

/**
* @brief StartScene 생성
*/
Scene* StartScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StartScene::create();

	scene->addChild(layer);

	return scene;
}

/**
* @brief Layer 초기화
*/
bool StartScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------StartScene Log Start-----------");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("ui/ui.plist");

	// 테스트용
	UserDefault::getInstance()->setIntegerForKey("money", 1000);
	UserDefault::getInstance()->setIntegerForKey("addmoney", 0);
	// 배경음악 시끄러워서 주석처리
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/dragon_flight2.mp3", true);

	srand(time(NULL));
	_bgindex = rand() % 3;
	_charindex = rand() % 3;

	_bg1 = Sprite::create(_bgname[_bgindex]);
	_bg1->setAnchorPoint(Vec2::ZERO);
	_bg1->setScale(D_BASE_SACLE);
	_bg1->setPosition(Vec2::ZERO);
	this->addChild(_bg1, OTHER_ZORDER::E_BACKBROUND);

	_bg2 = Sprite::create(_bgname[_bgindex]);
	_bg2->setAnchorPoint(Vec2::ZERO);
	_bg2->setScale(D_BASE_SACLE);
	_bg2->setPosition(Vec2(0.f, D_DESIGN_HEIGHT));
	this->addChild(_bg2, OTHER_ZORDER::E_BACKBROUND);

	_logo = Sprite::createWithSpriteFrameName("logo.png");
	_logo->setScale(D_BASE_SACLE);
	_logo->setPosition(Vec2(visibleSize.width / 2.f, visibleSize.height / 2.f + 500.f));
	this->addChild(_logo, OTHER_ZORDER::E_LOGO);

	_character = Sprite::createWithSpriteFrameName(_charname[_charindex]);
	_character->setScale(1.3f);
	_character->setPosition(Vec2(visibleSize.width / 2.f, visibleSize.height / 2.f - 50.f));
	this->addChild(_character, OTHER_ZORDER::E_STARTSCENE_CHAR);

	_label = Label::createWithTTF("Touch to Start", "fonts/Marker Felt.ttf", 70.f);
	_label->setPosition(Vec2(visibleSize.width / 2.f, visibleSize.height / 2.f - 500.f));
	this->addChild(_label, OTHER_ZORDER::E_LABEL);

	this->schedule(schedule_selector(StartScene::SceneUpdate), 0.0f);

	// 터치 이벤트를 ONE_BY_ONE 형식으로 받겠다
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	// 키보드 이벤트 리스너 생성
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(StartScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/**
 * @brief StartScene 업데이트 부분 이미지 움직임 담당
 * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
 **/
void StartScene::SceneUpdate(float dt)
{
	_bg1->setPosition(Vec2(0.f, _bg1->getPositionY() - D_BACKGROUND_SPEED));
	_bg2->setPosition(Vec2(0.f, _bg2->getPositionY() - D_BACKGROUND_SPEED));
	if (_bg1->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		_bg1->setPositionY(D_DESIGN_HEIGHT);
	}
	if (_bg2->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		_bg2->setPositionY(D_DESIGN_HEIGHT);
	}
	
	_label->setOpacity(_label->getOpacity() - 3);
}

/**
 * @brief 마우스 클릭 또는 터치 했을때 호출되는 callback 함수
 * @param Touch* touch 터치한 곳의 정보
 * @param  Event* unused_event 이벤트 종류
 **/
bool StartScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// Scene 전환
	Director::getInstance()->replaceScene(LobbyScene::createScene());
	return true;
}

/**
* @brief 키보드 입력 이벤트 발생시 호출되는 callback 함수
* @param KeyCode keyCode 입력된 키 코드
* @param Event* event 이벤트 종류
**/
void StartScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		UserDefault::getInstance()->setIntegerForKey("bulletlevel", 1);
		UserDefault::getInstance()->setIntegerForKey("money", 1000);
		UserDefault::getInstance()->setIntegerForKey("hightscore", 0);
	}
}
