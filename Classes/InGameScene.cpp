#include "stdafx.h"

/**
* @brief InGameScene 생성
*/
Scene* InGameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = InGameScene::create();

	scene->addChild(layer);

	return scene;
}

InGameScene::InGameScene()
{
	_rkeycheck = false;
	_lkeycheck = false;
	_addmoney = 0;
	_score = 0;
}
InGameScene::~InGameScene()
{
	_player->release();
}

/**
* @brief Layer 초기화
*/
bool InGameScene::init()
{
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------InGameScene Log Start-----------");
	_visibleSize = Director::getInstance()->getVisibleSize();

	_money = UserDefault::getInstance()->getIntegerForKey("money");

	InitUi();
	InitBG();
	InitPlayer();

	// 배경음악 시끄러워서 주석처리
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/dragon_flight.mp3", true);

	this->schedule(schedule_selector(InGameScene::SceneUpdate), 0.0f);
	this->schedule(schedule_selector(InGameScene::MonsterUpdate), 3.0f);
	this->schedule(schedule_selector(InGameScene::MeteoUpdate), 2.0f);
	this->schedule(schedule_selector(InGameScene::BulletUpdate), 0.05f);

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

/**
* @brief 배경 초기화
*/
void InGameScene::InitBG()
{
	_bg1 = Sprite::create("background/01.png");
	_bg1->setAnchorPoint(Vec2::ZERO);
	_bg1->setScale(D_BASE_SACLE);
	_bg1->setPosition(Vec2::ZERO);
	this->addChild(_bg1, INGAME_ZORDER::E_BACKGROUND);

	_bg2 = Sprite::create("background/01.png");
	_bg2->setAnchorPoint(Vec2::ZERO);
	_bg2->setScale(D_BASE_SACLE);
	_bg2->setPosition(Vec2(0.f, D_DESIGN_HEIGHT));
	this->addChild(_bg2, INGAME_ZORDER::E_BACKGROUND);
}

/**
* @brief Player 초기화
*/
void InGameScene::InitPlayer()
{
	// 플레이어 객체 생성 및 초기화
	_player = new Player();
	_player->InitObject();
	this->addChild(_player, INGAME_ZORDER::E_PLAYER);
}

/**
* @brief Ui 초기화
*/
void InGameScene::InitUi()
{
	_coinui = Sprite::create("item_coin.png");
	_coinui->setPosition(Vec2(42.f, _visibleSize.height - 50.f));
	this->addChild(_coinui, INGAME_ZORDER::E_UI);

	_coinlabel = Label::create(StringUtils::format("%lu", _addmoney), "fonts/Marker Felt.ttf", 50.f);
	_coinlabel->setAnchorPoint(Vec2(0.f, 0.5f));
	_coinlabel->setPosition(Vec2(78.f, _visibleSize.height - 50.f));
	this->addChild(_coinlabel, INGAME_ZORDER::E_UI);

	_scorelabel = Label::create(StringUtils::format("%lu M", _score), "fonts/Marker Felt.ttf", 50.f);
	_scorelabel->setAnchorPoint(Vec2(1.f, 0.5f));
	_scorelabel->setColor(Color3B(203, 230, 238));
	_scorelabel->setPosition(Vec2(_visibleSize.width - 50.f, _visibleSize.height - 50.f));
	this->addChild(_scorelabel, INGAME_ZORDER::E_UI);
}

/**
  * @brief Bullet 업데이트
  * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
  */
void InGameScene::BulletUpdate(float dt)
{
	if (_player->GetUnithp() > 0)
	{
		_bullet = new Bullet();
		_bullet->InitObject();
		_bullet->GetSprite()->setPosition(_player->GetSprite()->getPosition());
		this->addChild(_bullet, INGAME_ZORDER::E_BULLET);
		v_bullet.push_back(_bullet);
		_bullet->release();
	}
}

/**
* @brief Monster 업데이트
* @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
*/
void InGameScene::MonsterUpdate(float dt)
{
	for (int i = 0; i < 5; i++)
	{
		_monster = new Monster();
		_monster->InitObject();
		_monster->SpriteSetPotionX(128.f + 224.f * i);
		this->addChild(_monster, INGAME_ZORDER::E_MONSTER);
		v_monster.push_back(_monster);
		_monster->release();
	}
}

/**
* @brief Meteo 업데이트
* @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
*/
void InGameScene::MeteoUpdate(float dt)
{
	_meteo = new Meteo();
	_meteo->InitObject();
	this->addChild(_meteo, INGAME_ZORDER::E_METEO);
	v_meteo.push_back(_meteo);
	_meteo->release();
	SimpleAudioEngine::getInstance()->playEffect("sound/meteor.wav");
}

/**
* @brief InGameScene 업데이트 부분 이미지 움직임 담당
* @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
**/
void InGameScene::SceneUpdate(float dt)
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

	_score += 1;
	_scorelabel->setString(StringUtils::format("%lu M", _score));

	if (_rkeycheck == true && _player->GetSprite()->getPositionX() < D_DESIGN_WIDTH - _player->GetSprite()->getContentSize().width && _player->GetUnithp() > 0)
		_player->AddPosX(10.f);
	else if (_lkeycheck == true && _player->GetSprite()->getContentSize().width < _player->GetSprite()->getPositionX() && _player->GetUnithp() > 0)
		_player->MinPosX(10.f);

	if (_player->GetUnithp() > 0)
	{
		_player->Update();
		// 총알 업데이트
		for (auto it = v_bullet.begin(); it != v_bullet.end();)
		{
			(*it)->Update();

			if ((*it)->GetSprite()->getPositionY() > D_DESIGN_HEIGHT)
			{
				this->removeChild((*it));
				it = v_bullet.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	else
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/ch_die.wav");
		UserDefault::getInstance()->setIntegerForKey("score", _score);
		Director::getInstance()->replaceScene(EndScene::createScene());
	}

	// 몬스터 업데이트 및 충돌
	for (auto it = v_monster.begin(); it != v_monster.end();)
	{
		(*it)->Update();

		for (auto it2 = v_bullet.begin(); it2 != v_bullet.end();)
		{
			if ((*it2)->GetSprite()->getBoundingBox().intersectsRect((*it)->GetSprite()->getBoundingBox()))
			{
				// TODO 충돌 되었을때 처리
				(*it)->ReduceHp((*it2)->GetDamage());
				this->removeChild((*it2));
				it2 = v_bullet.erase(it2);
			}
			else
			{
				++it2;
			}
		}

		if ((*it)->GetUnithp() > 0)
		{
			if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
			{
				// TODO 충돌 되었을때 처리
				_player->ReduceHp(1);
				
				this->removeChild((*it));
				it = v_monster.erase(it);
			}
			else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT)
			{
				this->removeChild((*it));
				it = v_monster.erase(it);
			}
			else
			{
				++it;
			}
		}
		else
		{
			SimpleAudioEngine::getInstance()->playEffect("sound/mon_die.wav");
			_coin = new Coin();
			_coin->InitObject();
			_coin->GetSprite()->setPosition(Vec2((*it)->GetSprite()->getPositionX(), (*it)->GetSprite()->getPositionY() + 70.f));
			this->addChild(_coin, E_COIN);
			v_coin.push_back(_coin);
			_coin->release();

			this->removeChild((*it));
			it = v_monster.erase(it);
		}
	}

	// 메테오 업데이트 및 충돌
	for (auto it = v_meteo.begin(); it != v_meteo.end();)
	{
		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
		{
			// TODO 충돌 되었을때 처리
			_player->ReduceHp(1);
			this->removeChild((*it));
			it = v_meteo.erase(it);
		}
		else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT)
		{
			this->removeChild((*it));
			it = v_meteo.erase(it);
		}
		else
		{
			++it;
		}
	}

	// 코인, 플레이어 충돌
	for (auto it = v_coin.begin(); it != v_coin.end();)
	{
		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
		{
			// TODO 충돌 되었을때 처리
			_addmoney += D_ADDMONEY;
			_coinlabel->setString(StringUtils::format("%lu", _addmoney));
			UserDefault::getInstance()->setIntegerForKey("addmoney", _addmoney);
			SimpleAudioEngine::getInstance()->playEffect("sound/get_coin.wav");
			this->removeChild((*it));
			it = v_coin.erase(it);
		}
		else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT)
		{
			this->removeChild((*it));
			it = v_coin.erase(it);
		}
		else
		{
			++it;
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
	if (_player->GetUnithp() > 0)
		_player->SetPos(touch->getLocation());

	return true;
}

/**
* @brief 터치 되었을때 (마우스 드래그)
*/
void InGameScene::onTouchMoved(Touch* touch, Event* unused_event)
{
	if (_player->GetSprite()->getContentSize().width < touch->getLocation().x && touch->getLocation().x < D_DESIGN_WIDTH - _player->GetSprite()->getContentSize().width && _player->GetUnithp() > 0)
	{
		_player->SetPos(touch->getLocation());
	}
}

/**
* @brief 키보드 입력 이벤트 발생시 호출되는 callback 함수
* @param KeyCode keyCode 입력된 키 코드
* @param Event* event 이벤트 종류
**/
void InGameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		_rkeycheck = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		_lkeycheck = true;
}

void InGameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		_rkeycheck = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		_lkeycheck = false;
}
