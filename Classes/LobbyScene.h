#ifndef _LOBBYSCENE_H_
#define _LOBBYSCENE_H_

#include "stdafx.h"

class LobbyScene : public Layer
{
private:
    // 배경 이미지 이름
    std::string _bgname[4] = { "background/01.png", "background/02.png", "background/03.png", "background/04.png" };
    int _bgindex;

    Player* _player;

    // 배경 이미지
    Sprite* _bg1;
    Sprite* _bg2;

    Sprite* _layer;

    // UI
    Label* _playerlabel;
    Label* _bulletlabel;

    ui::Button* _startbtn;
    ui::Button* _upgradebtn;
public:
    ~LobbyScene();
    /**
     * @brief StartScene 생성
     */
    static Scene* createScene();

    /**
     * @brief Layer 초기화
     */
    virtual bool init();

    /**
     * @brief ui 초기화
     * @param Size winsize 창의 크기 받음
     */
    void UiInit(Size winsize);

    /**
     * @brief object 초기화
     * @param Size winsize 창의 크기 받음
     */
    void objectInit(Size winsize);

    /**
     * @brief InGameScene 업데이트
     * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
     */
    void SceneUpdate(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(LobbyScene);
};

#endif //_LOBBYSCENE_H_
