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
    * @brief Meteo �ʱ�ȭ
    */
	void InitObject() override;

	/**
	* @brief Meteo ������Ʈ
	*/
	void Update() override;

	/**
	* @brief _monster ��������Ʈ �ּ� �� ����
	*/
	Sprite* GetSprite() const override { return _coin; }
};

#endif
