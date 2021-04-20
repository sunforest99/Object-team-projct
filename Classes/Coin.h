#ifndef _COIN_H_
#define _COIN_H_

#include "stdafx.h"

class Coin : public Unit
{
private:
	// ���׿� �̹���
	Sprite* _coin;

public:

	/**
    * @brief Coin �ʱ�ȭ
    */
	void InitObject() override;

	/**
	* @brief Coin ������Ʈ
	*/
	void Update() override;

	/**
	* @brief _coin ��������Ʈ �ּ� �� ����
	*/
	Sprite* GetSprite() const override { return _coin; }
};

#endif
