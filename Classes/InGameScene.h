#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // ��� �̹���
    Sprite* bg1;
    Sprite* bg2;

    // Player
    Player* player;

public:
    InGameScene();
    ~InGameScene();

    /**
    * @brief InGameScene ����
    */
    static Scene* createScene();

     /**
     * @brief Layer �ʱ�ȭ
     */
    virtual bool init();

    /**
    * @brief ��� �ʱ�ȭ
    */
    void InitBG();
    /**
    * @brief object �ʱ�ȭ
    */
    void InitObj();

    /**
    * @brief InGameScene ������Ʈ
    */
    void SceneUpdate(float dt);

    /**
    * @brief ��ġ �Ǿ����� (���콺 ��������)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);
    /**
    * @brief ��ġ �Ǿ����� (���콺 �巡��)
    */
    virtual void onTouchMoved(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(InGameScene);
};

#endif //_INGAME_SCENE_H_
