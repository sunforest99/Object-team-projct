#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#define RAND_MAX 960

void Meteo::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//���׿� ��������Ʈ ����
	_meteo = Sprite::create("meteo.png");
	//��������Ʈ ��ġ ����
	srand(time(NULL));
	_meteo->setPosition(Vec2(rand() % RAND_MAX, D_DESIGN_HEIGHT));
	//��ü �߰�
	this->addChild(_meteo);
}

void Meteo::Update()
{
	//���׿��� �������� �ӵ�
	_meteo->setPositionY(_meteo->getPositionY() - 10.f);
}