#pragma once
#include "GameObject.h"
#include "Header.h"

/// <summary>
/// Abstract class derived from GameObject that allows using of Move() and Draw() functions
/// </summary>
/// <seealso cref="GameObject" />
class ActiveGameObject : public GameObject
{
public:
	ActiveGameObject(float x, float y);

	virtual void Move() = 0;
	virtual void Draw() = 0;

	virtual ~ActiveGameObject();
};

