#include "stdafx.h"

Player::Player()
{
	_hp = 1;
}

void Player::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("player.plist");

	_player = Sprite::createWithSpriteFrameName("pink_body.png");
	_player->setScale(2.f);
	_player->setPosition(Vec2(visibleSize.width /2 , D_PLAYER_HEIGHT));
	this->addChild(_player);
	
	_lwing = Sprite::createWithSpriteFrameName("pink_wing.png");
	_rwing = Sprite::createWithSpriteFrameName("pink_wing.png");
	
	_parent = _player->getContentSize();

	_lwing->setPosition(Vec2(_parent.width / 2 - 40.f, _parent.height / 2));
	_rwing->setPosition(Vec2(_parent.width / 2 + 40.f, _parent.height / 2));
	_rwing->setFlipX(true);
	_player->addChild(_lwing, SET_Z_ORDER::E_WINGS);
	_player->addChild(_rwing, SET_Z_ORDER::E_WINGS);
}

void Player::Update()
{
}
