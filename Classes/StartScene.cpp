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
	// �������� �ȵ�!!
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
 * @brief ���콺 Ŭ�� �Ǵ� ��ġ ������ ȣ��Ǵ� callback �Լ�
 * @param Touch* touch ��ġ�� ���� ����
 * @param  Event* unused_event �̺�Ʈ ����
 **/
bool StartScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// Scene ��ȯ
	Director::getInstance()->replaceScene(InGameScene::createScene());
	return true;
}