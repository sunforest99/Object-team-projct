#include "stdafx.h"

Monster::Monster()
{
	_hp = 1;
}

void Monster::InitObject()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("monster.plist");
	srand(time(NULL));
	_rand = rand() % 3 + 1;
	_hp = 10 * _rand;

	_monster = Sprite::createWithSpriteFrameName(StringUtils::format("dragon_%d_body.png", _rand));
	_monster->setScale(D_BASE_SACLE);
	_monster->setPositionY(D_DESIGN_HEIGHT);

	// --- ³¯°³

	_parent = _monster->getContentSize();

	_lwing = Sprite::createWithSpriteFrameName(StringUtils::format("dragon_%d_wing.png", _rand));
	_rwing = Sprite::createWithSpriteFrameName(StringUtils::format("dragon_%d_wing.png", _rand));

	_lwing->setPosition(Vec2(_parent.width / 2.f - 43.f, _parent.height / 2.f));
	_rwing->setPosition(Vec2(_parent.width / 2.f + 43.f, _parent.height / 2.f));

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

	_monster->addChild(_lwing, INGAME_ZORDER::E_WINGS);
	_monster->addChild(_rwing, INGAME_ZORDER::E_WINGS);

	// ---- ´«
	_leye = Sprite::createWithSpriteFrameName("dragon_eye.png");
	_reye = Sprite::createWithSpriteFrameName("dragon_eye.png");

	_reye->setFlipX(true);
	_parent = _monster->getContentSize();

	_leye->setPosition(Vec2(_parent.width / 2.f - 15.f, _parent.height / 2.f));
	_reye->setPosition(Vec2(_parent.width / 2.f + 15.f, _parent.height / 2.f));

	_monster->addChild(_leye, INGAME_ZORDER::E_MONSTER_EYE);
	_monster->addChild(_reye, INGAME_ZORDER::E_MONSTER_EYE);

	// ---- ´«¾Ë
	_parent = _monster->getContentSize();

	_leyebrow = Sprite::createWithSpriteFrameName(StringUtils::format("dragon_%d_eyebrow.png", _rand));
	_reyebrow = Sprite::createWithSpriteFrameName(StringUtils::format("dragon_%d_eyebrow.png", _rand));

	_reyebrow->setFlipX(true);

	_leyebrow->setPosition(Vec2(_parent.width / 2.f - 15.f, _parent.height / 2.f));
	_reyebrow->setPosition(Vec2(_parent.width / 2.f + 15.f, _parent.height / 2.f));

	_monster->addChild(_leyebrow, INGAME_ZORDER::E_MONSTER_EYE);
	_monster->addChild(_reyebrow, INGAME_ZORDER::E_MONSTER_EYE);

	this->addChild(_monster);
}

void Monster::Update()
{
	_monster->setPositionY(_monster->getPositionY() - 10.f);
}