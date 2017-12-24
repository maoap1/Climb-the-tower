#pragma once

#include "GameObject.h"
#include "Header.h"

class Wall : public GameObject
{
public:
	Wall(const char* fileName, float x, float y) :GameObject(fileName, x, y) {}
	void Draw() override;
	// is destructor needed?
};
