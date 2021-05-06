#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // ȭ�� ������
    Size _visibleSize;

    // ��� �̹���
    Sprite* _bg1;
    Sprite* _bg2;

    // Objects
    Player* _player;
    Monster* _monster;
    Meteo* _meteo;
    Bullet* _bullet;
    Coin* _coin;

    std::vector<Monster*> v_monster;
    std::vector<Meteo*> v_meteo;
    std::vector<Coin*> v_coin;
    std::vector<Bullet*> v_bullet;
    
    // Ű�Է�
    bool _rkeycheck;
    bool _lkeycheck;

    // ��(����)
    unsigned int _addmoney;
    unsigned int _money;

    // ���� (����)
    unsigned int _score;

    // UI
    Sprite* _coinui;

    Label* _coinlabel;
    Label* _scorelabel;

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
    * @brief Ui �ʱ�ȭ
    */
    void InitUi();

    /**
    * @brief InGameScene ������Ʈ
    * @param float dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
    */
    void SceneUpdate(float dt);
    /**
    * @brief Monster ������Ʈ
    * @param float dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
    */
    void MonsterUpdate(float dt);
    /**
    * @brief Meteo ������Ʈ
    * @param float dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
    */
    void MeteoUpdate(float dt);

    /**
    * @brief Bullet ������Ʈ
    * @param float dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
    */
    void BulletUpdate(float dt);

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
