#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // 화면 사이즈
    Size _visibleSize;

    // 배경 이미지
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
    
    // 키입력
    bool _rkeycheck;
    bool _lkeycheck;

    // 돈(코인)
    unsigned int _addmoney;
    unsigned int _money;

    // 점수 (미터)
    unsigned int _score;

    // UI
    Sprite* _coinui;

    Label* _coinlabel;
    Label* _scorelabel;

public:
    InGameScene();
    ~InGameScene();

    /**
    * @brief InGameScene 생성
    */
    static Scene* createScene();

    /**
    * @brief Layer 초기화
    */
    virtual bool init();

    /**
    * @brief 배경 초기화
    */
    void InitBG();
    /**
    * @brief Player 초기화
    */
    void InitPlayer();
    /**
    * @brief Ui 초기화
    */
    void InitUi();

    /**
    * @brief InGameScene 업데이트
    * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void SceneUpdate(float dt);
    /**
    * @brief Monster 업데이트
    * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void MonsterUpdate(float dt);
    /**
    * @brief Meteo 업데이트
    * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void MeteoUpdate(float dt);

    /**
    * @brief Bullet 업데이트
    * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void BulletUpdate(float dt);

    /**
    * @brief 터치 되었을때 (마우스 눌렀을때)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);
    /**
    * @brief 터치 되었을때 (마우스 드래그)
    */
    virtual void onTouchMoved(Touch* touch, Event* unused_event);

    /**
    * @brief 키보드 입력 이벤트 발생시 호출되는 callback 함수
    * @param KeyCode keyCode 입력된 키 코드
    * @param Event* event 이벤트 종류
    **/
    virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(InGameScene);
};

#endif //_INGAME_SCENE_H_
