#pragma once

class Monster : public Unit
{
public:
	Monster();
	~Monster();

	virtual void Update();
	virtual void Move();
	virtual void Clipping();
private:

};
