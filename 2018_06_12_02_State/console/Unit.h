#pragma once

class Unit
{
public:
	Unit();
	~Unit();

	int x;
	int y;
	int speed;
	char body;
	int hp;
	int attack;
	bool live;

	DWORD fColor;
	DWORD bColor;
	DWORD Time;

	virtual void Update() = 0;

	virtual void Draw();

	virtual void Move();

	virtual void Clipping() = 0;

private:

};