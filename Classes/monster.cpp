#include "stdafx.h"

Monster::Monster()
{
	_hp = 1;
	_pos = Vec2::ZERO;
}

void Monster::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	_monster = Sprite::create("player/monster.png");
	_monster->setScale(0.5f);
	_monster->setPosition(Vec2(visibleSize.width / 2, D_DESIGN_HEIGHT));
	this->addChild(_monster);
}

void Monster::Update()
{
	_pos = _monster->getPosition();

	if (_hp == 1)
	{
		if (_monster->getPositionY() < 0)
		{
			_monster->setPositionY(D_DESIGN_HEIGHT);
		}
		_monster->setPositionY(_monster->getPositionY() - 8.f);
	}
	else if (_hp == 0)
	{
		_monster->setPositionY(D_DESIGN_HEIGHT);
	}
}