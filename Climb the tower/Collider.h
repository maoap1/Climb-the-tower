#pragma once
#include "Header.h"
class Collider // this is a box collider
{
private:
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
	string flag;

	/// <summary>
	/// Initializes a new instance of the <see cref="Collider"/> class.
	/// </summary>
	/// <param name="x">The x coordinate of the top-left corner</param>
	/// <param name="y">The y coordinate of the top-left corner.</param>
	/// <param name="height">The height of the collider</param>
	/// <param name="width">The width of the collider</param>
	Collider(int x, int y, int height, int width, string flag = "");

	/// <summary>
	/// Finalizes an instance of the <see cref="Collider"/> class.
	/// </summary>
	~Collider();

	//friend -> would it be friend or not?
	bool HasCollided(const Collider& other);

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

