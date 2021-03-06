#include "CEnemyUpdater.h"
#include "CTransform.h"
#include "CBullet.h"

CEnemyUpdater::CEnemyUpdater(CTransform* transform)
{
	this->transform = transform;
	delay = 0;
	PreKey = 0;
	AlphaSpeed = 0;
}


CEnemyUpdater::~CEnemyUpdater()
{
}

void CEnemyUpdater::move(bool isLeft)
{
	if (isLeft)
		moveLeft();
	else
		moveRight();
}

void CEnemyUpdater::moveRight()
{
	if (PreKey != RIGHT) AlphaSpeed = 0; //Check Last Key
	if (transform->getX() + AlphaSpeed + 1 < 580)
		transform->setX(transform->getX() + (AlphaSpeed + 1));
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = RIGHT;
	//transform->setX(transform->getX() + 3);
}

void CEnemyUpdater::moveLeft()
{
	if (PreKey != LEFT) AlphaSpeed = 0; //Check Last Key
	if (transform->getX() - AlphaSpeed + 1 > 0)
		transform->setX(transform->getX() - (AlphaSpeed + 1));
	if (AlphaSpeed < MAX_ENEMY_SPEED) AlphaSpeed++;
	PreKey = LEFT;
	//transform->setX(transform->getX() - 1);
}

void CEnemyUpdater::Update()
{
	if (delay > 5) {
		CBullet* bullet = new CBullet(transform, true);
		delay = 0;
	}
	delay++;
}

void CEnemyUpdater::Pause()
{
}
