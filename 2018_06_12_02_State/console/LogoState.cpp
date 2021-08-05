#include "Include.h"
CLogoState::CLogoState()
{

}
CLogoState::~CLogoState()
{

}
void CLogoState::Draw()
{
	DrawStrEx3(0, 0, "Logo State", WHITE, BLACK);
}
void CLogoState::Update()
{
	if (IsKey(VK_F2))
	{
		stateCtrl.StateChange(E_MENU);
	}
}

void CLogoState::Exit()
{

}

void CLogoState::Start()
{

}