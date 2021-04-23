#ifndef _ENDSCENE_H_
#define _ENDSCENE_H_

#include "stdafx.h"

class EndScene : public Layer
{
private:
    Size _visibleSize;
    // 배경 이미지
    Sprite* _bg1;
    Sprite* _bg2;

    Sprite* _layer;

    unsigned int _hightscore;
    unsigned int _score;

    // Game over글씨
    Label* _gameoverlabel;

    // 스코어 관련 글씨
    Label* _scoreUi;
    Label* _hightscoreUi;

    // 점수(숫자)
    Label* _scorelabel;
    Label* _hightscorelabel;

    // 돈 올라가는 애니메이션 딜레이
    float _delay;

    unsigned int _addmoney;
    unsigned int _money;
    Sprite* _coin;

    Label* _coinlable;

    // 재시작 버튼
    ui::Button* _restartbtn;

public:
    /**
    * @brief EndScene 생성
    */
    static Scene* createScene();

    /**
    * @brief Layer 초기화
    */
    virtual bool init();

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
    * @brief 돈올라가는 애니메이션
    * @param float dt 델타 타임 (업데이트 할때 걸려야할 시간)
    */
    void Addmoney(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(EndScene);
};

#endif //_ENDSCENE_H_
