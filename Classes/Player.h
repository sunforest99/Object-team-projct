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
    void SetPos(const Vec2 pos) { _player->setPositionX(pos.x); }

    /**
    * @brief postionX 더하기
    * @param float posX posX 더할 값
    */
    void AddPosX(const float posX) { _player->setPositionX(_player->getPosition().x + posX); }
    /**
    * @brief postionX 빼기
    * @param float posX posX 뺄 값
    */
    void MinPosX(const float posX) { _player->setPositionX(_player->getPosition().x - posX); }
    
    /**
    * @brief player hp 깎기
    * @param int dmg 대미지 값
    */
    void ReduceHp(const int dmg) { _hp -= dmg; }

    /**
    * @brief sprite 주소값 가져오기
    */
    Sprite* GetSprite() const override  { return _player; }
};

#endif //_PLAYER_H_
