#ifndef _COIN_H_
#define _COIN_H_

#include "stdafx.h"

class Coin : public Unit
{
private:
	// 메테오 이미지
	Sprite* _coin;

public:

	/**
    * @brief Coin 초기화
    */
	void InitObject() override;

	/**
	* @brief Coin 업데이트
	*/
	void Update() override;

	/**
	* @brief _coin 스프라이트 주소 값 리턴
	*/
	Sprite* GetSprite() const override { return _coin; }
};

#endif
