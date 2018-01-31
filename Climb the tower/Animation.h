#pragma once

#include "Header.h"
#include "AllegroHandling.h"

class Animation
{
private:
	vector<ALLEGRO_BITMAP*> sprites;

	/* Destroyment DEBUGGING
	vector<ALLEGRO_BITMAP*> sprites2;
	vector<ALLEGRO_BITMAP*> sprites3;
	vector<ALLEGRO_BITMAP*> sprites4;
	vector<ALLEGRO_BITMAP*> sprites5;
	vector<ALLEGRO_BITMAP*> sprites6;
	vector<ALLEGRO_BITMAP*> sprites7;
	vector<ALLEGRO_BITMAP*> sprites8;
	vector<ALLEGRO_BITMAP*> sprites9;
	*/

	vector<ALLEGRO_BITMAP*> attackSprites;
	vector<int> frameDelays;
	int currentFrame;
	int currentSprite;
	int containsAttacks;

	void Init(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height);


public:
	Animation(vector<const char*> fileNames, vector<const char*> fileNamesAttacks, vector<int> frameDelays, float image_width, float image_height);
	Animation(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height);

	ALLEGRO_BITMAP* GetNext();
	ALLEGRO_BITMAP* GetNext(int attacked);
	ALLEGRO_BITMAP* GetNext(bool* isEnd);

	~Animation();
};

