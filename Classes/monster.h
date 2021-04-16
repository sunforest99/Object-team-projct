#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "stdafx.h"

class Monster : public Unit
{
private:
    // 캐릭터 이미지
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
   * @brief player 초기화
   */
    void InitObject() override;

    /**
    * @brief player 업데이트
    */
    void Update() override;

    /**
    * @brief player 업데이트
    * @param float posX 스플라이트 posX 설정할 값
    */
    void SpriteSetPotionX(const float posX) { _monster->setPositionX(posX); }

    /**
    * @brief _monster 스프라이드 주소 값 리턴
    */
    Sprite* GetSprite() const override { return _monster; }
};

#endif //_MONSTER_H_