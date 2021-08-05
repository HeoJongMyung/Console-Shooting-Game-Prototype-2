#pragma once

class Hero : public Unit
{
public:
	Hero();
	~Hero();

	virtual void Update();

	virtual void Move();

	virtual void Clipping();
private:

};

