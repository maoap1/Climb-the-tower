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
	Animation* Moving;
	Animation* Death;
	Spell* me;
	Collider* collider;

public:
	Spell(float x, float y, int orientation, int spellID);
	void SetMe(Spell* me);
	void Draw() override;
	void Move() override;
	~Spell();
};

