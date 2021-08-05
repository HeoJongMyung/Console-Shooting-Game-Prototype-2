#include "Include.h"


Effect::Effect()
{
	x = 0;
	y = 0;
	live = false;
	index = 0;

	fColor = WHITE;
	bColor = BLACK;
	Time = 0;
}

Effect::~Effect()
{
}

void Effect::DrawE()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Effect[i].live)
		{
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y - 1, effect[g_Effect[i].index][0][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y - 1, effect[g_Effect[i].index][0][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y - 1, effect[g_Effect[i].index][0][2], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y, effect[g_Effect[i].index][1][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y, effect[g_Effect[i].index][1][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y, effect[g_Effect[i].index][1][2], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y + 1, effect[g_Effect[i].index][2][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y + 1, effect[g_Effect[i].index][2][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y + 1, effect[g_Effect[i].index][2][2], g_Effect[i].fColor, g_Effect[i].bColor);
		}
	}
}

void Effect::Update()
{
	Clipping();
}

void Effect::Move(int x, int y)
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Effect[i].live == false)
		{
			g_Effect[i].x = x;
			g_Effect[i].y = y;
			g_Effect[i].index = 0;
			g_Effect[i].Time = GetTickCount() + 500;
			g_Effect[i].live = true;
			break;
		}
	}
}

void Effect::Clipping()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Effect[i].live)
		{
			if (g_Effect[i].Time < GetTickCount64())
			{
				g_Effect[i].index++;
				g_Effect[i].Time = GetTickCount64() + 300;
			}
			if (g_Effect[i].index > 2)
			{
				g_Effect[i].live = false;
			}
		}
	}
}
