#ifndef _METEO_H_
#define _METEO_H_

#include "stdafx.h"

class Meteo : public Unit
{
private:
	// 메테오 이미지
	Sprite* _meteo;

	int _rand;

public:

	/**
    * @brief Meteo 초기화
    */
	void InitObject() override;

	/**
	* @brief Meteo 업데이트
	*/
	void Update() override;

	/**
	* @brief _meteo 스프라이트 주소 값 리턴
	*/
	Sprite* GetSprite() const override { return _meteo; }
};

#endif
