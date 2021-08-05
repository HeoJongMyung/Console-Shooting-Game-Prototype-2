#include "Include.h"

// �밡���� ǥ���
// int    n�̸�
// char   c�̸�
// bool   b�̸�	
// DWORD  dw�̸�
// short  s�̸�
// long   l�̸�
// ����ü �ɹ������� 
// int m_n�̸�
// char  m_c�̸�
// �۷ι� g_?�̸�
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
	InitialConsole();//�ʱ�ȭ�Լ�
	SetWindowTitle("Shooting");

	// new : ���� �Ҵ�
	// int* val = new int[10]; ===== int val[10]  // val�� �⺻ ������ 0�� ����.
	// delete val //delete�� �Ἥ ������� �Ѵ�.

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
