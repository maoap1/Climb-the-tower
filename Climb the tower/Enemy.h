#pragma once

#include "Header.h"
#include "ActiveGameObject.h"
#include "Animation.h"
#include "Collider.h"

class Enemy : public ActiveGameObject
{
private:
	int orientation;
	//int speed = SPELL_SPEED;
	Animation* Moving;
	Animation* Death;
	//int collider_shift_x;
	//int collider_shift_y;
	//Collider* collider;
	//int crashed; // 0 false, 1 true AND it is drawn for the first time, 2 true

public:
	Enemy(float x, float y);
	void Draw() override;
	void Move() override;
	~Enemy() override;
};