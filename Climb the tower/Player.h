#pragma once

#include "Header.h"
#include "Animation.h"
#include "Collider.h"
#include "Spell.h"
#include "GameMap.h"

class Player : public GameObject
{
private:
	const int speed = PLAYER_SPEED;
	int attackAnimDelay = PLAYER_INIT_ATTACK_ANIM_DELAY; // the minimum of attackDelay ever
	int attackDelay = PLAYER_INIT_ATTACK_DELAY; // podle me se bude zlepsovat s levelem
	void Move(int direction);
	list<Collider*>* Colliders;
	Animation* RunLeft;
	Animation* RunRight;
	Animation* RunUp;
	Animation* RunDown;
	Animation* IdleLeft;
	Animation* IdleRight;
	Animation* IdleUp;
	Animation* IdleDown;
	Collider* collider;

	int lastDirection; // it tells us which direction do we need to draw
	bool moreDirections;

	bool attacked;
	bool animAttacked;
	int currentAttackFrame;
	
public:

	bool moved;

	/*
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="fileName">Name of the first sprite file.</param>
	/// <param name="fileName2">Name of the second sprite file.</param>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	/// <param name="collider">The collider of the player</param>
	/// <param name="collider_shift_x">The x difference between origin of player and its collider</param>
	/// <param name="collider_shift_y">The y difference between origin of player and its collider</param>
	/// <param name="Colliders">The reference to the list of all colliders in the game</param>
	Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders);

	*/

	Player(float x, float y, list<Collider*>* Colliders,
		Animation* RunLeft, Animation* RunRight, Animation* RunUp, Animation* RunDown,
		Animation* IdleLeft, Animation* IdleRight, Animation* IdleUp, Animation* IdleDown);


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

	void MoreDirections(bool moreDirections);

	void Attack();

	// is destructor needed?
};

