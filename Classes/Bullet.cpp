#include "stdafx.h"

void Bullet::InitObject()
{
	auto bulletsprite = SpriteFrameCache::getInstance();
	bulletsprite->addSpriteFramesWithFile("player.plist");

	_bullet = Sprite::createWithSpriteFrameName("bullet_01_01.png");
	_bullet->setPosition(Vec2(D_DESIGN_WIDTH/2, D_DESIGN_HEIGHT / 2));

	damage = 10;

	//°´Ã¼ Ãß°¡
	this->addChild(_bullet, INGAME_ZORDER::E_METEO);
}

void Bullet::Update()
{
	_bullet->setPositionY(_bullet->getPositionY() + D_BULLET_SPEED);
}
