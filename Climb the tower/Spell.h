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
	Spell* me;
	int collider_shift_x;
	int collider_shift_y;
	Collider* collider;
	list<Collider*>* Colliders;
	bool crashed;

public:
	Spell(float x, float y, int orientation, int spellID, list<Collider*>* Colliders);
	void SetMe(Spell* me);
	void Draw() override;
	void Move() override;
	~Spell();
};

