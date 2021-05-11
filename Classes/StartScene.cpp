#include "stdafx.h"

/**
* @brief StartScene ����
*/
Scene* StartScene::createScene()
{
	auto scene = Scene::create();

	auto layer = StartScene::create();

	scene->addChild(layer);

	return scene;
}

/**
* @brief Layer �ʱ�ȭ
*/
bool StartScene::init()
{
	// �������� �ȵ�!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------StartScene Log Start-----------");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("ui/ui.plist");

	// �׽�Ʈ��
	UserDefault::getInstance()->setIntegerForKey("money", 1000);
	UserDefault::getInstance()->setIntegerForKey("addmoney", 0);
	// ������� �ò������� �ּ�ó��
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

	// ��ġ �̺�Ʈ�� ONE_BY_ONE �������� �ްڴ�
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	// Ű���� �̺�Ʈ ������ ����
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(StartScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/**
 * @brief StartScene ������Ʈ �κ� �̹��� ������ ���
 * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
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
 * @brief ���콺 Ŭ�� �Ǵ� ��ġ ������ ȣ��Ǵ� callback �Լ�
 * @param Touch* touch ��ġ�� ���� ����
 * @param  Event* unused_event �̺�Ʈ ����
 **/
bool StartScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// Scene ��ȯ
	Director::getInstance()->replaceScene(LobbyScene::createScene());
	return true;
}

/**
* @brief Ű���� �Է� �̺�Ʈ �߻��� ȣ��Ǵ� callback �Լ�
* @param KeyCode keyCode �Էµ� Ű �ڵ�
* @param Event* event �̺�Ʈ ����
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
