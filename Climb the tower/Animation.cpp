#include "Animation.h"

Animation::Animation(vector<const char*> fileNames,vector<const char*> fileNamesAttacks, vector<int> frameDelays, int attackDelay)
{
	for each (const char* filename in fileNames)
	{
		sprites.push_back(al_load_bitmap(filename));
	}
	for each (const char* attack_file_name in fileNamesAttacks)
	{
		attackSprites.push_back(al_load_bitmap(attack_file_name));
	}
	this->frameDelays = frameDelays;
	currentFrame = 0;
	currentSprite = 0;
	this->attackDelay = attackDelay;
	attackFrame = -1;

}

ALLEGRO_BITMAP* Animation::GetNext()
{
	if (currentFrame++ >= frameDelays[currentSprite])
	{
		currentFrame = 0;
		currentSprite = (currentSprite + 1) % sprites.size();
	}
	if (attackFrame > 0)
	{
		if (attackFrame++ >= attackDelay)
		{
			attackFrame = 0;
		}
		return attackSprites[currentSprite];
	}
	return sprites[currentSprite];
}

ALLEGRO_BITMAP * Animation::GetNext(bool* attacked)
{
	if (*attacked)
	{
		if (attackFrame == -1)
		{
			return GetAttack();
		}
		else if (attackFrame == 0)
		{
			*attacked = false;
			attackFrame = -1;
		}
		return GetNext();
	}
	else
	{
		return GetNext();
	}
}

ALLEGRO_BITMAP* Animation::GetAttack()
{
	attackFrame = 1;
	return attackSprites[currentSprite];
}


Animation::~Animation()
{
}
