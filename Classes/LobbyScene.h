#ifndef _LOBBYSCENE_H_
#define _LOBBYSCENE_H_

#include "stdafx.h"

class LobbyScene : public Layer
{
private:
    Size _visibleSize;

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
    Sprite* _coin;

    Label* _coinlabel;
    ui::Button* _startbtn;
    ui::Button* _upgradebtn;

    char* _moneystring;
    unsigned int _money;
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
     */
    void UiInit();

    /**
     * @brief object 초기화
     */
    void objectInit();

    /**
     * @brief InGameScene 업데이트
     * @param int dt 델타 타임 (업데이트 할때 걸려야할 시간)
     */
    void SceneUpdate(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(LobbyScene);
};

#endif //_LOBBYSCENE_H_
