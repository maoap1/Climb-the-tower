#include "Animation.h"

void Animation::Init(vector<int> frameDelays)
{

	this->frameDelays = frameDelays;
	this->currentFrame = 0;
	this->currentSprite = 0;
	this->trivial = 0;
}

Animation::Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<int> frameDelays)
{
	this->sprites = sprites;
	Init(frameDelays);
	this->containsAttacks = 0;
}

Animation::Animation(vector<ALLEGRO_BITMAP*>* sprites, vector<ALLEGRO_BITMAP*>* attackSprites, vector<int> frameDelays)
{
	this->sprites = sprites;
	this->attackSprites = attackSprites;
	Init(frameDelays);
	this->containsAttacks = 1;
}

Animation::Animation(ALLEGRO_BITMAP* sprite)
{
	this->sprite = sprite;
	this->trivial = 1;
	this->containsAttacks = 0;
}

Animation::Animation(ALLEGRO_BITMAP* sprite, ALLEGRO_BITMAP* attackSprite)
{
	this->sprite = sprite;
	this->attackSprite = attackSprite;
	this->trivial = 1;
	this->containsAttacks = 1;
}


ALLEGRO_BITMAP* Animation::GetNext()
{
	return GetNext(0);
}


ALLEGRO_BITMAP * Animation::GetNext(int attacked)
{
	if (trivial)
	{
		if (attacked)
		{
			return attackSprite;
		}
		else
		{
			return sprite;
		}
	}
	if (currentFrame++ >= frameDelays[currentSprite])
	{
		currentFrame = 0;
		currentSprite = (currentSprite + 1) % (*sprites).size();
	}

	if ((!containsAttacks)||(!attacked))
	{
		return (*sprites)[currentSprite];
	}
	else
	{
		return (*attackSprites)[currentSprite];
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

}
