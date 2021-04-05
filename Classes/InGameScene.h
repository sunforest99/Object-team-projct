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
    Monster* monster;
    Meteo* meteo;

    std::vector<Monster*> v_monster;
    std::vector<Meteo*> v_meteo;

    bool rkeycheck;
    bool lkeycheck;

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
    void MonsterUpdate(float dt);
    void MeteoUpdate(float dt);

    /**
    * @brief ��ġ �Ǿ����� (���콺 ��������)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);
    /**
    * @brief ��ġ �Ǿ����� (���콺 �巡��)
    */
    virtual void onTouchMoved(Touch* touch, Event* unused_event);

    /**
    * @brief Ű���� �Է� �̺�Ʈ �߻��� ȣ��Ǵ� callback �Լ�
    * @param KeyCode keyCode �Էµ� Ű �ڵ�
    * @param Event* event �̺�Ʈ ����
    **/
    virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(InGameScene);
};

#endif //_INGAME_SCENE_H_
