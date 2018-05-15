#pragma once
#include "Header.h"
#include "Damagable.h"

/// <summary>
/// This is a box collider
/// </summary>
class Collider
{
private:

	/// <summary>
	/// The parent of this collider
	/// </summary>
	Damagable* parent;

	/// <summary>
	/// The x coordinate of the top-left corner
	/// </summary>
	int x;

	/// <summary>
	/// The y coordinate of the top-left corner
	/// </summary>
	int y;

	/// <summary>
	/// The height of the collider
	/// </summary>
	int height;

	/// <summary>
	/// The width of the collider
	/// </summary>
	int width;

public:
	bool collided;

	/// <summary>
	/// string flag; you can store here the name of the owner of this collider -> for example "Player"
	/// default is empty string
	/// </summary>
	string flag;

	/// <summary>
	/// Initializes a new instance of the <see cref="Collider"/> class.
	/// </summary>
	/// <param name="x">The x coordinate of the top-left corner</param>
	/// <param name="y">The y coordinate of the top-left corner.</param>
	/// <param name="height">The height of the collider</param>
	/// <param name="width">The width of the collider</param>
	Collider(int x, int y, int height, int width, string flag = "", Damagable* parent = NULL);

	/// <summary>
	/// Finalizes an instance of the <see cref="Collider"/> class.
	/// </summary>
	~Collider();

	/// <summary>
	/// Determines whether the collider has collided with the other collider.
	/// </summary>
	/// <param name="other">The other collider.</param>
	/// <returns>
	///   <c>true</c> if the specified other collider has collided; otherwise, <c>false</c>.
	/// </returns>
	bool HasCollided(const Collider& other);

	void DamageParent(int damageType, int value);

	/// <summary>
	/// Sets the top-left corner
	/// </summary>
	/// <param name="x">X coordinate</param>
	/// <param name="y">Y coordinate</param>
	void SetXY(int x, int y);

#ifdef DEBUG
	/// <summary>
	/// Draws a rectangle representing this Collider
	/// </summary>
	/// <returns></returns>
	void Draw();
#endif // DEBUG

};

