#include "Include.h"


Hero g_Hero;
Monster g_Monster[BMax];
Bullet g_Bullet[BMax];
Boss g_Boss;

CGameState::CGameState()
{

}
CGameState::~CGameState()
{

}

void CGameState::Draw()
{
	DrawStrEx3(0, 0, "Game State", WHITE, BLACK);


	for (int i = 0; i < BMax; i++)
	{
		g_Monster[i].Draw();
		g_Bullet[i].Draw();
		g_Effect[i].DrawE();
	}

	g_Hero.Draw();
	g_Boss.live = false;

	if (nscore >= 100 && nBosshp > 0)
	{
		g_Boss.live = true;
		if (nBosshp <= 0)
		{
			g_Boss.live = false;
		}

		if (g_Boss.live)
		{
			g_Boss.BDraw();
		}
		
	}
}
void CGameState::Update()
{
	nBosshp = g_Boss.hp;
	UI();
	//Score();

	if (IsKey(VK_F1))
	{
		stateCtrl.StateChange(E_LOGO);
	}

	for (int i = 0; i < BMax; i++)
	{
		g_Monster[i].Update();
		g_Bullet[i].Update();
		g_Effect[i].Update();
		break;
	}
	g_Hero.Update();

	g_Boss.live = false;
	if (nscore >= 100 && nBosshp >= 0)
	{
		g_Boss.live = true;
		if (nBosshp <= 0)
		{
			g_Boss.live = false;

		}
		if (g_Boss.live)
		{
			g_Boss.Update();
		}	
	}



	Bullet_MonsterCollision();
}
void CGameState::Exit()
{

}
void CGameState::Start()
{

}

void CGameState::Bullet_MonsterCollision()
{
	for (int i = 0; i < BMax; i++)
	{
		for (int j = 0; j < BMax; j++)
		{
			if (g_Bullet[i].live && g_Monster[j].live)
			{
				if (g_Bullet[i].x == g_Monster[j].x && g_Bullet[i].y < g_Monster[j].y)
				{
					g_Effect[i].Move(g_Bullet[i].x, g_Bullet[i].y);
					g_Bullet[i].live = false;
					g_Monster[j].live = false;
					nscore += 10;
				}
			}
		}
	}
}

void CGameState::UI()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 120; j++)
			if (nUI[i][j] == 1)
				DrawFillBoxEx3(j, i, 1, 1, YELLOW);

	nCount++;
	sprintf(count, "count : %d", nCount);
	DrawStrEx3(1, 1, count, LIGHTRED, BLACK);

	sprintf(count, "skill : Z", skill);
	DrawStrEx3(108, 28, count, LIGHTRED, BLACK);

	sprintf(score, "Score : %d", nscore);
	DrawStrEx3(15, 1, score, LIGHTRED, BLACK);

	Bullet_BossCollision();
	if (nscore >= 100 && nBosshp > 0)
	{
		sprintf(Bosshp, "Boss HP : %d", nBosshp);
		DrawStrEx3(45, 1, Bosshp, LIGHTRED, BLACK);
	}

	Hero_BossCollision();
	sprintf(Herohp, "Hero HP : %d", nHerohp);
	DrawStrEx3(30, 1, Herohp, LIGHTRED, BLACK);


	/*for (int i = 0; i < BMax; i++)
	{
		for (int j = 0; j < BMax; j++)
		{
			if (g_Bullet[i].live && g_Monster[j].live)
			{
				if (g_Bullet[i].x == g_Monster[j].x && g_Bullet[i].y < g_Monster[j].y)
				{
					nscore += 10;
					sprintf(score, "score : %d", nscore);
					DrawStrEx3(15, 1, score, LIGHTRED, BLACK);
				}
			}
		}
	}*/
}

void CGameState::Bullet_BossCollision()
{
	for (int i = 0; i < BMax; i++)
	{	
			if (g_Boss.live && g_Bullet[i].live )
			{
				if (g_Bullet[i].x == g_Boss.x && g_Bullet[i].y < g_Boss.y)
				{
					g_Effect[i].Move(g_Bullet[i].x, g_Bullet[i].y);
					g_Bullet[i].live = false;

					
				

					g_Boss.hp -= g_Hero.attack;

					if (nBosshp <= 0)
					{
						nscore += 100;
						g_Boss.live = false;
					}
				}
			}
	}
}

void CGameState::Hero_BossCollision()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Hero.live && g_Monster[i].live)
		{
			if (g_Monster[i].x == g_Hero.x && g_Monster[i].y >= g_Hero.y)
			{
				g_Effect[i].Move(g_Hero.x, g_Hero.y);
				g_Monster[i].live = false;



				nHerohp -= g_Monster[i].attack;

				if (nHerohp <= 0)
				{
					g_Hero.live = false;
					stateCtrl.StateChange(E_End);
				}
			}
		}
	}
}
