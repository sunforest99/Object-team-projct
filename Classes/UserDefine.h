#ifndef _USER_DEFINE_H
#define _USER_DEFINE_H

// 화면 해상도
#define D_DESIGN_WIDTH	1152 // 768 1.5배 
#define D_DESIGN_HEIGHT	1536 // 1024 1.5배
#define D_BASE_SACLE	1.5f

#define D_WINDOWS_SHOW 0.5

// title 이름
#define D_GAME_NAME "Team Project"

// background scroll
#define D_BACKGROUND_SPEED 8.f

// player setting height
#define D_PLAYER_HEIGHT 350.f

#define D_RAND_MAX 960

#define D_ADDMONEY 10

enum INGAME_ZORDER
{
	E_WINGS = -1,
	E_BACKGROUND,
	E_PLAYER,
	E_METEO = 1,
	E_MONSTER,
	E_MONSTER_EYE,
	E_COIN,
	E_UI
};

enum OTHER_ZORDER
{
	E_BACKBROUND = 0,
	E_STARTSCENE_CHAR = 0,
	E_LAYER,
	E_UPLAYER,
	E_LABEL,
	E_LOGO,
};

#endif // !_USER_DEFINE_H