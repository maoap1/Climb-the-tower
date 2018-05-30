#pragma once

#include "Header.h"
#include "Animation.h"
#include "Collider.h"
#include "Spell.h"
#include "Damagable.h"




/// <summary>
/// This is the player class. The player plays with this character.
/// </summary>
/// <seealso cref="GameObject" />
/// <seealso cref="Damagable" />
class Player : public GameObject, public Damagable
{
private:
	const int speed = PLAYER_SPEED;
	int attackAnimDelay = PLAYER_INIT_ATTACK_ANIM_DELAY; // the minimum of attackDelay ever
	int attackDelay = PLAYER_INIT_ATTACK_DELAY; // podle me se bude zlepsovat s levelem
	
	Animation* RunLeft;
	Animation* RunRight;
	Animation* RunUp;
	Animation* RunDown;
	Animation* IdleLeft;
	Animation* IdleRight;
	Animation* IdleUp;
	Animation* IdleDown;
	/// <summary>
	/// The outer collider, immune to spells, for colliding with walls etc.
	/// </summary>
	Collider* collider;
	/// <summary>
	/// The collider for colliding with spells
	/// </summary>
	Collider* spellCollider;

	int lastDirection; // it tells us which direction do we need to draw
	bool moreDirections;

	bool attacked;
	bool animAttacked;
	int currentAttackFrame;
	float lives;

	/// <summary>
	/// Moves in the specified direction.
	/// </summary>
	/// <param name="direction">The direction to move</param>
	void Move(int direction);
	
public:

	/// <summary>
	/// true if the player already moved
	/// </summary>
	bool moved;

	/// <summary>
	/// true if the player is still alive
	/// </summary>
	bool living;

	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="x">The x coordinate</param>
	/// <param name="y">The y coordinate</param>
	/// <param name="lives">Maximum lives for this character</param>
	Player(float x, float y, float lives);

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

	/// <summary>
	/// Tells the player that he is going to more than one direction
	/// </summary>
	/// <param name="moreDirections">if set to <c>true</c> [more directions].</param>
	void MoreDirections(bool moreDirections);

	/// <summary>
	/// Creates spell as attack, if player can.
	/// </summary>
	/// <param name="spellID">ID of the spell -> see Constants.h</param>
	void Attack(int spellID);

	/// <summary>
	/// Damages the player
	/// </summary>
	/// <param name="damageType">Type of the damage.</param>
	/// <param name="value">How much damage.</param>
	void Damage(int damageType, int value) override;

	/// <summary>
	/// Returns x coordinate of the player
	/// </summary>
	/// <returns></returns>
	float Get_x();

	/// <summary>
	/// Returns y coordinate of the player
	/// </summary>
	/// <returns></returns>
	float Get_y();

	/// <summary>
	/// Finalizes an instance of the <see cref="Player"/> class.
	/// </summary>
	~Player() override;
};

