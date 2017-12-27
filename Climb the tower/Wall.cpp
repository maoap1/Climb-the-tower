#include "Wall.h"



Wall::Wall(const char * fileName, float x, float y) : GameObject(x, y)
{
	this->image = al_load_bitmap(fileName);
}

void Wall::Draw()
{
	al_draw_scaled_bitmap(image, 0, 0, 50, 50, x, y, 75, 75, 0);
}
