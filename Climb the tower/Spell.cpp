#include "Spell.h"


#pragma region Animations

#define MOVE_ANIMATION_LENGTH 3
#define DEATH_ANIMATION_LENGTH 5

typedef const char* moveFileNames[4][MOVE_ANIMATION_LENGTH];
typedef const char* deathFileNames[4][DEATH_ANIMATION_LENGTH];

moveFileNames fireballFileNames =
{
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Left
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Up
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Right
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Down
};

deathFileNames fireballDeathFileNames =
{
	{ "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	  "Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Left
	  { "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	  "Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Up
	  { "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	  "Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Right
	  { "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	  "Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Down
};
#pragma endregion


Spell::Spell(float x, float y, int orientation, int spellID) : ActiveGameObject(x, y)
{
	this->orientation = orientation;
	this->spellID = spellID;

	moveFileNames* specificMoveFileNames = NULL;
	deathFileNames* specificDeathFileNames = NULL;
	switch (spellID)
	{
	case ID_MISSILE:
		break;
	case ID_FIREBALL:
		specificMoveFileNames = &fireballFileNames;
		specificDeathFileNames = &fireballDeathFileNames;
		break;
	}
#pragma region Moving animation
	vector<int> frameDelays = {6, 6, 6};
	vector<const char*> fileNames;

	for (int i = 0; i < MOVE_ANIMATION_LENGTH; i++)
	{
		fileNames.push_back((*specificMoveFileNames)[orientation][i]);
	}

	this->Moving = new Animation(fileNames, frameDelays, FIREBALL_SIZE, FIREBALL_SIZE);
#pragma endregion

#pragma region Death animation
	frameDelays = { 8, 8, 8, 8, 8 };
	fileNames.clear();
	for (int i = 0; i < DEATH_ANIMATION_LENGTH; i++)
	{
		fileNames.push_back((*specificDeathFileNames)[orientation][i]);
	}
	this->Death = new Animation(fileNames, frameDelays, FIREBALL_SIZE, FIREBALL_SIZE);
#pragma endregion

	frameDelays.~vector();
	fileNames.~vector();
}

void Spell::Draw()
{
	al_draw_bitmap(Moving->GetNext(0), x, y, 0);
}

void Spell::Move()
{

}

void Spell::SetMe(Spell* me)
{
	this->me = me;
}

Spell::~Spell()
{
	Moving->~Animation();
	Death->~Animation();
}
