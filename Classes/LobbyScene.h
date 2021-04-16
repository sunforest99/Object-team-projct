#ifndef _LOBBYSCENE_H_
#define _LOBBYSCENE_H_

#include "stdafx.h"

class LobbyScene : public Layer
{
private:
    // ��� �̹��� �̸�
    std::string _bgname[4] = { "background/01.png", "background/02.png", "background/03.png", "background/04.png" };
    int _bgindex;

    Player* _player;

    // ��� �̹���
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
     * @brief StartScene ����
     */
    static Scene* createScene();

    /**
     * @brief Layer �ʱ�ȭ
     */
    virtual bool init();

    /**
     * @brief ui �ʱ�ȭ
     * @param Size winsize â�� ũ�� ����
     */
    void UiInit(Size winsize);

    /**
     * @brief object �ʱ�ȭ
     * @param Size winsize â�� ũ�� ����
     */
    void objectInit(Size winsize);

    /**
     * @brief InGameScene ������Ʈ
     * @param int dt ��Ÿ Ÿ�� (������Ʈ �Ҷ� �ɷ����� �ð�)
     */
    void SceneUpdate(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(LobbyScene);
};

#endif //_LOBBYSCENE_H_
