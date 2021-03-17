#ifndef _UNIT_H_
#define _UNIT_H_

#include "stdafx.h"

/// <summary>
/// 모든 유닛이 필요한 함수, 변수들 유닛 클래스를 만들때 상속하면 됨.
/// </summary>

class Unit : public Node
{
public:
	Vec2 _pos;
	int _damage;
	int _hp;

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;

	virtual Vec2 GetUnitpos() const { return _pos; }
	virtual int GetUnitDamage() const { return _damage; }
	virtual int GetUnithp() const { return _hp; }
};

#endif // !_UNIT_H_
