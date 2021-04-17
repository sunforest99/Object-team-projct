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
	
	// 배경음악 시끄러워서 주석처리
	/*auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("bgm/dragon_flight2.mp3", true);*/

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
	_bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(_bg2, OTHER_ZORDER::E_BACKBROUND);

	_logo = Sprite::create("ui/logo.png");
	_logo->setScale(D_BASE_SACLE);
	_logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 500));
	this->addChild(_logo, OTHER_ZORDER::E_LOGO);

	_character = Sprite::create(_charname[_charindex]);
	_character->setScale(1.3f);
	_character->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
	this->addChild(_character, OTHER_ZORDER::E_STARTSCENE_CHAR);

	_label = Label::createWithTTF("Touch to Start", "fonts/Marker Felt.ttf", 70);
	_label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 500));
	this->addChild(_label, OTHER_ZORDER::E_LABEL);

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
	_bg1->setPosition(Vec2(0, _bg1->getPositionY() - D_BACKGROUND_SPEED));
	_bg2->setPosition(Vec2(0, _bg2->getPositionY() - D_BACKGROUND_SPEED));
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
