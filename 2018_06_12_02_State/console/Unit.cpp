#include "include.h"

Unit::Unit()
{
	x = 0;
	y = 0;
	speed = 1;
	body = 'A';
	hp = 0;
	attack = 0;
	live = false;
	Time = 0;

	fColor = WHITE;
	bColor = BLACK;
}

Unit::~Unit()
{
}

void Unit::Draw()
{
	if (live)
	{
		DrawCharEx3(x, y, body, fColor, bColor);
	}
}

void Unit::Move()
{
}




