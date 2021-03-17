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
	// 오류나면 안됨!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------StartScene Log Start-----------");

	auto visibleSize = Director::getInstance()->getVisibleSize();
	log("visibleSize: %d", visibleSize);

	Label* label = Label::createWithTTF("Touch to Start", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	Sprite* sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(sprite, 0);

	// 터치 이벤트를 ONE_BY_ONE 형식으로 받겠다
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

bool StartScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// Scene 전환
	Director::getInstance()->replaceScene(HelloWorld::createScene());

	return true;
}