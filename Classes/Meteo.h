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
   * @brief player �ʱ�ȭ
   */
    void Init() override;

    /**
    * @brief player ������Ʈ
    */
    void Update() override;

    /*@brief player ������Ʈ
        * @param float posX ��������Ʈ posX ������ ��
     */
    void SpriteSetPotionX(const float posX) { _meteo->setPositionX(posX); }
    /**
    * @brief _monster ��������Ʈ �ּ� �� ����
    */
    Sprite* GetSprite() const override { return _meteo; }

};

#endif