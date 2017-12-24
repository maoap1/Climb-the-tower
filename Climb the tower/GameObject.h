#pragma once
#include "Header.h"

class GameObject
{
protected:
	ALLEGRO_BITMAP* image;
	float x;
	float y;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="GameObject"/> class.
	/// </summary>
	/// <param name="fileName">Name of the sprite file.</param>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	GameObject(const char* fileName, float x, float y);

	/// <summary>
	/// Finalizes an instance of the <see cref="GameObject"/> class.
	/// </summary>
	~GameObject() {}

	/// <summary>
	/// Draws this instance.
	/// </summary>
	virtual void Draw() = 0;
};

