#include "Spell.h"
#include "GameMap.h"
#include "AnimationInitialization.h"


Spell::Spell(float x, float y, int orientation, int spellID) : ActiveGameObject(x, y)
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
		collider_shift_x = 0;
		collider_shift_y = 0;
		collider_width = 10;
		collider_height = 5;
		break;
	case ID_RIGHT:
		collider_shift_x = 70;
		collider_shift_y = 0;
		collider_width = 5;
		collider_height = 10;
		break;
	case ID_DOWN:
		collider_shift_x = 0;
		collider_shift_y = 0;
		collider_width = 10;
		collider_height = 5;
		break;
	}

	collider = new Collider(x + collider_shift_x, y + collider_shift_y, collider_height, collider_height, "Spell");
	GameMap::Colliders.push_back(collider);

	// THIS only for spells!
	vector<int> MoveFrameDelays = { 6, 6, 6 };
	vector<int> DeathFrameDelays = { 8, 8, 8, 8, 8 };
	// end of THIS

	using namespace AnimationInitialization;

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
		switch (orientation)
		{
		case ID_LEFT:
			this->Moving = new Animation(&FireballLeft, MoveFrameDelays);
			this->Death = new Animation(&FireballDeathLeft, DeathFrameDelays);
			break;
		case ID_UP:
			this->Moving = new Animation(&FireballUp, MoveFrameDelays);
			this->Death = new Animation(&FireballDeathUp, DeathFrameDelays);
			break;
		case ID_RIGHT:
			this->Moving = new Animation(&FireballRight, MoveFrameDelays);
			this->Death = new Animation(&FireballDeathRight, DeathFrameDelays);
			break;
		case ID_DOWN:
			this->Moving = new Animation(&FireballDown, MoveFrameDelays);
			this->Death = new Animation(&FireballDeathDown, DeathFrameDelays);
			break;
		}
		break;
	case ID_FROSTBALL:
		switch (orientation)
		{
		case ID_LEFT:
			this->Moving = new Animation(&FrostballLeft, MoveFrameDelays);
			this->Death = new Animation(&FrostballDeathLeft, DeathFrameDelays);
			break;
		case ID_UP:
			this->Moving = new Animation(&FrostballUp, MoveFrameDelays);
			this->Death = new Animation(&FrostballDeathUp, DeathFrameDelays);
			break;
		case ID_RIGHT:
			this->Moving = new Animation(&FrostballRight, MoveFrameDelays);
			this->Death = new Animation(&FrostballDeathRight, DeathFrameDelays);
			break;
		case ID_DOWN:
			this->Moving = new Animation(&FrostballDown, MoveFrameDelays);
			this->Death = new Animation(&FrostballDeathDown, DeathFrameDelays);
			break;
		}
		break;
	case ID_ARCANEBALL:
		switch (orientation)
		{
		case ID_LEFT:
			this->Moving = new Animation(&ArcaneballLeft, MoveFrameDelays);
			this->Death = new Animation(&ArcaneballDeathLeft, DeathFrameDelays);
			break;
		case ID_UP:
			this->Moving = new Animation(&ArcaneballUp, MoveFrameDelays);
			this->Death = new Animation(&ArcaneballDeathUp, DeathFrameDelays);
			break;
		case ID_RIGHT:
			this->Moving = new Animation(&ArcaneballRight, MoveFrameDelays);
			this->Death = new Animation(&ArcaneballDeathRight, DeathFrameDelays);
			break;
		case ID_DOWN:
			this->Moving = new Animation(&ArcaneballDown, MoveFrameDelays);
			this->Death = new Animation(&ArcaneballDeathDown, DeathFrameDelays);
			break;
		}
		break;
	}
}

void Spell::Draw()
{
	if (crashed == 1)
	{
		GameMap::Movables.remove(this);
		GameMap::Colliders.remove(this->collider);
		delete collider;
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
	for each (Collider* it in GameMap::Colliders)
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
