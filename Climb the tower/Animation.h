#pragma once

#include "Header.h"
#include "AllegroHandling.h"

class Animation
{
private:
	vector<ALLEGRO_BITMAP*> sprites;
	vector<ALLEGRO_BITMAP*> attackSprites;
	vector<int> frameDelays;
	int currentFrame;
	int currentSprite;
	int containsAttacks;

	void Init(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height);


public:
	Animation(vector<const char*> fileNames, vector<const char*> fileNamesAttacks, vector<int> frameDelays, float image_width, float image_height);
	Animation(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height);

	ALLEGRO_BITMAP* GetNext(int attacked);


	~Animation();
};

