#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
private:
    // 배경 이미지
    Sprite* bg1;
    Sprite* bg2;

    // 로고 이미지
    Sprite* logo;

    // 캐릭터 이미지
    Sprite* character;

    // touch to start 글씨
    Label* label;

public:
    static Scene* createScene();

    // 초기화 해주는부분
    virtual bool init();

    // 업데이트 부분
    void SceneUpdate(float dt);

    // 터치 되었을때 ( 마우스 눌렀을때)
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
