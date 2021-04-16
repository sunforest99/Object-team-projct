#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "stdafx.h"

class Monster : public Unit
{
private:
    // ĳ���� �̹���
    Sprite* _monster;
    Size    _parent;

    Sprite* _lwing;
    Sprite* _rwing;

    Sprite* _leye;
    Sprite* _reye;

    Sprite* _leyebrow;
    Sprite* _reyebrow;
public:
    Monster();  

    /**
   * @brief player �ʱ�ȭ
   */
    void InitObject() override;

    /**
    * @brief player ������Ʈ
    */
    void Update() override;

    /**
    * @brief player ������Ʈ
    * @param float posX ���ö���Ʈ posX ������ ��
    */
    void SpriteSetPotionX(const float posX) { _monster->setPositionX(posX); }

    /**
    * @brief _monster �������̵� �ּ� �� ����
    */
    Sprite* GetSprite() const override { return _monster; }
};

#endif //_MONSTER_H_