#include "Player.h"


//Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders) : GameObject(fileName, x, y)
Player::Player(float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders, 
	Animation* RunLeft, Animation* RunRight, Animation* RunUp, Animation* RunDown, 
	Animation* IdleLeft, Animation* IdleRight, Animation* IdleUp, Animation* IdleDown) : GameObject(x, y)
{
	this->collider = collider;
	this->Colliders = Colliders;
	this->collider_shift_x = collider_shift_x;
	this->collider_shift_y = collider_shift_y;
	this->RunLeft = RunLeft;
	this->RunRight = RunRight;
	this->RunUp = RunUp;
	this->RunDown = RunDown;
	this->IdleLeft = IdleLeft;
	this->IdleRight = IdleRight;
	this->IdleUp = IdleUp;
	this->IdleDown = IdleDown;
	lastDirection = DOWN;
	moreDirections = false;
	attacked = false;
	animAttacked = false;
	currentAttackFrame = 0;
}

void Player::Draw()
{
	if (attacked)
	{
		currentAttackFrame++;
		if (currentAttackFrame > attackDelay)
		{
			attacked = false;
		}
		if (animAttacked)
		{
			if (currentAttackFrame > attackAnimDelay)
			{
				animAttacked = false;
			}
		}
	}

	ALLEGRO_BITMAP* currentBitmap = 0;

	if (moved)
	{
		switch (lastDirection)
		{
		case UP:
			currentBitmap = RunUp->GetNext(animAttacked);
			break;
		case DOWN:
			currentBitmap = RunDown->GetNext(animAttacked);
			break;
		case LEFT:
			currentBitmap = RunLeft->GetNext(animAttacked);
			break;
		case RIGHT:
			currentBitmap = RunRight->GetNext(animAttacked);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (lastDirection)
		{
		case UP:
			currentBitmap = IdleUp->GetNext(animAttacked);
			break;
		case DOWN:
			currentBitmap = IdleDown->GetNext(animAttacked);
			break;
		case LEFT:
			currentBitmap = IdleLeft->GetNext(animAttacked);
			break;
		case RIGHT:
			currentBitmap = IdleRight->GetNext(animAttacked);
			break;
		default:
			break;
		}
	}

	al_draw_bitmap(currentBitmap, x, y, 0);
}

Collider* Player::GetCollider()
{
	return collider;
}

void Player::Move(Direction direction)
{
	moved = true;

	int xNew = x;
	int yNew = y;
	switch (direction)
	{
	case UP:
		yNew -= speed;
		break;
	case DOWN:
		yNew += speed;
		break;
	case LEFT:
		xNew -= speed;
		break;
	case RIGHT:
		xNew += speed;
		break;
	default:
		break;
	}
	collider->SetXY(xNew+collider_shift_x, yNew+collider_shift_y); // check the new location for collisions
	for each (Collider* it in *Colliders)
	{
		if (it->flag != "Player")
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				collider->SetXY(x+collider_shift_x, y+collider_shift_y);
				return;
			}
		}
	}
	// if collision didnt occur
	x = xNew;
	y = yNew;
	
}

void Player::MoveUp()
{
	if ((!moreDirections)||(lastDirection == DOWN)) // The second condition is bugfix
	{
		lastDirection = UP;
	}
	Move(UP);
}

void Player::MoveDown()
{
	if ((!moreDirections) || (lastDirection == UP)) // The second condition is bugfix
	{
		lastDirection = DOWN;
	}
	Move(DOWN);
}

void Player::MoveLeft()
{
	if ((!moreDirections) || (lastDirection == RIGHT)) // The second condition is bugfix
	{
		lastDirection = LEFT;
	}
	Move(LEFT);
}

void Player::MoveRight()
{
	if ((!moreDirections) || (lastDirection == LEFT)) // The second condition is bugfix
	{
		lastDirection = RIGHT;
	}
	Move(RIGHT);
}

void Player::MoreDirections(bool moreDirections)
{
	this->moreDirections = moreDirections;
}

void Player::Attack()
{
	if (!attacked)
	{
		attacked = true;
		animAttacked = true;
		// vytvorit kouzlo

		GameMap::CreateSpell(x, y, ID_LEFT, ID_FIREBALL);

		// prozatim
		currentAttackFrame = 0;
	}
	
}
