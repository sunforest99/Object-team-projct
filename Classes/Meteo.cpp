#include "stdafx.h"

void Meteo::InitObject()
{
	//메테오 스프라이트 생성
	_meteo = Sprite::create("meteo.png");
	//스프라이트 위치 지정
	srand(time(NULL));
	_meteo->setPosition(Vec2(rand() % RAND_MAX, D_DESIGN_HEIGHT));
	//객체 추가
	this->addChild(_meteo);
}

void Meteo::Update()
{
	//메테오가 떨어지는 속도
	_meteo->setPositionY(_meteo->getPositionY() - 10.f);
}
