#ifndef _CENEMY_H_
#define _CENEMY_H_

#include <windows.h>
#include "CHp.h"
#include "CEnemy_Player.h"
#include "CCombo.h"
#include "CHit.h"
#include "CGameObject.h"

#define ENEMY_SIZE 25
#define LEFT 1
#define RIGHT 2
#define UPGRADE 0
#define NON_UPGRADE 1

//class CBulletMaker;
class CRenderer;
class CUpdater;
class CTransform;

class CEnemy : public CGameObject {
	int MoveMode;
	int Delay;

	int ComboDelay;
	BOOL BulletMode;

	//CBulletMaker *Bullet;
public:

	CTransform *transform;
	CRenderer* renderer;
	CUpdater* updater;

	CEnemy();
	virtual ~CEnemy();

	BOOL CheckHit(int,int,int);

	void Update(CPlayer*, CHp*, CCombo*, CHit*);
	void Render(HDC);
};

class CPlayerBody {
	int m_PosX, m_PosY;
public:
	CPlayerBody(int PosX, int PosY);
	~CPlayerBody();

	int GetPosX() { return m_PosX; }
	int GetPosY() { return m_PosY; }

	void Update();
	void Render(HDC hdc);
};

#endif