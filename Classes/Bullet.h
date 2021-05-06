#ifndef _BULLET_H_
#define _BULLET_H_

#include "stdafx.h"

class Bullet : public Unit
{
private:
	// 총알 이미지
	Sprite* _bullet;

	int damage;

public:

	/**
	* @brief Bullet 초기화
	*/
	void InitObject() override;

	/**
	* @brief Bullet 업데이트
	*/
	void Update() override;

	/**
	* @brief _bullet 스프라이트 주소 값 리턴
	*/
	Sprite* GetSprite() const override { return _bullet; }

	/**
	* @brief _bullet 데미지 값 리턴
	*/
	int GetDamage() const { return damage; }
};

#endif
