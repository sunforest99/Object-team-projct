#ifndef _ENDSCENE_H_
#define _ENDSCENE_H_

#include "stdafx.h"

class EndScene : public Layer
{
private:
    Size _visibleSize;
    // ��� �̹���
    Sprite* _bg1;
    Sprite* _bg2;

    Sprite* _layer;

    unsigned int _hightscore;
    unsigned int _score;

    // Game over�۾�
    Label* _gameoverlabel;

    // ���ھ� ���� �۾�
    Label* _scoreUi;
    Label* _hightscoreUi;

    // ����(����)
    Label* _scorelabel;
    Label* _hightscorelabel;

    // ����� ��ư
    ui::Button* _restartbtn;

public:
    /**
    * @brief EndScene ����
    */
    static Scene* createScene();

    /**
    * @brief Layer �ʱ�ȭ
    */
    virtual bool init();

    /**
    * @brief Ui �ʱ�ȭ
    */
    void InitUi();

    /**
    * @brief InGameScene ������Ʈ
    */
    void SceneUpdate(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(EndScene);
};

#endif //_ENDSCENE_H_
