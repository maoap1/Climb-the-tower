#pragma once

#include "Header.h"
#include "ActiveGameObject.h"
#include "Animation.h"
#include "Collider.h"
#include "AllegroHandling.h"

class Spell : public ActiveGameObject
{
private:
	int orientation;
	int spellID;
	int speed = SPELL_SPEED;
	Animation* Moving;
	Animation* Death;
	int collider_shift_x;
	int collider_shift_y;
	Collider* collider;
	int crashed; // 0 false, 1 true AND it is drawn for the first time, 2 true

public:
	Spell(float x, float y, int orientation, int spellID);
	void Draw() override;
	void Move() override;
	~Spell();
};

