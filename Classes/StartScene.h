#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
private:
    // ��� �̹��� �̸�
    std::string _bgname[4] = { "background/01.png", "background/02.png", "background/03.png", "background/04.png" };
    // ĳ���� �̹��� �̸�
    std::string _charname[4] = { "character_01.png", "character_02.png", "character_03.png", "character_04.png" };
    int _bgindex;
    int _charindex;

    // ��� �̹���
    Sprite* _bg1;
    Sprite* _bg2;

    // �ΰ� �̹���
    Sprite* _logo;

    // ĳ���� �̹���
    Sprite* _character;

    // touch to start �۾�
    Label* _label;

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

    /**
    * @brief Ű���� �Է� �̺�Ʈ �߻��� ȣ��Ǵ� callback �Լ�
    * @param KeyCode keyCode �Էµ� Ű �ڵ�
    * @param Event* event �̺�Ʈ ����
    **/
    virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
