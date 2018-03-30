#include "Collider.h"



Collider::Collider(int x, int y, int height, int width, string flag) // there shouldn't be: string flag = ""
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->flag = flag;
	this->collided = false;
}


Collider::~Collider()
{

}

bool Collider::HasCollided(const Collider& other)
{ // standard check for collisions of box colliders
	if ((x > other.x + other.width - 1) || (y > other.y + other.height - 1) ||
		(other.x > x + width - 1) || (other.y > y + height - 1))
	{
		// no collision
		return false;
	}
	// collision
	return true;
}

void Collider::SetXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

#ifdef DEBUG
void Collider::Draw()
{
	al_draw_rectangle(x, y, x + width, y + height, al_map_rgb(0, 255, 0), 1.0);
}
#endif // DEBUG
