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
public:
	Animation(vector<const char*> fileNames, vector<const char*> fileNamesAttacks, vector<int> frameDelays, int attackDelay);

	ALLEGRO_BITMAP* GetNext();
	ALLEGRO_BITMAP* GetAttack();

	~Animation();
};

