#pragma once

#include "Header.h"
#include "AllegroHandling.h"

class Animation
{
private:
	vector<ALLEGRO_BITMAP*>* sprites;
	vector<ALLEGRO_BITMAP*>* attackSprites;
	ALLEGRO_BITMAP* sprite;
	ALLEGRO_BITMAP* attackSprite;

	vector<int> frameDelays;
	int currentFrame;
	int currentSprite;
	int containsAttacks;
	int trivial;

	void Init(vector<int> frameDelays);

public:
	Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<int> frameDelays);
	Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<ALLEGRO_BITMAP*>* attackSprites, vector<int> frameDelays);
	Animation(ALLEGRO_BITMAP* sprite);
	Animation(ALLEGRO_BITMAP* sprite, ALLEGRO_BITMAP* AttackSprite);

	ALLEGRO_BITMAP* GetNext();
	ALLEGRO_BITMAP* GetNext(int attacked);
	ALLEGRO_BITMAP* GetNext(bool* isEnd);

	~Animation();
};

