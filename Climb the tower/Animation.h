#pragma once

#include "Header.h"
#include "AllegroHandling.h"


//#include <memory>
//
//class Deleter
//{
//public:
//
//	void operator()(ALLEGRO_BITMAP* ptrToBitmap)
//	{
//		al_destroy_bitmap(ptrToBitmap);
//	}
//};


class Animation
{
private:
	//vector<unique_ptr<ALLEGRO_BITMAP, Deleter>> sprites;
	vector<ALLEGRO_BITMAP*> sprites;
	//vector<unique_ptr<ALLEGRO_BITMAP, Deleter>> attackSprites;
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

