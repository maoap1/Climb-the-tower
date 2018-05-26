#include "Enemy.h"
#include "GameMap.h"
#include "AnimationInitialization.h"
#include "ObjectsCreation.h"

Enemy::Enemy(float x, float y, float lives) : ActiveGameObject(x, y)
{
	this->collider = new Collider(x + SLIME_COLLIDER_SHIFT_X, y + SLIME_COLLIDER_SHIFT_Y,
		SLIME_COLLIDER_HEIGHT, SLIME_COLLIDER_WIDTH, "Enemy", this);
	GameMap::Colliders.push_back(this->collider);

	using namespace AnimationInitialization;
	vector<int> FrameDelays;
	for (int i = 0; i < 2 * SLIME_ANIM_LENGTH + SLIME_ANIM_ADDITIONAL; i++)
	{
		FrameDelays.push_back(8);
	}

	this->Moving = new Animation(&Slime, &SlimeAttack, FrameDelays);
	Moving->Randomize();

	this->lives = lives;
	speed_multiplier = 1; // this goes down when hitted by waterblast

	recoveryFrames = 0;
	GameMap::RandomEmptyPosition(final_x, final_y);

	hitted = false;
	triggered = false;
	attacked = false;
	burning = false;

	currentHittedFrame = 0;
	currentAttackFrame = 0;
}

void Enemy::Draw()
{
	if (lives <= 0)
	{
		GameMap::Movables.remove(this);
		GameMap::Colliders.remove(this->collider);
		delete collider;
		GameMap::ToDeletion.push_back(this);
	}
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
	if (burning)
	{
		al_draw_tinted_bitmap(Moving->GetNext(hitted), al_map_rgba_f(1, 0.6, 0, 1), x, y, 0);
	}
	else if (speed_multiplier < 1)
	{
		al_draw_tinted_bitmap(Moving->GetNext(hitted), al_map_rgba_f(0, 1, 0.8, 1), x, y, 0);
	}
	else
	{
		al_draw_bitmap(Moving->GetNext(hitted), x, y, 0);
	}
}

void Enemy::MoveTo(float next_x, float next_y)
{
	float normalizer = sqrt(pow((next_x - x),2) + pow((next_y - y),2));
	float xNew = x + speed_multiplier*SLIME_SPEED*(next_x - x) / normalizer;
	float yNew = y + speed_multiplier*SLIME_SPEED*(next_y - y) / normalizer;
	if (speed_multiplier < 1)
	{
		speed_multiplier += SLIME_SPEED_RECOVERY;
	}
	else if (speed_multiplier > 1)
	{
		speed_multiplier = 1;
	}
	if (burning)
	{
		lives -= BURNING_DAMAGE;
	}
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

void Enemy::Damage(int damageType, int value)
{
	if (damageType == ID_WATERBLAST)
	{
		speed_multiplier = 0;
		lives -= value / 4;
	}
	else if (damageType == ID_ARCANEBALL)
	{
		lives -= value;
	}
	else if (damageType == ID_FIREBALL)
	{
		burning = true;
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