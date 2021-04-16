#ifndef _METEO_H_
#define _METEO_H_

#include "stdafx.h"

class Meteo : public Unit
{
private:
	// ���׿� �̹���
	Sprite* _meteo;

public:

	/**
    * @brief Meteo �ʱ�ȭ
    */
	void InitObject() override;

	/**
	* @brief Meteo ������Ʈ
	*/
	void Update() override;

	/*@brief Meteo ������Ʈ
	* @param float posX ��������Ʈ posX ������ ��
	 */
	void SpriteSetPotionX(const float posX) { _meteo->setPositionX(posX); }
	/**
	* @brief _monster ��������Ʈ �ּ� �� ����
	*/
	Sprite* GetSprite() const override { return _meteo; }
};

#endif