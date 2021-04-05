#include "stdafx.h"

Monster::Monster()
{
	_hp = 1;
}

void Monster::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	_monster = Sprite::create("monster.png");
	//_monster->setScale(0.5f);		// 추후 변경
	_monster->setPositionY(D_DESIGN_HEIGHT);
	this->addChild(_monster);
}

void Monster::Update()
{
	_monster->setPositionY(_monster->getPositionY() - 10.f);
}