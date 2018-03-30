#include "Enemy.h"
#include "GameMap.h"
#include "AnimationInitialization.h"

Enemy::Enemy(float x, float y) : ActiveGameObject(x, y)
{
	this->collider = new Collider(x + SLIME_COLLIDER_SHIFT_X, y + SLIME_COLLIDER_SHIFT_Y,
		SLIME_COLLIDER_HEIGHT, SLIME_COLLIDER_WIDTH, "Enemy");
	GameMap::Colliders.push_back(this->collider);

	using namespace AnimationInitialization;
	vector<int> FrameDelays;
	for (int i = 0; i < 2 * SLIME_ANIM_LENGTH + 4; i++) // +4 is TESTING!!!
	{
		FrameDelays.push_back(8);
	}

	this->Moving = new Animation(&Slime, &SlimeAttack, FrameDelays);
	Moving->Randomize();

	last_x = 0;
	last_y = 0;
	GameMap::RandomEmptyPosition(final_x, final_y);
}

void Enemy::Draw()
{
	al_draw_bitmap(Moving->GetNext(), x, y, 0);
}

void Enemy::MoveTo(float next_x, float next_y)
{
	float normalizer = sqrt(pow((next_x - x),2) + pow((next_y - y),2));
	float xNew = x + SLIME_SPEED*(next_x - x) / normalizer;
	float yNew = y + SLIME_SPEED*(next_y - y) / normalizer;

	collider->SetXY(xNew + SLIME_COLLIDER_SHIFT_X, yNew + SLIME_COLLIDER_SHIFT_Y); // check the new location for collisions
	for each (Collider* it in GameMap::Colliders)
	{
		if ((it != collider)&&(it->flag != "EnemySpell"))
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				if (it->flag != "Spell")
				{
					crashed = 1;
				}

				collider->SetXY(x + SLIME_COLLIDER_SHIFT_X, y + SLIME_COLLIDER_SHIFT_Y);
				return;
			}
		}
	}
	// if collision didnt occur
	x = xNew;
	y = yNew;
}

void Enemy::Move()
{
	if ((crashed == 1)||((round(final_x - x) == 0.0)&&(round(final_x - x) == 0.0)))
	{
		GameMap::RandomEmptyPosition(final_x, final_y);
		crashed = 0;
	}

	MoveTo(final_x, final_y);
}

Enemy::~Enemy()
{
	delete Moving;
	delete Death;
}