#include "stdafx.h"

void Meteo::InitObject()
{
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
