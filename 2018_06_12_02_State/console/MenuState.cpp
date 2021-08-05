#include "Include.h"
CMenuState::CMenuState()
{

}
CMenuState::~CMenuState()
{

}
void CMenuState::Draw()
{
	DrawStrEx3(0, 0, "Menu State", WHITE, BLACK);
}
void CMenuState::Exit()
{

}
void CMenuState::Start()
{

}
void CMenuState::Update()
{
	if(IsKey(VK_F3))
	{
		stateCtrl.StateChange(E_GAME);
	}

}