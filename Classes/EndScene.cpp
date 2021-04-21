#include "stdafx.h"

/**
* @brief EndScene 생성
*/
Scene* EndScene::createScene()
{
	auto scene = Scene::create();

	auto layer = EndScene::create();

	scene->addChild(layer);

	return scene;
}

/**
* @brief Layer 초기화
*/
bool EndScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------EndScene Log Start-----------");
	_visibleSize = Director::getInstance()->getVisibleSize();

	_hightscore = UserDefault::getInstance()->getIntegerForKey("hightscore");
	_score = UserDefault::getInstance()->getIntegerForKey("score");

	if (_score > _hightscore) 
	{
		_hightscore = _score;
		UserDefault::getInstance()->setIntegerForKey("hightscore", _hightscore);
	}

	_bg1 = Sprite::create("background/01.png");
	_bg1->setAnchorPoint(Vec2::ZERO);
	_bg1->setScale(D_BASE_SACLE);
	_bg1->setPosition(Vec2::ZERO);
	this->addChild(_bg1, OTHER_ZORDER::E_BACKBROUND);

	_bg2 = Sprite::create("background/01.png");
	_bg2->setAnchorPoint(Vec2::ZERO);
	_bg2->setScale(D_BASE_SACLE);
	_bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(_bg2, OTHER_ZORDER::E_BACKBROUND);

	_layer = Sprite::create("layer.png");
	_layer->setScale(100.f);
	_layer->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2));
	_layer->setOpacity(200);
	this->addChild(_layer, OTHER_ZORDER::E_LAYER);

	InitUi();

	this->schedule(schedule_selector(EndScene::SceneUpdate), 0.0f);

	return true;
}

/**
* @brief Ui 초기화
*/
void EndScene::InitUi()
{
	_gameoverlabel = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 70);
	_gameoverlabel->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 500));
	this->addChild(_gameoverlabel, OTHER_ZORDER::E_LABEL);

	_hightscoreUi = Label::createWithTTF("Hight Score", "fonts/Marker Felt.ttf", 70);
	_hightscoreUi->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 150));
	this->addChild(_hightscoreUi, OTHER_ZORDER::E_LABEL);

	_hightscorelabel = Label::createWithTTF(StringUtils::format("%lu", _hightscore), "fonts/Marker Felt.ttf", 70);
	_hightscorelabel->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 50));
	this->addChild(_hightscorelabel, OTHER_ZORDER::E_LABEL);

	_scoreUi = Label::createWithTTF("Score", "fonts/Marker Felt.ttf", 70);
	_scoreUi->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 - 100));
	this->addChild(_scoreUi, OTHER_ZORDER::E_LABEL);

	_scorelabel = Label::createWithTTF(StringUtils::format("%lu", _score), "fonts/Marker Felt.ttf", 70);
	_scorelabel->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 - 200));
	this->addChild(_scorelabel, OTHER_ZORDER::E_LABEL);	

	_restartbtn = ui::Button::create("ui/btn_restart_n.png", "ui/btn_restart_c.png");
	_restartbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(LobbyScene::createScene());
			break;
		default:
			break;
		}
		});
	_restartbtn->setTitleText("Jump to Lobby");
	_restartbtn->setTitleFontSize(50.f);
	_restartbtn->setScale(0.8f);
	_restartbtn->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 - 500));
	this->addChild(_restartbtn, OTHER_ZORDER::E_UPLAYER);
}

/**
 * @brief EndScene 업데이트 부분 이미지 움직임 담당
 * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
 **/
void EndScene::SceneUpdate(float dt)
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
}