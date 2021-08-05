#include "Include.h"

Hero::Hero()
{
	x = 60;
	y = 15;
	attack = 5;
	live = true;
	hp = 100;
}

Hero::~Hero()
{
}

void Hero::Update()
{
	Move();
	Clipping();
	if (hp == 0)
	{
		// 게임 종료
	}
}

void Hero::Move()
{
	if (IsKey(VK_UP))
	{
		y -= speed;
	}
	if (IsKey(VK_DOWN))
	{
		y += speed;
	}
	if (IsKey(VK_LEFT))
	{
		x -= speed;
	}
	if (IsKey(VK_RIGHT))
	{
		x += speed;
	}
	if (IsKey(VK_SPACE))
	{
		g_Bullet->Move1(g_Hero.x, g_Hero.y);
	}

	if (IsKey(VK_Z))
	{
		g_Bullet->Move2(g_Hero.x, g_Hero.y);
	}
}

void Hero::Clipping()
{

	if (x < 1)
	{
		x = 1;
	}

	if (x > 118)
	{
		x = 118;
	}

	if (y < 3)
	{
		y = 3;
	}

	if (y > 28)
	{
		y = 28;
	}
}

