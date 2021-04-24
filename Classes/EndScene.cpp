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

	_money = UserDefault::getInstance()->getIntegerForKey("money");
	_addmoney = UserDefault::getInstance()->getIntegerForKey("addmoney");
	UserDefault::getInstance()->setIntegerForKey("money", _money + _addmoney);

	log("%lu", _addmoney);
	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("ui/ui.plist");

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

	_layer = Sprite::createWithSpriteFrameName("layer.png");
	_layer->setScale(100.f);
	_layer->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f));
	_layer->setOpacity(200);
	this->addChild(_layer, OTHER_ZORDER::E_LAYER);

	InitUi();

	this->schedule(schedule_selector(EndScene::SceneUpdate), 0.0f);
	_addmoney >= 1000 ? _delay = 0.001f : _delay = 0.01f;
	this->schedule(schedule_selector(EndScene::Addmoney), _delay, _addmoney, _delay);

	return true;
}

/**
* @brief Ui 초기화
*/
void EndScene::InitUi()
{
	_gameoverlabel = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 70.f);
	_gameoverlabel->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f + 550.f));
	this->addChild(_gameoverlabel, OTHER_ZORDER::E_LABEL);

	_hightscoreUi = Label::createWithTTF("Hight Score", "fonts/Marker Felt.ttf", 70.f);
	_hightscoreUi->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f + 250.f));
	this->addChild(_hightscoreUi, OTHER_ZORDER::E_LABEL);

	_hightscorelabel = Label::createWithTTF(StringUtils::format("%lu", _hightscore), "fonts/Marker Felt.ttf", 70.f);
	_hightscorelabel->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f + 150.f));
	this->addChild(_hightscorelabel, OTHER_ZORDER::E_LABEL);

	_scoreUi = Label::createWithTTF("Score", "fonts/Marker Felt.ttf", 70.f);
	_scoreUi->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f));
	this->addChild(_scoreUi, OTHER_ZORDER::E_LABEL);

	_scorelabel = Label::createWithTTF(StringUtils::format("%lu", _score), "fonts/Marker Felt.ttf", 70.f);
	_scorelabel->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f - 100.f));
	this->addChild(_scorelabel, OTHER_ZORDER::E_LABEL);

	_restartbtn = ui::Button::create("btn_restart_n.png", "btn_restart_c.png", ui::Widget::TextureResType::PLIST);
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
	_restartbtn->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f - 500.f));
	this->addChild(_restartbtn, OTHER_ZORDER::E_UPLAYER);

	_coin = Sprite::create("item_coin.png");
	_coin->setPosition(Vec2(_visibleSize.width / 2.f - 100.f, _visibleSize.height / 2.f - 250.f));
	this->addChild(_coin, OTHER_ZORDER::E_UPLAYER);

	_coinlable = Label::createWithTTF(StringUtils::format("%lu", _money), "fonts/Marker Felt.ttf", 70.f);
	_coinlable->setPosition(Vec2(_visibleSize.width / 2.f, _visibleSize.height / 2.f - 250.f));
	this->addChild(_coinlable, OTHER_ZORDER::E_LABEL);
}

/**
 * @brief EndScene 업데이트 부분 이미지 움직임 담당
 * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
 **/
void EndScene::SceneUpdate(float dt)
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
}


/**
* @brief 돈올라가는 애니메이션
* @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
*/

void EndScene::Addmoney(float dt)
{
	_coinlable->setString(StringUtils::format("%lu", _money));
	_money ++;
}