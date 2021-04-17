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
	
	// ������� �ò������� �ּ�ó��
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

	// ��ġ �̺�Ʈ�� ONE_BY_ONE �������� �ްڴ�
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

/**
 * @brief StartScene ������Ʈ �κ� �̹��� ������ ���
 * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
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
