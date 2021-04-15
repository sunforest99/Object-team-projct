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

	// --- ³¯°³
	_lwing = Sprite::createWithSpriteFrameName("dragon_01_wing.png");
	_rwing = Sprite::createWithSpriteFrameName("dragon_01_wing.png");

	_parent = _monster->getContentSize();

	_lwing->setPosition(Vec2(_parent.width / 2 - 43.f, _parent.height / 2));
	_rwing->setPosition(Vec2(_parent.width / 2 + 43.f, _parent.height / 2));

	_rwing->setFlipX(true);

	auto rwingreduce = ScaleTo::create(0.5f, 0.9f);
	auto rwingincrease = ScaleTo::create(0.5f, 1.2f);
	auto rseq = Sequence::create(rwingreduce, rwingincrease, nullptr);

	auto lwingreduce = ScaleTo::create(0.5f, 0.9f);
	auto lwingincrease = ScaleTo::create(0.5f, 1.2f);
	auto lseq = Sequence::create(lwingreduce, lwingincrease, nullptr);

	RepeatForever* ractionrepeat = RepeatForever::create(rseq);
	RepeatForever* lactionrepeat = RepeatForever::create(lseq);

	_rwing->runAction(ractionrepeat);
	_lwing->runAction(lactionrepeat);

	_monster->addChild(_lwing, SET_Z_ORDER::E_WINGS);
	_monster->addChild(_rwing, SET_Z_ORDER::E_WINGS);

	// ---- ´«
	_leye = Sprite::createWithSpriteFrameName("dragon_eye.png");
	_reye = Sprite::createWithSpriteFrameName("dragon_eye.png");

	_reye->setFlipX(true);
	_parent = _monster->getContentSize();

	_leye->setPosition(Vec2(_parent.width / 2 - 15.f, _parent.height / 2));
	_reye->setPosition(Vec2(_parent.width / 2 + 15.f, _parent.height / 2));

	_monster->addChild(_leye, SET_Z_ORDER::E_MONSTER_EYE);
	_monster->addChild(_reye, SET_Z_ORDER::E_MONSTER_EYE);

	// ---- ´«¾Ë
	_leyebrow = Sprite::createWithSpriteFrameName("dragon_01_eyebrow.png");
	_reyebrow = Sprite::createWithSpriteFrameName("dragon_01_eyebrow.png");

	_reyebrow->setFlipX(true);
	_parent = _monster->getContentSize();

	_leyebrow->setPosition(Vec2(_parent.width / 2 - 15.f, _parent.height / 2));
	_reyebrow->setPosition(Vec2(_parent.width / 2 + 15.f, _parent.height / 2));

	_monster->addChild(_leyebrow, SET_Z_ORDER::E_MONSTER_EYE);
	_monster->addChild(_reyebrow, SET_Z_ORDER::E_MONSTER_EYE);

	this->addChild(_monster);
}

void Monster::Update()
{
	_monster->setPositionY(_monster->getPositionY() - 10.f);
}