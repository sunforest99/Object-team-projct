#ifndef _BULLET_H_
#define _BULLET_H_

#include "stdafx.h"

class Bullet : public Unit
{
private:
	// �Ѿ� �̹���
	Sprite* _bullet;

	int damage;

public:

	/**
	* @brief Bullet �ʱ�ȭ
	*/
	void InitObject() override;

	/**
	* @brief Bullet ������Ʈ
	*/
	void Update() override;

	/**
	* @brief _bullet ��������Ʈ �ּ� �� ����
	*/
	Sprite* GetSprite() const override { return _bullet; }

	/**
	* @brief _bullet ������ �� ����
	*/
	int GetDamage() const { return damage; }
};

#endif
