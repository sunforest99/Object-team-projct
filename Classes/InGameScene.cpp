#include "stdafx.h"

Scene* InGameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = InGameScene::create();

	scene->addChild(layer);

	return scene;
}

InGameScene::InGameScene()
{

}
InGameScene::~InGameScene()
{
	player->release();
}

bool InGameScene::init()
{
	// �������� �ȵ�!!
	if (!Layer::init())
	{
		return false;
	}

	log("-----------InGameScene Log Start-----------");
	
	InitBG();
	InitObj();

	this->schedule(schedule_selector(InGameScene::SceneUpdate), 0.0f);

	// ��ġ �̺�Ʈ�� ONE_BY_ONE �������� �ްڴ�
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

void InGameScene::InitBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	bg1 = Sprite::create("background/01.png");
	bg1->setAnchorPoint(Vec2::ZERO);
	bg1->setScale(D_BASE_SACLE);
	bg1->setPosition(Vec2::ZERO);
	this->addChild(bg1, 0);

	bg2 = Sprite::create("background/01.png");
	bg2->setAnchorPoint(Vec2::ZERO);
	bg2->setScale(D_BASE_SACLE);
	bg2->setPosition(Vec2(0, D_DESIGN_HEIGHT));
	this->addChild(bg2, 0);
}

void InGameScene::InitObj()
{
	// �÷��̾� ��ü ���� �� �ʱ�ȭ
	player = new Player();
	player->Init();
	this->addChild(player);

}

/**
 * @brief InGameScene ������Ʈ �κ� �̹��� ������ ���
 * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
 **/
void InGameScene::SceneUpdate(float dt)
{
	bg1->setPosition(Vec2(0, bg1->getPositionY() - D_BACKGROUND_SPEED));
	bg2->setPosition(Vec2(0, bg2->getPositionY() - D_BACKGROUND_SPEED));
	if (bg1->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		bg1->setPositionY(D_DESIGN_HEIGHT);
	}
	if (bg2->getPositionY() <= -D_DESIGN_HEIGHT)
	{
		bg2->setPositionY(D_DESIGN_HEIGHT);
	}

	// �÷��̾� ������Ʈ
	player->Update();
}

/**
 * @brief ���콺 Ŭ�� �Ǵ� ��ġ ������ ȣ��Ǵ� callback �Լ�
 * @param Touch* touch ��ġ�� ���� ����
 * @param  Event* unused_event �̺�Ʈ ����
 **/
bool InGameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	player->SetPos(touch->getLocation());

	log("%f %f", player->GetPos().x, player->GetPos().y);
	return true;
}

void InGameScene::onTouchMoved(Touch* touch, Event* unused_event)
{
	player->SetPos(touch->getLocation());
}