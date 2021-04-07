#include "stdafx.h"

Monster::Monster()
{
	_hp = 1;
}

void Monster::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("monster.plist");

	_monster = Sprite::createWithSpriteFrameName("dragon_01_body.png");
	_monster->setScale(1.5f);
	_monster->setPositionY(D_DESIGN_HEIGHT);


	_lwing = Sprite::createWithSpriteFrameName("dragon_01_wing.png");
	_rwing = Sprite::createWithSpriteFrameName("dragon_01_wing.png");

	_parent = _monster->getContentSize();

	_lwing->setPosition(Vec2(_parent.width / 2 - 40.f, _parent.height / 2));
	_rwing->setPosition(Vec2(_parent.width / 2 + 40.f, _parent.height / 2));

	_rwing->setFlipX(true);

	_monster->addChild(_lwing, SET_Z_ORDER::E_WINGS);
	_monster->addChild(_rwing, SET_Z_ORDER::E_WINGS);

	this->addChild(_monster);
}

void Monster::Update()
{
	_monster->setPositionY(_monster->getPositionY() - 10.f);
}