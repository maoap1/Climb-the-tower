#include "Player.h"



//Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders) : GameObject(fileName, x, y)
Player::Player(float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders, 
	Animation* RunLeft, Animation* RunRight, Animation* RunUp, Animation* RunDown) : GameObject(x, y)
	//Animation* IdleLeft, Animation* IdleRight, Animation* IdleUp, Animation* IdleDown);
{
	this->collider = collider;
	this->Colliders = Colliders;
	this->collider_shift_x = collider_shift_x;
	this->collider_shift_y = collider_shift_y;
	this->RunLeft = RunLeft;
	this->RunRight = RunRight;
	this->RunUp = RunUp;
	this->RunDown = RunDown;
	lastDirection = DOWN;
	moreDirections = false;
}

void Player::Draw()
{
	switch (lastDirection)
	{
	case UP:
		al_draw_scaled_bitmap(RunUp->GetNext(), 0, 0, 50, 50, x, y, 90, 90, 0);
		break;
	case DOWN:
		al_draw_scaled_bitmap(RunDown->GetNext(), 0, 0, 50, 50, x, y, 90, 90, 0);
		break;
	case LEFT:
		al_draw_scaled_bitmap(RunLeft->GetNext(), 0, 0, 50, 50, x, y, 90, 90, 0);
		break;
	case RIGHT:
		al_draw_scaled_bitmap(RunRight->GetNext(), 0, 0, 50, 50, x, y, 90, 90, 0);
		break;
	default:
		break;
	}
	//al_draw_scaled_bitmap(RunLeft->GetNext(), 0, 0, 50, 50, x, y, 90, 90, 0);
	//al_draw_scaled_bitmap(image3, 0, 0, 50, 50, x, y, 90, 90, 0);


	/*
	switch (last_drawn)
	{
	case 1:
		al_draw_scaled_bitmap(image2, 0, 0, 50, 50, x, y, 100, 100, 0);
		//al_draw_bitmap(image2, x, y, 0);
		if (frame++ >= frame_delay)
		{
			last_drawn = 2;
			frame = 0;
		}
		break;
	case 2:
		al_draw_scaled_bitmap(image, 0, 0, 50, 50, x, y, 100, 100, 0);
		if (frame++ >= frame_delay)
		{
			last_drawn = 1;
			frame = 0;
		}
		break;
	default:
		break;
	}
	*/
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
	if (!moreDirections)
	{
		lastDirection = UP;
	}
	Move(UP);
}

void Player::MoveDown()
{
	if (!moreDirections)
	{
		lastDirection = DOWN;
	}
	Move(DOWN);
}

void Player::MoveLeft()
{
	if (!moreDirections)
	{
		lastDirection = LEFT;
	}
	Move(LEFT);
}

void Player::MoveRight()
{
	if (!moreDirections)
	{
		lastDirection = RIGHT;
	}
	Move(RIGHT);
}

void Player::MoreDirections(bool moreDirections)
{
	this->moreDirections = moreDirections;
}
