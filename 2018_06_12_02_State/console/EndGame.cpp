#include "Include.h"



	CEndGame::CEndGame()
	{

	}

	CEndGame::~CEndGame()
	{

	}

	void CEndGame::Start()
	{

	}

	void CEndGame::Update()
	{			
			stateCtrl.StateChange(E_End);
	}

	void CEndGame::Draw()
	{
		sprintf(gameState.score, "Score : %d", gameState.nscore);
		DrawStrEx3(58, 17, gameState.score, LIGHTRED, BLACK);

		DrawStrEx3(60, 15, "Game End", WHITE, BLACK);
	}

	void CEndGame::Exit()
	{

	}
