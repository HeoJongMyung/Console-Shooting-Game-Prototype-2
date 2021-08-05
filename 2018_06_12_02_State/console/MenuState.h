class CMenuState : public CState
{
public:
	CMenuState();
	~CMenuState();
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
};