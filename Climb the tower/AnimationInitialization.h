#pragma once

#include "Header.h"

namespace AnimationInitialization
{
#pragma region Spell movements
	extern vector<ALLEGRO_BITMAP*> FireballLeft;
	extern vector<ALLEGRO_BITMAP*> FireballUp;
	extern vector<ALLEGRO_BITMAP*> FireballRight;
	extern vector<ALLEGRO_BITMAP*> FireballDown;

	extern vector<ALLEGRO_BITMAP*> FrostballLeft;
	extern vector<ALLEGRO_BITMAP*> FrostballUp;
	extern vector<ALLEGRO_BITMAP*> FrostballRight;
	extern vector<ALLEGRO_BITMAP*> FrostballDown;

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

	extern vector<ALLEGRO_BITMAP*> FrostballDeathLeft;
	extern vector<ALLEGRO_BITMAP*> FrostballDeathUp;
	extern vector<ALLEGRO_BITMAP*> FrostballDeathRight;
	extern vector<ALLEGRO_BITMAP*> FrostballDeathDown;

	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathLeft;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathUp;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathRight;
	extern vector<ALLEGRO_BITMAP*> ArcaneballDeathDown;
#pragma endregion

	void AnimInit();
}