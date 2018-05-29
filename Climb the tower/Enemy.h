#pragma once

#include "Header.h"
#include "ActiveGameObject.h"
#include "Animation.h"
#include "Collider.h"
#include "Damagable.h"

class Enemy : public ActiveGameObject, public Damagable
{
private:
	/// <summary>
	/// orientation of the enemy
	/// </summary>
	int orientation;
	Animation* Moving;
	Animation* Death;
	int collider_width;
	int collider_height;
	int collider_shift_x;
	int collider_shift_y;
	/// <summary>
	/// The collider of the enemy
	/// </summary>
	Collider* collider;

	float final_x;
	float final_y;

	int crashed; // 0 false, 1 true
	bool triggered; // true if it sees the player, false if otherwise
	bool hit; // true if hit by spell, false otherwise
	bool attacked;
	int currentHittedFrame;
	int currentAttackFrame;

	/// <summary>
	/// Number of lives of this creature
	/// </summary>
	float lives;
	/// <summary>
	/// The speed multiplier used when hit by waterblast
	/// </summary>
	float speed_multiplier;
	/// <summary>
	/// Determines whether the slime is burning or not. Once caught fire, it will slowly die.
	/// </summary>
	bool burning;

	void MoveTo(float x, float y);
	void Attack();

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Enemy"/> class.
	/// </summary>
	/// <param name="x">The x coordinate of the enemy</param>
	/// <param name="y">The y coordinate of the enemy</param>
	/// <param name="lives">Lives of the enemy</param>
	Enemy(float x, float y, float lives);

	/// <summary>
	/// Draws this instance.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Moves this instance.
	/// </summary>
	void Move() override;

	/// <summary>
	/// Damages this instance
	/// </summary>
	/// <param name="damageType">Type of the damage.</param>
	/// <param name="value">How much damage</param>
	void Damage(int damageType, int value) override;

	/// <summary>
	/// Finalizes an instance of the <see cref="Enemy"/> class.
	/// </summary>
	~Enemy() override;
};