#include "include.h";


Boss::Boss()
{
	g_Boss.x = 60;
	g_Boss.y = 6;
	g_Boss.speed = 1;
	g_Boss.body = 'B';
	g_Boss.hp = 100;
	g_Boss.attack = 10;
	g_Boss.live = false;
	g_Boss.Time = 0;

	g_Boss.fColor = WHITE;
	g_Boss.bColor = BLACK;
}

Boss::~Boss()
{

}

void Boss::Update()
{
	Move();
	BossMonster();
}

void Boss::Move()
{
	//int ranx = rand() % 120;
	//int rany = rand() % 15;

	if (hp <= 100 && 50 < hp)
	{
		g_Boss.x = 60;//ranx;
		g_Boss.y = 10;//rany;
		MonsterSpawn();
	}

	if (hp <= 50)
	{
		fColor = RED;

		g_Boss.x = 60;//ranx;
		g_Boss.y = 10;//rany;
		MonsterSpawn2();
	}
}

void Boss::Clipping()
{

	if (g_Boss.x < 1)
	{
		g_Boss.x = 1;
	}

	if (g_Boss.x > 118)
	{
		g_Boss.x = 118;
	}

	if (g_Boss.y < 3)
	{
		g_Boss.y = 3;
	}



	if (g_Boss.y > 15)
	{
		g_Boss.y = 15;
	}
}

void Boss::BDraw()
{
		DrawCharEx3(g_Boss.x, g_Boss.y, g_Boss.body, g_Boss.fColor, g_Boss.bColor);	
}

void Boss::Bosslive()
{
	if (gameState.nscore == 100)
	{
		g_Boss.live = true;
	}

	if (g_Boss.hp == 0)
	{
		g_Boss.live = false;
	}
}

void Boss::BossMonster()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Monster[i].y += g_Monster[i].speed;

		if (g_Monster[i].live == true && g_Monster[i].y > 28)
		{
			g_Monster[i].live = false;
		}
	}
}

void Boss::MonsterSpawn()
{
	int random = rand() % 120;

	if (Time < GetTickCount())
	{
		for (int i = 0; i < BMax; i++)
		{
			if (!g_Monster[i].live)
			{
				g_Monster[i].x = g_Boss.x;
				g_Monster[i].y = g_Boss.y;
				Time = GetTickCount() + 1000;
				g_Monster[i].live = true;
				break;
			}
		}
	}
}

void Boss::MonsterSpawn2()
{
	int random = rand() % 120;

	if (Time < GetTickCount())
	{
		for (int i = 0; i < BMax; i++)
		{
			if (!g_Monster[i].live)
			{
				g_Monster[i].x = g_Boss.x;
				g_Monster[i].y = g_Boss.y;
				Time = GetTickCount() + 300;
				g_Monster[i].live = true;
				break;
			}
		}
	}
}
