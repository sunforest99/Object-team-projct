#ifndef _USER_INCLUDE_H
#define _USER_INCLUDE_H

// cocos 부분
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
// using namsepace cocos2d;
USING_NS_CC;

// 게임 만들때 필요한 도구들
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>

// include 부분 순서 조심
#include "AppDelegate.h"
#include "Unit.h"
#include "Player.h"


// Scene 여기아래로 class include 하면 안됨
#include "InGameScene.h"
#include "StartScene.h"
#include "HelloWorldScene.h"

#endif // !_USER_INCLUDE_H