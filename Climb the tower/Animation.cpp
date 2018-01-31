#include "Animation.h"


void Animation::Init(vector<const char*> fileNames, vector<int> frameDelays, float image_width, float image_height)
{
	for each (const char* filename in fileNames)
	{
		sprites.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		/* DESTROYMENT DEBUGGING
		sprites2.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites3.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites4.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites5.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites6.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites7.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites8.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		sprites9.push_back(AllegroHandling::load_resized_bitmap(filename, image_width, image_height));
		*/
	}

	this->frameDelays = frameDelays;
	currentFrame = 0;
	currentSprite = 0;
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
	ALLEGRO_BITMAP* bitmap = GetNext(0);
	if ((currentFrame == 0) && (currentSprite == 0))
	{
		*isEnd = true;
	}
	else
	{
		*isEnd = false;
	}

	return bitmap;
}


Animation::~Animation()
{
	// DESTROY!!! ALLEGRO_BITMAPs from this animation!!!
}
