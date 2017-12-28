#pragma once

#include "Header.h"

class Animation
{
private:
	vector<ALLEGRO_BITMAP*> sprites;
	vector<ALLEGRO_BITMAP*> attackSprites;
	vector<int> frameDelays;
	int attackDelay;
	int currentFrame;
	int currentSprite;
	int attackFrame;

	ALLEGRO_BITMAP* GetAttack();


public:
	Animation(vector<const char*> fileNames, vector<const char*> fileNamesAttacks, vector<int> frameDelays, int attackDelay);

	ALLEGRO_BITMAP* GetNext(); // this is public in case that something doesnt attack
	ALLEGRO_BITMAP* GetNext(bool* attacked);


	~Animation();
};

