#pragma once
#include "Header.h"

class GameObject
{
protected:
	ALLEGRO_BITMAP* image;
	float x;
	float y;

public:
	GameObject(const char* fileName, float x, float y);
	~GameObject() {}
	virtual void Draw() = 0;
};

