#include "Player.h"



Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider,list<Collider*>* Colliders) : GameObject(fileName, x, y)
{
	image2 = al_load_bitmap(fileName2);
	this->collider = collider;
	this->Colliders = Colliders;
}

void Player::Draw()
{
	switch (last_drawn)
	{
	case 1:
		al_draw_bitmap(image2, x, y, 0);
		if (frame++ >= frame_delay)
		{
			last_drawn = 2;
			frame = 0;
		}
		break;
	case 2:
		al_draw_bitmap(image, x, y, 0);
		if (frame++ >= frame_delay)
		{
			last_drawn = 1;
			frame = 0;
		}
		break;
	default:
		break;
	}
}

Collider* Player::GetCollider()
{
	return collider;
}

void Player::Move(Direction direction)
{
	//!!!!!!!!!!!!!!!!!!!!!BUG BUG BUG BUG BUG!!!!!!!!!!!!!!!!!!!!!
	// When moving diagonally, the player is walking faster
	// Is it needed to be fixed?
	int xNew = x;
	int yNew = y;
	switch (direction)
	{
	case Player::UP:
		yNew -= speed;
		break;
	case Player::DOWN:
		yNew += speed;
		break;
	case Player::LEFT:
		xNew -= speed;
		break;
	case Player::RIGHT:
		xNew += speed;
		break;
	default:
		break;
	}
	collider->SetXY(xNew, yNew); // check the new location for collisions
	for each (Collider* it in *Colliders)
	{
		if (it->flag != "Player")
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				collider->SetXY(x, y);
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
	Move(Player::UP);
}

void Player::MoveDown()
{
	Move(Player::DOWN);
}

void Player::MoveLeft()
{
	Move(Player::LEFT);
}

void Player::MoveRight()
{
	Move(Player::RIGHT);
}
