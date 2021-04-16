#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // 배경 이미지
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
    * @brief InGameScene 업데이트
    * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void SceneUpdate(float dt);
    /**
    * @brief Monster 업데이트
    */
    void MonsterUpdate(float dt);
    /**
    * @brief Meteo 업데이트
    */
    void MeteoUpdate(float dt);

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
