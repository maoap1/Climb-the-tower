#pragma once
#include "GameObject.h"
#include "Header.h"

class ActiveGameObject : public GameObject
{
public:
	ActiveGameObject(float x, float y);

	virtual void Move() = 0;
	virtual void Draw() = 0;

	~ActiveGameObject();
};

