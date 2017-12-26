#include "Wall.h"

void Wall::Draw()
{
	al_draw_scaled_bitmap(image, 0, 0, 50, 50, x, y, 75, 75, 0);
}
