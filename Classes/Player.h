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
    void SetPos(Vec2 pos) const { _player->setPosition(Vec2(pos.x, D_PLAYER_HEIGHT)); }

    /**
    * @brief postion ��������
    */
    Vec2 GetPos() const { return _pos; }

    /**
    * @brief player hp ���
    * @param int dmg ����� ��
    */
    void ReduceHp(const int dmg) { _hp += dmg; }
};

#endif //_PLAYER_H_
