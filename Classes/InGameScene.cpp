#include "stdafx.h"

/**
* @brief InGameScene ����
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
}
InGameScene::~InGameScene()
{
	_player->release();
}

/**
* @brief Layer �ʱ�ȭ
*/
bool InGameScene::init()
{
	// �������� �ȵ�!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------InGameScene Log Start-----------");

	_money = UserDefault::getInstance()->getIntegerForKey("money");
	log("money: %d", _money);
	InitBG();
	InitPlayer();

	// ������� �ò������� �ּ�ó��
	/*auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("bgm/dragon_flight.mp3", true);*/

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

/**
* @brief ��� �ʱ�ȭ
*/
void InGameScene::InitBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	_bg1 = Sprite::create("background/01.png");
	_bg1->setAnchorPoint(Vec2::ZERO);
	_bg1->setScale(D_BASE_SACLE);
	_bg1->setPosition(Vec2::ZERO);
	this->addChild(_bg1, INGAME_ZORDER::E_BACKGROUND);

	_bg2 = Sprite::create("background/01.png");
	_bg2->setAnchorPoint(Vec2::ZERO);
	_bg2->setScale(D_BASE_SACLE);
	_bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(_bg2, INGAME_ZORDER::E_BACKGROUND);
}

/**
* @brief Player �ʱ�ȭ
*/
void InGameScene::InitPlayer()
{
	// �÷��̾� ��ü ���� �� �ʱ�ȭ
	_player = new Player();
	_player->InitObject();
	this->addChild(_player, INGAME_ZORDER::E_PLAYER);
}
/**
* @brief Monster ������Ʈ
*/
void InGameScene::MonsterUpdate(float dt)
{
	for (int i = 0; i < 5; i++)
	{
		_monster = new Monster();
		_monster->InitObject();
		_monster->SpriteSetPotionX(128 + 224 * i);
		log("y: %f", _monster->GetSprite()->getPositionY());
		this->addChild(_monster, INGAME_ZORDER::E_MONSTER);
		v_monster.push_back(_monster);
		_monster->release();
	}
}

/**
* @brief Meteo ������Ʈ
*/
void InGameScene::MeteoUpdate(float dt)
{
	_meteo = new Meteo();
	_meteo->InitObject();
	this->addChild(_meteo, INGAME_ZORDER::E_METEO);
	v_meteo.push_back(_meteo);
	_meteo->release();
}

/**
* @brief InGameScene ������Ʈ �κ� �̹��� ������ ���
* @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
**/
void InGameScene::SceneUpdate(float dt)
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

	if (_rkeycheck == true && _player->GetSprite()->getPositionX() < D_DESIGN_WIDTH - 125 && _player->GetUnithp() > 0)
		_player->AddPosX(10.f);
	else if (_lkeycheck == true && 0 + 125 < _player->GetSprite()->getPositionX() && _player->GetUnithp() > 0)
		_player->MinPosX(10.f);

	_player->Update();
	// ���� ������Ʈ �� �浹
	for (auto it = v_monster.begin(); it != v_monster.end();)
	{
		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
		{
			// TODO �浹 �Ǿ����� ó��
			// player->ReduceHp(1);
            _coin = new Coin();
            _coin->InitObject();
            _coin->GetSprite()->setPosition(Vec2((*it)->GetSprite()->getPositionX(), (*it)->GetSprite()->getPositionY() + 70.f));
            this->addChild(_coin, 10);
            v_coin.push_back(_coin);
            _coin->release();
            
            this->removeChild((*it));
            it = v_monster.erase(it);
		}
		else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT * 2)
		{
			this->removeChild((*it));
			it = v_monster.erase(it);
		}
		else
		{
			++it;
		}
	}

	// ���׿� ������Ʈ �� �浹
	for (auto it = v_meteo.begin(); it != v_meteo.end();)
	{
		(*it)->Update();

		if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
		{
			// TODO �浹 �Ǿ����� ó��
			// player->ReduceHp(1);
			this->removeChild((*it));
			it = v_meteo.erase(it);
		}
		else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT * 2)
		{
			this->removeChild((*it));
			it = v_meteo.erase(it);
		}
		else
		{
			++it;
		}
	}
    
	// ����, �÷��̾� �浹
    for(auto it = v_coin.begin(); it!= v_coin.end();)
    {
        (*it)->Update();
        
        if ((*it)->GetSprite()->getBoundingBox().intersectsRect(_player->GetSprite()->getBoundingBox()))
        {
            // TODO �浹 �Ǿ����� ó��
			_money += 10;
			UserDefault::getInstance()->setIntegerForKey("money", _money);
            this->removeChild((*it));
            it = v_coin.erase(it);
        }
        else if ((*it)->GetSprite()->getPositionY() < -D_DESIGN_HEIGHT * 2)
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
* @brief ���콺 Ŭ�� �Ǵ� ��ġ ������ ȣ��Ǵ� callback �Լ�
* @param Touch* touch ��ġ�� ���� ����
* @param  Event* unused_event �̺�Ʈ ����
**/
bool InGameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	if (_player->GetUnithp() > 0)
		_player->SetPos(touch->getLocation());

	return true;
}

void InGameScene::onTouchMoved(Touch* touch, Event* unused_event)
{
	if (0 + 125 < touch->getLocation().x && touch->getLocation().x < D_DESIGN_WIDTH - 125 && _player->GetUnithp() > 0)
	{
		_player->SetPos(touch->getLocation());
	}
}

/**
* @brief Ű���� �Է� �̺�Ʈ �߻��� ȣ��Ǵ� callback �Լ�
* @param KeyCode keyCode �Էµ� Ű �ڵ�
* @param Event* event �̺�Ʈ ����
**/
void InGameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		_rkeycheck = true;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		_lkeycheck = true;

	// �׽�Ʈ��
	if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE)
		Director::getInstance()->replaceScene(LobbyScene::createScene());
}

void InGameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		_rkeycheck = false;
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		_lkeycheck = false;
}
