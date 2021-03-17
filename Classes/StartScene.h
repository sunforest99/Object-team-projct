#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
private:
    // ��� �̹���
    Sprite* bg1;
    Sprite* bg2;

    // �ΰ� �̹���
    Sprite* logo;

    // ĳ���� �̹���
    Sprite* character;

    // touch to start �۾�
    Label* label;

public:
    static Scene* createScene();

    // �ʱ�ȭ ���ִºκ�
    virtual bool init();

    // ������Ʈ �κ�
    void SceneUpdate(float dt);

    // ��ġ �Ǿ����� ( ���콺 ��������)
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
