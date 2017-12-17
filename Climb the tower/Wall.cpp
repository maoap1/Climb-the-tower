#include "Wall.h"

void Wall::Draw()
{
	al_draw_bitmap(image, x, y, 0);
}
