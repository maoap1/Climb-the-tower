#pragma once
#include "Header.h"

class GameObject
{
protected:
	float x;
	float y;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="GameObject"/> class.
	/// </summary>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	GameObject(float x, float y);

	/// <summary>
	/// Finalizes an instance of the <see cref="GameObject"/> class.
	/// </summary>
	virtual ~GameObject();

	/// <summary>
	/// Draws this instance.
	/// </summary>
	virtual void Draw() = 0;
};

