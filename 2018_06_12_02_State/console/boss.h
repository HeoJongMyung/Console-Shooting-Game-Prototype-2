#pragma once

class Boss : public Unit
{
public:
	Boss();
	~Boss();

	virtual void Update();

	virtual void Move();

	virtual void Clipping();

	void BDraw();

	void Bosslive();

	void BossMonster();

	void MonsterSpawn();

	void MonsterSpawn2();

private:

};