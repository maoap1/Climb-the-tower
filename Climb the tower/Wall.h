#pragma once

#include "GameObject.h"
#include "Header.h"
#include "AllegroHandling.h"

/// <summary>
/// This is the basic wall object. It just stands in corners and creates a game map
/// </summary>
/// <seealso cref="GameObject" />
class Wall : public GameObject
{
private:
	/// <summary>
	/// The image of the wall
	/// </summary>
	ALLEGRO_BITMAP* image;

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Wall"/> class.
	/// </summary>
	/// <param name="fileName">Name of the sprite file.</param>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	Wall(const char* fileName, float x, float y);

	/// <summary>
	/// Draws this instance.
	/// </summary>
	void Draw() override;
	
	/// <summary>
	/// Finalizes an instance of the <see cref="Wall"/> class.
	/// </summary>
	~Wall() override;
};
