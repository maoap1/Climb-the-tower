#pragma once

#include "Header.h"
#include "ActiveGameObject.h"
#include "Animation.h"
#include "Collider.h"
#include "Damagable.h"

class Enemy : public ActiveGameObject, public Damagable
{
private:
	int orientation;
	Animation* Moving;
	Animation* Death;
	int collider_width;
	int collider_height;
	int collider_shift_x;
	int collider_shift_y;
	Collider* collider;

	float final_x;
	float final_y;

	int crashed; // 0 false, 1 true
	bool triggered;
	bool hitted;
	bool attacked;
	int currentHittedFrame;
	int currentAttackFrame;
	int recoveryFrames;
	/// <summary>
	/// Number of lives of this creature
	/// </summary>
	float lives;
	/// <summary>
	/// The speed multiplier used when hitted by waterblast
	/// </summary>
	float speed_multiplier;
	/// <summary>
	/// Determines whether the slime is burning or not. Once caught fire, it will slowly die.
	/// </summary>
	bool burning;

	void MoveTo(float x, float y);
	void Attack();

public:
	Enemy(float x, float y, float lives);
	void Draw() override;
	void Move() override;
	void Damage(int damageType, int value) override;
	~Enemy() override;
};