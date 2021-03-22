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

    /**
    * @brief 터치 되었을때 (마우스 눌렀을때)
    */
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);
    /**
    * @brief 터치 되었을때 (마우스 드래그)
    */
    virtual void onTouchMoved(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(InGameScene);
};

#endif //_INGAME_SCENE_H_
