#include "Include.h"

// 헝가리안 표기법
// int    n이름
// char   c이름
// bool   b이름	
// DWORD  dw이름
// short  s이름
// long   l이름
// 구조체 맴버변수는 
// int m_n이름
// char  m_c이름
// 글로벌 g_?이름
// int nVlaue = 0;
// void Quit();

CStateCtrl stateCtrl;

CLogoState logoState;
CMenuState menuState;
CGameState gameState;
CEndGame endgameState;

Effect g_Effect[BMax];

char effect[BLength][BLength][BLength] =
{
	{' ',' ',' '
	,' ','*',' '
	,' ',' ',' '},

	{' ','*',' '
	,'*',' ','*'
	,' ','*',' '},

	{'*',' ','*'
	,' ',' ',' '
	,'*',' ','*'}
};

//int nScore;
//char Score[32];

int main()
{
	InitialConsole();//초기화함수
	SetWindowTitle("Shooting");

	// new : 공간 할당
	// int* val = new int[10]; ===== int val[10]  // val에 기본 값으로 0이 들어간다.
	// delete val //delete를 써서 돌려줘야 한다.

	stateCtrl.StateAdd(E_LOGO, &logoState);
	stateCtrl.StateAdd(E_MENU, &menuState);
	stateCtrl.StateAdd(E_GAME, &gameState);
	stateCtrl.StateAdd(E_End, &endgameState);

	stateCtrl.StateChange(E_LOGO);

	while (true)
	{
		CheckInput();
		ClearScreenEx3(BLACK);
	
		stateCtrl.Update();
		stateCtrl.Draw();
		
		Flip();
		EngineSync(30);
	}

	ReleaseConsole();
	return 0;
}
