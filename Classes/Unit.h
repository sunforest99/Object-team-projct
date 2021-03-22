#ifndef _UNIT_H_
#define _UNIT_H_

#include "stdafx.h"

/// <summary>
/// 모든 유닛이 필요한 함수, 변수들 유닛 클래스를 만들때 상속하면 됨.
/// </summary>

class Unit : public Node
{
protected:
	int _damage;
	int _hp;
	Vec2 _pos;

public:
	/**
	* @brief 각 class 초기화
	*/
	virtual void Init() = 0;

	/**
	* @brief 각 class 업데이트
	*/
	virtual void Update() = 0;

	/**
	* @brief 유닛의 데미지 가져오기
	*/
	int GetUnitDamage() const { return _damage; }
	/**
	* @brief 유닛의 hp 가져오기
	*/
	int GetUnithp() const { return _hp; }
};

#endif // !_UNIT_H_
