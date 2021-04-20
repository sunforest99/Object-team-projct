#include "stdafx.h"

/**
 * @brief StartScene 생성
 */
Scene* LobbyScene::createScene()
{
	auto scene = Scene::create();

	auto layer = LobbyScene::create();

	scene->addChild(layer);

	return scene;
}

LobbyScene::~LobbyScene()
{
	_player->release();
}

/**
 * @brief Layer 초기화
 */
bool LobbyScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------LobbyScene Log Start-----------");
	_visibleSize = Director::getInstance()->getVisibleSize();

	_money = UserDefault::getInstance()->getIntegerForKey("money");

	srand(time(NULL));
	_bgindex = rand() % 3;

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

	_layer = Sprite::create("layer.png");
	_layer->setScale(100.f);
	_layer->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2));
	_layer->setOpacity(200);
	this->addChild(_layer, OTHER_ZORDER::E_LAYER);

	UiInit();
	objectInit();

	this->schedule(schedule_selector(LobbyScene::SceneUpdate), 0.0f);

	return true;
}

/**
 * @brief ui 초기화
 * @param Size winsize 창의 크기 받음
 */
void LobbyScene::UiInit()
{
	_playerlabel = Label::createWithTTF("Player", "fonts/Marker Felt.ttf", 70);
	_playerlabel->setPosition(Vec2(_visibleSize.width / 2 - 250.f, _visibleSize.height / 2 + 300.f));
	this->addChild(_playerlabel, OTHER_ZORDER::E_LABEL);

	_bulletlabel = Label::createWithTTF("Bullet", "fonts/Marker Felt.ttf", 70);
	_bulletlabel->setPosition(Vec2(_visibleSize.width / 2 + 250.f, _visibleSize.height / 2 + 300.f));
	this->addChild(_bulletlabel, OTHER_ZORDER::E_LABEL);

	// ---- 게임 시작 버튼
	_startbtn = ui::Button::create("ui/btn_restart_n.png","ui/btn_restart_c.png");
	_startbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(InGameScene::createScene());
			break;
		default:
			break;
		}
		});
	_startbtn->setTitleText("Game Start");
	_startbtn->setTitleFontSize(50.f);
	_startbtn->setScale(0.8f);
	_startbtn->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 - 500));
	this->addChild(_startbtn, OTHER_ZORDER::E_UPLAYER);

	// ----  총알 업그래이드 버튼
	_upgradebtn = ui::Button::create("ui/btn_restart_n.png", "ui/btn_restart_c.png");
	_upgradebtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (_money > 0)
			{
				_money -= 10;
				UserDefault::getInstance()->setIntegerForKey("money", _money);
				_coinlabel->setString(StringUtils::format("%lu", _money));
				log("upgrade - money : %lu", _money);
			}
			break;
		default:
			break;
		}
		});
	_upgradebtn->setTitleText("Bullet Upgrade");
	_upgradebtn->setTitleFontSize(50.f);
	_upgradebtn->setScale(0.8f);
	_upgradebtn->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 - 350));
	this->addChild(_upgradebtn, OTHER_ZORDER::E_UPLAYER);

	_coinlabel = Label::create(StringUtils::format("%lu",_money) , "fonts/Marker Felt.ttf", 70);
	_coinlabel->setAnchorPoint(Vec2(0.f,0.5f));
	_coinlabel->setPosition(Vec2(100.f, _visibleSize.height - 80.f));
	this->addChild(_coinlabel, OTHER_ZORDER::E_LABEL);

	_coin = Sprite::create("item_coin.png");
	_coin->setPosition(Vec2(64, _visibleSize.height - 80.f));
	this->addChild(_coin, OTHER_ZORDER::E_UPLAYER);
}


/**
 * @brief object 초기화
 * @param Size winsize 창의 크기 받음
 */
void LobbyScene::objectInit()
{
	_player = new Player();
	_player->InitObject();
	_player->GetSprite()->setPosition(Vec2(_visibleSize.width / 2 - 250.f, _visibleSize.height / 2 + 150.f));
	this->addChild(_player, OTHER_ZORDER::E_UPLAYER);
}

/**
 * @brief StartScene 업데이트 부분 이미지 움직임 담당
 * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
 */
void LobbyScene::SceneUpdate(float dt)
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