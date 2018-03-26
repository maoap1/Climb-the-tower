#include "Enemy.h"
#include "GameMap.h"
#include "AnimationInitialization.h"

Enemy::Enemy(float x, float y) : ActiveGameObject(x, y)
{
	using namespace AnimationInitialization;
	vector<int> FrameDelays;
	for (int i = 0; i < 2 * SLIME_ANIM_LENGTH + 4; i++) // +4 is TESTING!!!
	{
		FrameDelays.push_back(8);
	}

	this->Moving = new Animation(&Slime, &SlimeAttack, FrameDelays);
}

void Enemy::Draw()
{
	al_draw_bitmap(Moving->GetNext(), x, y, 0);
}

void Enemy::Move()
{
}

Enemy::~Enemy()
{
	delete Moving;
	delete Death;
}