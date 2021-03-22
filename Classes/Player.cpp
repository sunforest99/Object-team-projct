#include "stdafx.h"

Player::Player()
{
	_hp = 1;
	_pos = Vec2::ZERO;
}

void Player::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	_player = Sprite::create("player/player.png");
	_player->setScale(0.5f);
	_player->setPosition(Vec2(visibleSize.width /2 , D_PLAYER_HEIGHT));
	this->addChild(_player);
}

void Player::Update()
{
	_pos = _player->getPosition();
}
