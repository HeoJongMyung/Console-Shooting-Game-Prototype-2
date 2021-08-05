#include "include.h"


Bullet::Bullet()
{
	x = 0;
	y = 0;
	speed = 1;
	body = 'l';
	hp = 0;
	attack = 10;
	live = false;
	Time = GetTickCount();

	fColor = WHITE;
	bColor = BLACK;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Bullet[i].y -= g_Bullet[i].speed;
	}
	Clipping();
}

void Bullet::Move1(int x, int y)
{
	if (Time < GetTickCount())
	{
		for (int i = 0; i < BMax; i++) 
		{
			if (!g_Bullet[i].live)
			{
				g_Bullet[i].x = x;
				g_Bullet[i].y = y;
				Time = GetTickCount() + 300;
				g_Bullet[i].live = true;
				if (IsKey(VK_Z))
				{
					return Move2(g_Hero.x, g_Hero.y);
				}		
				break;
			}	
		}
	}
}


void Bullet::Move2(int x, int y)
{
	if (Time < GetTickCount())
	{
		for (int i = 0; i < BMax; i++)
		{
			if (!g_Bullet[i].live)
			{
				g_Bullet[i].x = x;
				g_Bullet[i].y = y;
				Time = GetTickCount() + 10;
				g_Bullet[i].live = true;
				
				//if (IsKey(VK_SPACE))//Time == GetTickCount() + 1000)
				//{
				//	break;
				//}

				if (IsKey(VK_SPACE))
				{
					return Move1(g_Hero.x, g_Hero.y);
				}
				break;
			}
		}
	}
	//return Move1(g_Hero.x, g_Hero.y);
}



void Bullet::Clipping()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Bullet[i].y < 3 && g_Bullet[i].live == true)
		{
			g_Bullet[i].live = false;
		}
	}
}