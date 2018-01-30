#include "Animation.h"


void Animation::Init(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height)
{
	for each (const char* filename in fileNames)
	{
		sprites.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
	}

	this->frameDelays = frameDelays;
	currentFrame = 0;
	currentSprite = 0;
	started = false;
}

Animation::Animation(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height)
{
	Init(fileNames, frameDelays, image_width, image_height);
	this->containsAttacks = 0;
}

Animation::Animation(vector<const char*> fileNames,vector<const char*> fileNamesAttacks, vector<int> frameDelays, float image_width, float image_height)
{

	Init(fileNames, frameDelays, image_width, image_height);
	this->containsAttacks = 1;

	for each (const char* attack_file_name in fileNamesAttacks)
	{
		attackSprites.push_back(AllegroHandling::load_resized_bitmap(attack_file_name,image_width, image_height));
	}

}

ALLEGRO_BITMAP* Animation::GetNext()
{
	return GetNext(0);
}


ALLEGRO_BITMAP * Animation::GetNext(int attacked)
{
	if (currentFrame++ >= frameDelays[currentSprite])
	{
		currentFrame = 0;
		currentSprite = (currentSprite + 1) % sprites.size();
	}

	if ((!containsAttacks)||(!attacked))
	{
		return sprites[currentSprite];
	}
	else
	{
		return attackSprites[currentSprite];
	}
}

ALLEGRO_BITMAP* Animation::GetNext(bool* isEnd)
{
	if ((started) && (currentFrame == 0)&& (currentSprite == 0))
	{
		*isEnd = true;
	}
	else
	{
		started = true;
		*isEnd = false;
	}

	return GetNext(0);
}


Animation::~Animation()
{
}
