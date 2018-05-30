#pragma once

#include "Header.h"
#include "ActiveGameObject.h"
#include "Animation.h"
#include "Collider.h"

class Spell : public ActiveGameObject
{
private:
	int orientation; // orientation of spell
	int spellID; // The identifier of spell -> see Constants.h
	int spellDamage = SPELL_DAMAGE;
	int speed = SPELL_SPEED;
	Animation* Moving;
	Animation* Death;
	int collider_shift_x;
	int collider_shift_y;
	Collider* collider; // collider of spell

	/// <summary>
	/// 0 false, 1 true AND it is drawn for the first time, 2 is partially death, but still in dying animation
	/// </summary>
	int crashed;

public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Spell"/> class.
	/// </summary>
	/// <param name="x">The x coordinate of the spell</param>
	/// <param name="y">The y coordinate of the spell</param>
	/// <param name="orientation">The orientation of the spell</param>
	/// <param name="spellID">The identifier of spell -> see Constants.h</param>
	Spell(float x, float y, int orientation, int spellID);

	/// <summary>
	/// Draws the spell
	/// </summary>
	void Draw() override;

	/// <summary>
	/// Moves the spell
	/// </summary>
	void Move() override;

	/// <summary>
	/// Finalizes an instance of the <see cref="Spell"/> class.
	/// </summary>
	~Spell() override;
};

