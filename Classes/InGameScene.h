#ifndef _INGAME_SCENE_H_
#define _INGAME_SCENE_H_

#include "stdafx.h"

class InGameScene : public Layer
{
private:
    // 배경 이미지
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
    * @brief object 초기화
    */
    void InitObj();

    /**
    * @brief InGameScene 업데이트
    */
    void SceneUpdate(float dt);
    void MonsterUpdate(float dt);
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
