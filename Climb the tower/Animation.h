#pragma once

#include "Header.h"
#include "AllegroHandling.h"

/// <summary>
/// This is the animation class. It stores the pointer to vector of bitmaps created in AnimationInicialization.h.
/// This class returns the actual pointer to bitmap which should be drawn, according to the actual animation.
/// The animation can contain attacks, and these animations follow the non-attack animation.
/// </summary>
class Animation
{
private:
	/// <summary>
	/// The vector of sprites
	/// </summary>
	vector<ALLEGRO_BITMAP*>* sprites;

	/// <summary>
	/// The vector of attack sprites
	/// </summary>
	vector<ALLEGRO_BITMAP*>* attackSprites;

	/// <summary>
	/// The only one sprite
	/// </summary>
	ALLEGRO_BITMAP* sprite;

	/// <summary>
	/// The only one attack sprite
	/// </summary>
	ALLEGRO_BITMAP* attackSprite;

	/// <summary>
	/// Vector of delays between changes of sprites
	/// </summary>
	vector<int> frameDelays;

	/// <summary>
	/// The current frame of the sprite.
	/// Determines how many times was the actual sprite viewed
	/// </summary>
	int currentFrame;

	/// <summary>
	/// The position in vectors of the current sprite.
	/// </summary>
	int currentSprite;

	/// <summary>
	/// 1 if contains, 0 if not
	/// </summary>
	int containsAttacks;

	/// <summary>
	/// 1 if doesn't contain vector of sprites (this is trivial animation)
	/// 0 if it is classical animation (contains vector of sprites)
	/// </summary>
	int trivial;

	/// <summary>
	/// Initializes animation class
	/// </summary>
	/// <param name="frameDelays">Frame delays</param>
	void Init(vector<int> frameDelays);

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Animation"/> class. Doesn't include attacks.
	/// </summary>
	/// <param name="sprites">Vector of bitmaps of sprites.</param>
	/// <param name="frameDelays">Vector of delays between changes of sprites</param>
	Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<int> frameDelays);

	/// <summary>
	/// Initializes a new instance of the <see cref="Animation"/> class. Includes attacks.
	/// </summary>
	/// <param name="sprites">Vector of bitmaps of sprites.</param>
	/// <param name="attackSprites">Vector of bitmaps of attack sprites.</param>
	/// <param name="frameDelays">Vector of delays between changes of sprites</param>
	Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<ALLEGRO_BITMAP*>* attackSprites, vector<int> frameDelays);


	/// <summary>
	/// Initializes a new instance of the <see cref="Animation"/> class.
	/// Includes only one sprite (i.e. for "idle" animations)
	/// </summary>
	/// <param name="sprite">The only one bitmap</param>
	Animation(ALLEGRO_BITMAP* sprite);

	/// <summary>
	/// Initializes a new instance of the <see cref="Animation"/> class.
	/// Includes only one sprite for normal state and one sprite for attack state. (suitable i.e. for "idle" animations)
	/// </summary>
	/// <param name="sprite">The sprite.</param>
	/// <param name="AttackSprite">The attack sprite.</param>
	Animation(ALLEGRO_BITMAP* sprite, ALLEGRO_BITMAP* AttackSprite);

	/// <summary>
	/// Returns next bitmap of the animation
	/// </summary>
	/// <returns></returns>
	ALLEGRO_BITMAP* GetNext();

	/// <summary>
	/// Returns next bitmap of the animation that includes attacks.
	/// </summary>
	/// <param name="attacked"> 0 for return of the next non-attacking bitmap, anything else (i.e. 1) for attacking bitmap.</param>
	/// <returns></returns>
	ALLEGRO_BITMAP* GetNext(int attacked);

	/// <summary>
	/// Returns next bitmap of the animation.
	/// Suitable especially for Death animations.
	/// </summary>
	/// <param name="isEnd">Returns, whether the animation has ended or not.</param>
	/// <returns></returns>
	ALLEGRO_BITMAP* GetNext(bool* isEnd);


	/// <summary>
	/// Randomizes actual sprite
	/// </summary>
	void Randomize();


	/// <summary>
	/// Finalizes an instance of the <see cref="Animation"/> class.
	/// </summary>
	~Animation();
};

