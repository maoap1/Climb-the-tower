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

	float last_x;
	float last_y;
	float final_x;
	float final_y;

	int crashed; // 0 false, 1 true
	bool triggered;
	bool hitted;
	bool attacked;
	int currentHittedFrame;
	int currentAttackFrame;
	int recoveryFrames;

	void MoveTo(float x, float y);
	void Attack();

public:
	Enemy(float x, float y);
	void Draw() override;
	void Move() override;
	void Damage(int damageType, int value) override;
	~Enemy() override;
};