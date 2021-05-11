#include "stdafx.h"

void Bullet::InitObject()
{
	_bulletsprite = SpriteFrameCache::getInstance();
	_bulletsprite->addSpriteFramesWithFile("player.plist");

	_bulletlevel = UserDefault::getInstance()->getIntegerForKey("bulletlevel");

	_bullet = Sprite::createWithSpriteFrameName(StringUtils::format("bullet_01_0%d.png", _bulletlevel));
	_bullet->setPosition(Vec2(D_DESIGN_WIDTH/2, D_DESIGN_HEIGHT / 2));

	_damage = 1 * _bulletlevel;

	//°´Ã¼ Ãß°¡
	this->addChild(_bullet, INGAME_ZORDER::E_METEO);
}

void Bullet::Update()
{
	_bullet->setPositionY(_bullet->getPositionY() + D_BULLET_SPEED);
}