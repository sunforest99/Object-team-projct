#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "stdafx.h"

class Monster : public Unit
{
private:
    // ĳ���� �̹���
    Sprite* _monster;
public:
    Monster();  
    void Init() override;
    
    void Update() override;    
};

#endif //_MONSTER_H_