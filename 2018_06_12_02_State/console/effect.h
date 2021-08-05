#pragma once

class Effect : public  Unit
{
public:
	Effect();
	~Effect();
	int index;

	void DrawE();

	virtual void Update();
	virtual void Move(int x, int y);
	virtual void Clipping();

private:

};
