#pragma once

#include "Header.h"

/// <summary>
/// In this namespace are all animations initialized
/// It just load a lot of images to the memory (into vectors) so that animations can easily work with them
/// Mostly generated automatically. Where needed, there is a documentation of what do those names mean
/// </summary>
namespace AnimationInitialization
{
#pragma region Player
	extern vector<ALLEGRO_BITMAP*> PlayerLeft;
	extern vector<ALLEGRO_BITMAP*> PlayerLeftAttack;
	extern vector<ALLEGRO_BITMAP*> PlayerRight;
	extern vector<ALLEGRO_BITMAP*> PlayerRightAttack;
	extern vector<ALLEGRO_BITMAP*> PlayerUp;
	extern vector<ALLEGRO_BITMAP*> PlayerUpAttack;
	extern vector<ALLEGRO_BITMAP*> PlayerDown;
	extern vector<ALLEGRO_BITMAP*> PlayerDownAttack;

	extern ALLEGRO_BITMAP* PlayerUpIdle;
	extern ALLEGRO_BITMAP* PlayerUpIdleAttack;
	extern ALLEGRO_BITMAP* PlayerDownIdle;
	extern ALLEGRO_BITMAP* PlayerDownIdleAttack;
#pragma endregion

#pragma region Slime
	extern vector<ALLEGRO_BITMAP*> Slime;
	extern vector<ALLEGRO_BITMAP*> SlimeAttack;
#pragma endregion

#pragma region Spell movements
	extern vector<ALLEGRO_BITMAP*> FireballLeft;
	extern vector<ALLEGRO_BITMAP*> FireballUp;
	extern vector<ALLEGRO_BITMAP*> FireballRight;
	extern vector<ALLEGRO_BITMAP*> FireballDown;

	extern vector<ALLEGRO_BITMAP*> WaterblastLeft;
	extern vector<ALLEGRO_BITMAP*> WaterblastUp;
	extern vector<ALLEGRO_BITMAP*> WaterblastRight;
	extern vector<ALLEGRO_BITMAP*> WaterblastDown;

	extern vector<ALLEGRO_BITMAP*> ArcaneballLeft;
	extern vector<ALLEGRO_BITMAP*> ArcaneballUp;
	extern vector<ALLEGRO_BITMAP*> ArcaneballRight;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDown;

	extern vector<ALLEGRO_BITMAP*> SlimeballLeft;
	extern vector<ALLEGRO_BITMAP*> SlimeballUp;
	extern vector<ALLEGRO_BITMAP*> SlimeballRight;
	extern vector<ALLEGRO_BITMAP*> SlimeballDown;
#pragma endregion

#pragma region Spell deaths
	extern vector<ALLEGRO_BITMAP*> FireballDeathLeft;
	extern vector<ALLEGRO_BITMAP*> FireballDeathUp;
	extern vector<ALLEGRO_BITMAP*> FireballDeathRight;
	extern vector<ALLEGRO_BITMAP*> FireballDeathDown;

	extern vector<ALLEGRO_BITMAP*> WaterblastDeathLeft;
	extern vector<ALLEGRO_BITMAP*> WaterblastDeathUp;
	extern vector<ALLEGRO_BITMAP*> WaterblastDeathRight;
	extern vector<ALLEGRO_BITMAP*> WaterblastDeathDown;

	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathLeft;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathUp;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathRight;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathDown;

	extern vector<ALLEGRO_BITMAP*> SlimeballDeathLeft;
	extern vector<ALLEGRO_BITMAP*> SlimeballDeathUp;
	extern vector<ALLEGRO_BITMAP*> SlimeballDeathRight;
	extern vector<ALLEGRO_BITMAP*> SlimeballDeathDown;
#pragma endregion

	/// <summary>
	/// This function calls all the others in this namespace
	/// </summary>
	void AnimInit();
}