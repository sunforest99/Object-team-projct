#include "stdafx.h"

void Meteo::InitObject()
{
	//���׿� ��������Ʈ ����
	_meteo = Sprite::create("meteo.png");
	//��������Ʈ ��ġ ����
	srand(time(NULL));
	_rand = rand() % D_RAND_MAX + 1;
	_meteo->setPosition(Vec2(_rand * _meteo->getContentSize().width  * 0.5f, D_DESIGN_HEIGHT));
	//��ü �߰�
	this->addChild(_meteo, INGAME_ZORDER::E_METEO);
}

void Meteo::Update()
{
	//���׿��� �������� �ӵ�
	_meteo->setPositionY(_meteo->getPositionY() - D_METEO_SPEED);
}
