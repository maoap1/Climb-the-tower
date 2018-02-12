#pragma once

#include "Header.h"

namespace AnimationInitialization
{
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
#pragma endregion

	void AnimInit();
}