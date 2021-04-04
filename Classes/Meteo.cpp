#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#define RAND_MAX 960

void Meteo::Init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//메테오 스프라이트 생성
	_meteo = Sprite::create("meteo.png");	
	//스프라이트 위치 지정
	_meteo->setPosition(Vec2(visibleSize.width / 2, D_DESIGN_HEIGHT));
	//객체 추가
	this->addChild(_meteo);
}

void Meteo::Update()
{
	//메테오 위치가 0이하로 떨어지면 초기화
	srand(time(NULL));
	if (_meteo->getPositionY() < 0)
	{
		_meteo->setPositionY(D_DESIGN_HEIGHT);
		_meteo->setPositionX(rand() % RAND_MAX);
	}
	//메테오가 떨어지는 속도
	_meteo->setPositionY(_meteo->getPositionY() - 10.f);
}