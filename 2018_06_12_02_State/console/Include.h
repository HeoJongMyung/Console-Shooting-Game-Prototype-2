#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#define BMax 30
#define BLength 3

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "Define.h"
#include "mmsystem.h"
//------------------------------------
#include "State.h"
#include "StateCtrl.h"


#include "LogoState.h"
#include "MenuState.h"
#include "GameState.h"
#include "EndGame.h"

#include "Extern.h"

#include "Unit.h"
#include "hero.h"
#include "bullet.h"
#include "Monster.h"
#include "effect.h"
#include "boss.h"

extern Hero g_Hero;
extern Monster g_Monster[BMax];
extern Bullet g_Bullet[BMax];
extern CGameState gameState;

extern Effect g_Effect[BMax];
extern char effect[BLength][BLength][BLength];

extern Boss g_Boss;

#endif