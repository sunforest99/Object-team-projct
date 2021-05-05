#ifndef _USER_INCLUDE_H
#define _USER_INCLUDE_H

// cocos 부분
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
// using namsepace cocos2d;
USING_NS_CC;
// usning namespace audio engie
using namespace CocosDenshion;

// 게임 만들때 필요한 도구들
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>

// include 부분 순서 조심
#include "AppDelegate.h"
#include "Unit.h"
#include "monster.h"
#include "Coin.h"
#include "Meteo.h"
#include "Player.h"
#include "Bullet.h"

// Scene 여기아래로 class include 하면 안됨
#include "StartScene.h"
#include "LobbyScene.h"
#include "InGameScene.h"
#include "EndScene.h"
#include "HelloWorldScene.h"

#endif // !_USER_INCLUDE_H
