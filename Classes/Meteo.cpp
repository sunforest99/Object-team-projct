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
	_meteo->setPosition(Vec2(visibleSize.width / 2, D_DESIGN_HEIGHT));
	//��ü �߰�
	this->addChild(_meteo);
}

void Meteo::Update()
{
	//���׿� ��ġ�� 0���Ϸ� �������� �ʱ�ȭ
	srand(time(NULL));
	if (_meteo->getPositionY() < 0)
	{
		_meteo->setPositionY(D_DESIGN_HEIGHT);
		_meteo->setPositionX(rand() % RAND_MAX);
	}
	//���׿��� �������� �ӵ�
	_meteo->setPositionY(_meteo->getPositionY() - 10.f);
}