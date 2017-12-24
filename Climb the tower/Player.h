#pragma once

#include "GameObject.h"
#include "Header.h"

class Player : public GameObject
{
protected:
	ALLEGRO_BITMAP* image2;
	int last_drawn = 2;
	int frame = 0;
	int frame_delay = 6; // Wouldn't it be a constant?
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="fileName">Name of the first sprite file.</param>
	/// <param name="fileName2">Name of the second sprite file.</param>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	Player(const char* fileName, const char* fileName2, float x, float y);

	/// <summary>
	/// Draws this instance.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Moves up.
	/// </summary>
	void MoveUp();

	/// <summary>
	/// Moves down.
	/// </summary>
	void MoveDown();

	/// <summary>
	/// Moves to the left.
	/// </summary>
	void MoveLeft();

	/// <summary>
	/// Moves to the right.
	/// </summary>

	void MoveRight();
	// is destructor needed?
};

