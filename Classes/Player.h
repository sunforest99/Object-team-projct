#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "stdafx.h"

class Player : public Unit
{
private:
    // 캐릭터 이미지
    Sprite* _player;

public:
    /**
    * @brief player hp, pos 초기화
    */
    Player();

    /**
    * @brief player 초기화
    */
    void Init() override;
    /**
    * @brief player 업데이트
    */
    void Update() override;

    /**
    * @brief postion 설정하기
    * @param Vec2 pos 설정할 pos 값
    */
    void SetPos(Vec2 pos) const { _player->setPositionX(pos.x); }

    void AddPosX(float posX) const { _player->setPositionX(_player->getPosition().x + posX); }
    void MinPosX(float posX) const { _player->setPositionX(_player->getPosition().x - posX); }

    /**
    * @brief postion 가져오기
    */
    Vec2 GetPos() const { return _pos; }

    /**
    * @brief player hp 깎기
    * @param int dmg 대미지 값
    */
    void ReduceHp(const int dmg) { _hp += dmg; }
};

#endif //_PLAYER_H_
