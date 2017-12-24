#include "Player.h"



Player::Player(const char* fileName, const char* fileName2, float x, float y) : GameObject(fileName, x, y)
{
	image2 = al_load_bitmap(fileName2);
}

void Player::Draw()
{
	switch (last_drawn)
	{
	case 1:
		al_draw_bitmap(image2, x, y, 0);
		last_drawn = 2;
		break;
	case 2:
		al_draw_bitmap(image, x, y, 0);
		last_drawn = 1;
		break;
	default:
		break;
	}

}
