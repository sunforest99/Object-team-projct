#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // ��� �̹���
    Sprite* _bg1;
    Sprite* _bg2;

    // Player
    Player* _player;
    Monster* _monster;
    Meteo* _meteo;

    std::vector<Monster*> v_monster;
    std::vector<Meteo*> v_meteo;

    bool _rkeycheck;
    bool _lkeycheck;

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
    * @brief Player �ʱ�ȭ
    */
    void InitPlayer();

    /**
    * @brief InGameScene ������Ʈ
    * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
    */
    void SceneUpdate(float dt);
    /**
    * @brief Monster ������Ʈ
    */
    void MonsterUpdate(float dt);
    /**
    * @brief Meteo ������Ʈ
    */
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
