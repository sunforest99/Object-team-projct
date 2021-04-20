#include "stdafx.h"

void Coin::InitObject()
{
	_coin = Sprite::create("item_coin.png");
	this->addChild(_coin);
}

void Coin::Update()
{
	_coin->setPositionY(_coin->getPositionY() - 15.f);
}
