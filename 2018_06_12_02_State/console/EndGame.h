#pragma once

class CEndGame : public CState
{
public:
	CEndGame();
	~CEndGame();
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
};