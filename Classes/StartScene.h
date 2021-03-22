#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
private:
    // ��� �̹��� �̸�
    std::string _bgname[4] = { "background/01.png", "background/02.png", "background/03.png", "background / 04.png" };
    // ĳ���� �̹��� �̸�
    std::string _charname[4] = { "ui/character_01.png", "ui/character_02.png", "ui/character_03.png", "ui/character_04.png" };
    int bgindex;
    int charindex;

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
    /**
    * @brief StartScene ����
    */
    static Scene* createScene();

    /**
    * @brief Layer �ʱ�ȭ
    */
    virtual bool init();

    /**
    * @brief InGameScene ������Ʈ
    */
    void SceneUpdate(float dt);

    /**
    * @brief ��ġ �Ǿ����� (���콺 ��������)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
