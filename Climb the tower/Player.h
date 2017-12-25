#pragma once

#include "Collider.h"
#include "GameObject.h"
#include "Header.h"

class Player : public GameObject
{
private:
	enum Direction {UP,DOWN,LEFT,RIGHT};
	const int speed = 2; //2 worked fine
	void Move(Direction direction);
	list<Collider*>* Colliders;

protected:
	ALLEGRO_BITMAP* image2;
	int last_drawn = 2;
	int frame = 0;
	int frame_delay = 6; // Wouldn't it be a constant?
	Collider* collider;
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="fileName">Name of the first sprite file.</param>
	/// <param name="fileName2">Name of the second sprite file.</param>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	/// <param name="collider">The collider of the player</param>
	/// <param name="Colliders">The reference to the list of all colliders in the game</param>
	Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, list<Collider*>* Colliders);


	/// <summary>
	/// Returns the collider.
	/// </summary>
	/// <returns></returns>
	Collider* GetCollider();

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

