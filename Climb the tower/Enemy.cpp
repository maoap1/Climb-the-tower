#include "Enemy.h"
#include "GameMap.h"
#include "AnimationInitialization.h"
#include "ObjectsCreation.h"

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
	recoveryFrames = 0;
	GameMap::RandomEmptyPosition(final_x, final_y);

	hitted = false;
	triggered = false;
	attacked = false;

	currentHittedFrame = 0;
	currentAttackFrame = 0;
}

void Enemy::Draw()
{
	if (attacked)
	{
		currentAttackFrame++;
		if (currentAttackFrame > SLIME_ATTACK_DELAY)
		{
			attacked = false;
		}
	}

	if (hitted)
	{
		currentHittedFrame++;
		if (currentHittedFrame > SLIME_HITTED_ANIM_DELAY)
		{
			hitted = false;
		}
	}

	al_draw_bitmap(Moving->GetNext(hitted), x, y, 0);
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
				else
				{
					triggered = true;
					hitted = true;
					currentHittedFrame = 0;
				}

				collider->SetXY(x + SLIME_COLLIDER_SHIFT_X, y + SLIME_COLLIDER_SHIFT_Y);
				return;
			}
		}
	}
	// if collision didnt occur
	x = xNew;
	y = yNew;
	if (collider->collided)
	{
		collider->collided = false;
		hitted = true;
		triggered = true;
		currentHittedFrame = 0;
	}
}

void Enemy::Move()
{
	using namespace ObjectsCreation;

	float x_dif = abs(x - player->Get_x());
	float y_dif = abs(y - player->Get_y());
	float distance = sqrt(pow(x_dif, 2) + pow(y_dif, 2));
	if (distance < AGGRO_INIT_DISTANCE)
	{
		triggered = true;
	}
	else if (distance > AGGRO_MAX_DISTANCE)
	{
		triggered = false;
	}

	if (!triggered)
	{
		if ((crashed == 1) || ((round(final_x - x) == 0.0) && (round(final_x - x) == 0.0)))
		{
			GameMap::RandomEmptyPosition(final_x, final_y);
			crashed = 0;
		}
		MoveTo(final_x, final_y);
	}

	if (triggered)
	{
		MoveTo(player->Get_x(), player->Get_y());
		Attack();
	}
}

void Enemy::Attack()
{
	if (!attacked)
	{
		attacked = true;

		using namespace ObjectsCreation;
		float x_dif = x - player->Get_x();
		float y_dif = y - player->Get_y();

		int direction;
		if (abs(x_dif)>abs(y_dif)) // Left or Right
		{
			if (x_dif>0) // Left
			{
				direction = ID_LEFT;
			}
			else         // Right
			{
				direction = ID_RIGHT;
			}
		}
		else					   // Up or Down
		{
			if (y_dif>0) // Up
			{
				direction = ID_UP;
			}
			else         // Down
			{
				direction = ID_DOWN;
			}
		}

		GameMap::CreateSpell(x+10, y+10, direction, ID_SLIMEBALL);
		currentAttackFrame = 0;
	}
}

Enemy::~Enemy()
{
	delete Moving;
	delete Death;
}