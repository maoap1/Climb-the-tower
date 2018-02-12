#include "Player.h"


//Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders) : GameObject(fileName, x, y)
Player::Player(float x, float y, 
	Animation* RunLeft, Animation* RunRight, Animation* RunUp, Animation* RunDown, 
	Animation* IdleLeft, Animation* IdleRight, Animation* IdleUp, Animation* IdleDown) : GameObject(x, y)
{
	this->collider = new Collider(x + PLAYER_COLLIDER_SHIFT_X, y + PLAYER_COLLIDER_SHIFT_Y,
								  PLAYER_COLLIDER_WIDTH, PLAYER_COLLIDER_HEIGHT, "Player");
	GameMap::Colliders.push_back(this->collider);
	this->RunLeft = RunLeft;
	this->RunRight = RunRight;
	this->RunUp = RunUp;
	this->RunDown = RunDown;
	this->IdleLeft = IdleLeft;
	this->IdleRight = IdleRight;
	this->IdleUp = IdleUp;
	this->IdleDown = IdleDown;
	lastDirection = ID_DOWN;
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
		case ID_LEFT:
			currentBitmap = RunLeft->GetNext(animAttacked);
			break;
		case ID_UP:
			currentBitmap = RunUp->GetNext(animAttacked);
			break;
		case ID_RIGHT:
			currentBitmap = RunRight->GetNext(animAttacked);
			break;
		case ID_DOWN:
			currentBitmap = RunDown->GetNext(animAttacked);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (lastDirection)
		{
		case ID_LEFT:
			currentBitmap = IdleLeft->GetNext(animAttacked);
			break;
		case ID_UP:
			currentBitmap = IdleUp->GetNext(animAttacked);
			break;
		case ID_RIGHT:
			currentBitmap = IdleRight->GetNext(animAttacked);
			break;
		case ID_DOWN:
			currentBitmap = IdleDown->GetNext(animAttacked);
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

void Player::Move(int direction)
{
	moved = true;

	int xNew = x;
	int yNew = y;
	switch (direction)
	{
	case ID_LEFT:
		xNew -= speed;
		break;
	case ID_UP:
		yNew -= speed;
		break;
	case ID_RIGHT:
		xNew += speed;
		break;
	case ID_DOWN:
		yNew += speed;
		break;
	default:
		break;
	}
	collider->SetXY(xNew+PLAYER_COLLIDER_SHIFT_X, yNew+PLAYER_COLLIDER_SHIFT_Y); // check the new location for collisions
	for each (Collider* it in GameMap::Colliders)
	{
		if (it->flag != "Player")
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				collider->SetXY(x+PLAYER_COLLIDER_SHIFT_X, y+PLAYER_COLLIDER_SHIFT_Y);
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
	if ((!moreDirections)||(lastDirection == ID_DOWN)) // The second condition is bugfix
	{
		lastDirection = ID_UP;
	}
	Move(ID_UP);
}

void Player::MoveDown()
{
	if ((!moreDirections) || (lastDirection == ID_UP)) // The second condition is bugfix
	{
		lastDirection = ID_DOWN;
	}
	Move(ID_DOWN);
}

void Player::MoveLeft()
{
	if ((!moreDirections) || (lastDirection == ID_RIGHT)) // The second condition is bugfix
	{
		lastDirection = ID_LEFT;
	}
	Move(ID_LEFT);
}

void Player::MoveRight()
{
	if ((!moreDirections) || (lastDirection == ID_LEFT)) // The second condition is bugfix
	{
		lastDirection = ID_RIGHT;
	}
	Move(ID_RIGHT);
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

		GameMap::CreateSpell(x, y, lastDirection, ID_FIREBALL);

		// prozatim
		currentAttackFrame = 0;
	}
	
}
