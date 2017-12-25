#include "Player.h"



Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider) : GameObject(fileName, x, y)
{
	image2 = al_load_bitmap(fileName2);
	this->collider = collider;
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

	x = xNew;
	y = yNew;
}

void Player::MoveUp()
{
	Move(Player::UP);
	collider->SetXY(x, y);
}

void Player::MoveDown()
{
	Move(Player::DOWN);
	collider->SetXY(x, y);
}

void Player::MoveLeft()
{
	Move(Player::LEFT);
	collider->SetXY(x, y);
}

void Player::MoveRight()
{
	Move(Player::RIGHT);
	collider->SetXY(x, y);
}
