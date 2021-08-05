#include "include.h"

Monster::Monster()
{
	x = 0;
	y = 0;
	speed = 1;
	body = 'T';
	hp = 0;
	attack = 10;
	live = false;
	Time = 0;

	fColor = YELLOW;
	bColor = BLACK;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	Move();
	Clipping();
}

void Monster::Move()
{	
		for(int i = 0; i < BMax; i++)
		{
			g_Monster[i].y += g_Monster[i].speed;

			if (g_Monster[i].live == true && g_Monster[i].y > 28)
			{

				g_Monster[i].live = false;
			}
		}
}

void Monster::Clipping()
{
	int random = rand() % 120;

	if (Time < GetTickCount())
	{	
		for (int i = 0; i < BMax; i++)
		{
			if (!g_Monster[i].live)
			{
				g_Monster[i].x = random;
				g_Monster[i].y = 3;
				Time = GetTickCount() + 300;
				g_Monster[i].live = true;
				break;
			}
		}
	}
}



