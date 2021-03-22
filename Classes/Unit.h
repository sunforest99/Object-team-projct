#ifndef _UNIT_H_
#define _UNIT_H_

#include "stdafx.h"

/// <summary>
/// ��� ������ �ʿ��� �Լ�, ������ ���� Ŭ������ ���鶧 ����ϸ� ��.
/// </summary>

class Unit : public Node
{
protected:
	int _damage;
	int _hp;
	Vec2 _pos;

public:
	/**
	* @brief �� class �ʱ�ȭ
	*/
	virtual void Init() = 0;

	/**
	* @brief �� class ������Ʈ
	*/
	virtual void Update() = 0;

	/**
	* @brief ������ ������ ��������
	*/
	int GetUnitDamage() const { return _damage; }
	/**
	* @brief ������ hp ��������
	*/
	int GetUnithp() const { return _hp; }
};

#endif // !_UNIT_H_
