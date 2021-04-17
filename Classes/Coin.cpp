#include "stdafx.h"

void Coin::InitObject()
{
	_coin = Sprite::create("item_coin.png");
	this->addChild(_coin);
}

void Coin::Update()
{
	//메테오가 떨어지는 속도
	_coin->setPositionY(_coin->getPositionY() - 15.f);
}
