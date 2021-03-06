#include "CBullet.h"
#include "CTransform.h"
#include "CBulletRenderer.h"
#include "CBulletUpdater.h"
#include "CGameHost.h"

//CBulletBody::CBulletBody(int X, int Y, BOOL bEnemy) {
//	this->X = X, this->Y = Y;
//	hBrush = CreateSolidBrush(RGB(255,255,0));
//	hEnemyBrush = CreateSolidBrush(RGB(0,255,0));
//	hPen = (HPEN)GetStockObject(NULL_PEN);
//	this->bEnemy = bEnemy;
//}
//
//CBulletBody::~CBulletBody() {
//	DeleteObject(hBrush);
//	DeleteObject(hEnemyBrush);
//	DeleteObject(hPen);
//}
//
//void CBulletBody::MoveBody() {
//	if(bEnemy) {
//		Y += BULLET_SPEED;
//		if(Y>600) Y=600;
//	} else {
//		Y -= BULLET_SPEED;
//		if(Y<0) Y=0;
//	}
//}
//
//int CBulletBody::GetX() { return X; }
//int CBulletBody::GetY() { return Y; } 
//
//void CBulletBody::Update() {
//	MoveBody();
//}
//
//void CBulletBody::Render(HDC hdc) {
//	HBRUSH OldBrush;
//	if(bEnemy) OldBrush = (HBRUSH)SelectObject(hdc,hEnemyBrush);
//	else OldBrush = (HBRUSH)SelectObject(hdc,hBrush);
//	HPEN OldPen = (HPEN)SelectObject(hdc,hPen);
//	Rectangle(hdc,X,Y,X+BULLET_WIDTH,Y+BULLET_HEIGHT);
//	SelectObject(hdc,OldPen);
//	SelectObject(hdc,OldBrush);
//}

CBullet::CBullet(CTransform* player_transform, bool bEnemy) {
	//Delay = 0;
	//IsBulletOn = TRUE;
	this->bEnemy = bEnemy;
	
	this->transform = new CTransform(player_transform->getX()+player_transform->getSize()/2, player_transform->getY());
	this->renderer = new CBulletRenderer(this->transform);
	((CBulletRenderer*)this->renderer)->setAlive(&isAlive);
	this->updater = new CBulletUpdater(this->transform);
	if (bEnemy) {
		((CBulletUpdater*)this->updater)->reverse_direction();
		((CBulletRenderer*)this->renderer)->set_bullet_color(255,0,0);
	}

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);
	CGameHost::bullets.push_back(this);
}

CBullet::~CBullet() {
}

//void CBullet::PushBody(int PosX, int PosY, int Combo) {
//	if(!Delay) {
//		CBulletBody *Body;
//		//if(!bEnemy) {
//		if(Combo>=10) {
//			Body = new CBulletBody(PosX-7,PosY-3,bEnemy);
//			this->Body.push_back(Body);
//			Body = new CBulletBody(PosX+7,PosY-3,bEnemy);
//			this->Body.push_back(Body);
//		}
//		//}
//		Body = new CBulletBody(PosX,PosY,bEnemy);
//		this->Body.push_back(Body);
//	}
//	Delay++;
//	if(Delay==5) Delay=0;
//}

//void CBullet::PopBody() {
//	vector<CBulletBody*>::size_type Count = Body.size();
//	this->Body.erase(this->Body.begin());
//}
//
//void CBullet::DrawBody(HDC hdc) {
//	for(vector<CBulletBody*>::iterator Iter=Body.begin();Iter!=Body.end();++Iter)
//		(*Iter)->Render(hdc);
//}

//BOOL CBullet::CheckHit(int X, int Y, int Size) {
//	for(vector<CBulletBody*>::iterator Iter=Body.begin();Iter!=Body.end();++Iter) {
//		int _X = (*Iter)->GetX();
//		int _Y = (*Iter)->GetY();
//		if(X-BULLET_WIDTH<=_X && X+Size>=_X && Y-BULLET_HEIGHT<=_Y && Y+Size>=_Y) {
//			Body.erase(Iter);
//			goto CBULLET_CHECKHIT;
//		}
//	}
//	return FALSE;
//CBULLET_CHECKHIT:
//	return TRUE;
//}

//BOOL CBullet::GetBulletMode() {
//	return IsBulletOn;
//}

void CBullet::Update() {
//CBULLET_UPDATE:
//	for(vector<CBulletBody*>::iterator Iter=Body.begin();Iter!=Body.end();++Iter) {
//		if((*Iter)->GetY()==0 || (*Iter)->GetY()==600) {
//			Body.erase(Iter);
//			goto CBULLET_UPDATE;
//		}
//		(*Iter)->Update();
//	}
//	if(!Body.size()) IsBulletOn=FALSE;
//	else IsBulletOn=TRUE;
	this->updater->Update();
}

void CBullet::Render(HDC hdc) {
	//DrawBody(hdc);
	this->renderer->Render(hdc);
}