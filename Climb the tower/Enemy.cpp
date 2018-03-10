#include "Enemy.h"
#include "GameMap.h"
#include "AnimationInitialization.h"

Enemy::Enemy(float x, float y, int orientation) : ActiveGameObject(x, y)
{
}

void Enemy::Draw()
{
}

void Enemy::Move()
{
}

Enemy::~Enemy()
{
	delete Moving;
	delete Death;
}