#pragma once

class Bullet : public Unit
{
public:
	Bullet();
	~Bullet();

	virtual void Update();

	virtual void Move1(int x, int y);
	void Move2(int x, int y);
	//void Move3(int x, int y);
	//void Move4(int x, int y);

	virtual void Clipping();

private:

};