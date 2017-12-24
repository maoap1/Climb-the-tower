#pragma once

#include "GameObject.h"
#include "Header.h"

class Player : public GameObject
{
protected:
	ALLEGRO_BITMAP* image2;
	int last_drawn = 2;
public:
	Player(const char* fileName, const char* fileName2, float x, float y);
	void Draw() override;
	// is destructor needed?
};

