#include "Wall.h"



Wall::Wall(const char * fileName, float x, float y) : GameObject(x, y)
{
	this->image = AllegroHandling::load_resized_bitmap(fileName, WALL_SIZE, WALL_SIZE);
}

void Wall::Draw()
{
	al_draw_bitmap(image, x, y, 0);
}

Wall::~Wall()
{

}
