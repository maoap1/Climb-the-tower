#include "Spell.h"
#include "SpellAnimationDatabase.h"
#include "GameMap.h"
#include "AnimationInitialization.h"


Spell::Spell(float x, float y, int orientation, int spellID, list<Collider*>* Colliders) : ActiveGameObject(x, y)
{
	this->crashed = 0;
	this->orientation = orientation;
	this->spellID = spellID;

	bool isMissile;
	switch (spellID)
	{
	case ID_ARCANE_MISSILE:
	case ID_SLIME_BALL:
	case ID_MUD_BALL:
	case ID_SNOW_BALL:
		isMissile = true;
		break;
	default:
		isMissile = false;
		break;
	}

	int collider_width;
	int collider_height;

	switch (orientation)
	{
	case ID_LEFT:
		collider_shift_x = 0;
		collider_shift_y = 0;
		collider_width = 5;
		collider_height = 10;
		break;
	case ID_UP:
		break;
	case ID_RIGHT:
		break;
	case ID_DOWN:
		break;
	default:
		collider_shift_x = 0;
		collider_shift_y = 0;
		collider_width = 5;
		collider_height = 10;
		break;
	}

	collider = new Collider(x + collider_shift_x, y + collider_shift_y, collider_height, collider_height, "Spell");
	this->Colliders = Colliders;
	this->Colliders->push_back(collider); // DONT FORGET TO REMOVE HIM AFTER DEATH!

	moveFileNames* specificMoveFileNames = NULL;
	deathFileNames* specificDeathFileNames = NULL;
	switch (spellID)
	{

	case ID_ARCANE_MISSILE:
		break;
	case ID_SLIME_BALL:
		break;
	case ID_MUD_BALL:
		break;
	case ID_SNOW_BALL:
	break;
	case ID_FIREBALL:
		specificMoveFileNames = &fireballFileNames;
		specificDeathFileNames = &fireballDeathFileNames;
		break;
	case ID_FROSTBOLT:
		break;
	case ID_DEATH_BALL:
		break;
	case ID_ARCANE_SPELL:
		break;
	}
#pragma region Moving animation
	vector<int> frameDelays = {6, 6, 6};
	vector<const char*> fileNames;

	for (int i = 0; i < MOVE_ANIMATION_LENGTH; i++)
	{
		fileNames.push_back((*specificMoveFileNames)[orientation][i]);
	}

	//this->Moving = new Animation(fileNames, frameDelays, FIREBALL_SIZE, FIREBALL_SIZE);
	this->Moving = new Animation(&AnimationInitialization::FireballLeft, frameDelays);
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
	if (crashed == 1)
	{
		GameMap::Movables.remove(this);
		GameMap::Colliders.remove(this->collider);
		collider->~Collider();
		crashed = 2;
	}

	if (crashed == 2)
	{

		bool end = false;
		ALLEGRO_BITMAP* bitmap = Death->GetNext(&end);
		if (end)
		{
			GameMap::ToDeletion.push_back(this);
		}
		else
		{
			al_draw_bitmap(bitmap, x, y, 0);
		}
	}
	else
	{
		al_draw_bitmap(Moving->GetNext(), x, y, 0);
	}
}

void Spell::Move()
{
	if (crashed)
	{
		return; // this should have been removed from Movables before this happens
	}
	int xNew = x;
	int yNew = y;
	switch (orientation)
	{
	case ID_LEFT:
		xNew -= speed;
		break;
	case ID_UP:
		yNew -= speed;
		break;
	case ID_RIGHT:
		xNew += speed;
		break;
	case ID_DOWN:
		yNew += speed;
		break;
	default:
		break;
	}
	collider->SetXY(xNew + collider_shift_x, yNew + collider_shift_y); // check the new location for collisions
	for each (Collider* it in *Colliders)
	{
		if (it->flag != "Spell")
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				crashed = 1;
				collider->SetXY(x + collider_shift_x, y + collider_shift_y);
				return;
			}
		}
	}
	// if collision didnt occur
	x = xNew;
	y = yNew;
}

Spell::~Spell()
{
	delete Moving;
	delete Death;
	//Moving->~Animation();
	//Death->~Animation();
}
