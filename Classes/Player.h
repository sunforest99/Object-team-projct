#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "stdafx.h"

class Player : public Unit
{
private:
    // ĳ���� �̹���
    Sprite* _player;

public:
    /**
    * @brief player hp, pos �ʱ�ȭ
    */
    Player();

    /**
    * @brief player �ʱ�ȭ
    */
    void Init() override;
    /**
    * @brief player ������Ʈ
    */
    void Update() override;

    /**
    * @brief postion �����ϱ�
    * @param Vec2 pos ������ pos ��
    */
    void SetPos(const Vec2 pos) { _player->setPositionX(pos.x); }

    /**
    * @brief postionX ���ϱ�
    * @param float posX posX ���� ��
    */
    void AddPosX(const float posX) { _player->setPositionX(_player->getPosition().x + posX); }
    /**
    * @brief postionX ����
    * @param float posX posX �� ��
    */
    void MinPosX(const float posX) { _player->setPositionX(_player->getPosition().x - posX); }
    
    /**
    * @brief player hp ���
    * @param int dmg ����� ��
    */
    void ReduceHp(const int dmg) { _hp -= dmg; }

    /**
    * @brief sprite �ּҰ� ��������
    */
    Sprite* GetSprite() const override  { return _player; }
};

#endif //_PLAYER_H_
