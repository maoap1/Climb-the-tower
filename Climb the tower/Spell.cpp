#include "Spell.h"
#include "GameMap.h"
#include "AnimationInitialization.h"


Spell::Spell(float x, float y, int orientation, int spellID) : ActiveGameObject(x, y)
{
	this->crashed = 0;
	this->orientation = orientation;
	this->spellID = spellID;

	int collider_width;
	int collider_height;

	switch (orientation) // for every orientation is needed specific collider
	{
	case ID_LEFT:
		collider_shift_x = 0;
		collider_shift_y = 11;
		collider_width = 50;
		collider_height = 27;
		break;
	case ID_UP:
		collider_shift_x = 14;
		collider_shift_y = 0;
		collider_width = 25;
		collider_height = 45;
		break;
	case ID_RIGHT:
		collider_shift_x = 6;
		collider_shift_y = 12;
		collider_width = 44;
		collider_height = 25;
		break;
	case ID_DOWN:
		collider_shift_x = 14;
		collider_shift_y = 5;
		collider_width = 25;
		collider_height = 44;
		break;
	}
	if (spellID != ID_SLIMEBALL) // creates collider for player spells
	{
		collider = new Collider(x + collider_shift_x, y + collider_shift_y, collider_height, collider_width, "Spell");
	}
	else // creates collider for enemy spell
	{
		collider = new Collider(x + collider_shift_x, y + collider_shift_y, collider_height, collider_width, "EnemySpell");
	}
	GameMap::Colliders.push_back(collider);

	// Now creates particular animations of the spell
	vector<int> MoveFrameDelays = { 6, 6, 6 };
	vector<int> DeathFrameDelays = { 6, 6, 6, 6, 6 };

	using namespace AnimationInitialization;

	switch (spellID)
	{
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
	case ID_WATERBLAST:
		switch (orientation)
		{
		case ID_LEFT:
			this->Moving = new Animation(&WaterblastLeft, MoveFrameDelays);
			this->Death = new Animation(&WaterblastDeathLeft, DeathFrameDelays);
			break;
		case ID_UP:
			this->Moving = new Animation(&WaterblastUp, MoveFrameDelays);
			this->Death = new Animation(&WaterblastDeathUp, DeathFrameDelays);
			break;
		case ID_RIGHT:
			this->Moving = new Animation(&WaterblastRight, MoveFrameDelays);
			this->Death = new Animation(&WaterblastDeathRight, DeathFrameDelays);
			break;
		case ID_DOWN:
			this->Moving = new Animation(&WaterblastDown, MoveFrameDelays);
			this->Death = new Animation(&WaterblastDeathDown, DeathFrameDelays);
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
	case ID_SLIMEBALL:
		switch (orientation)
		{
		case ID_LEFT:
			this->Moving = new Animation(&SlimeballLeft, MoveFrameDelays);
			this->Death = new Animation(&SlimeballDeathLeft, DeathFrameDelays);
			break;
		case ID_UP:
			this->Moving = new Animation(&SlimeballUp, MoveFrameDelays);
			this->Death = new Animation(&SlimeballDeathUp, DeathFrameDelays);
			break;
		case ID_RIGHT:
			this->Moving = new Animation(&SlimeballRight, MoveFrameDelays);
			this->Death = new Animation(&SlimeballDeathRight, DeathFrameDelays);
			break;
		case ID_DOWN:
			this->Moving = new Animation(&SlimeballDown, MoveFrameDelays);
			this->Death = new Animation(&SlimeballDeathDown, DeathFrameDelays);
			break;
		}
		break;
	}
}

void Spell::Draw()
{
	if (crashed == 1) // the spell has just crashed -> first phase of dying
	{
		GameMap::Movables.remove(this);
		GameMap::Colliders.remove(this->collider);
		delete collider;
		crashed = 2; // now enters phase 2
	}

	if (crashed == 2) // the spell is still beeing drawn with Death animation
	{

		bool end = false;
		ALLEGRO_BITMAP* bitmap = Death->GetNext(&end); // if it is the last bitmap, then end is true
		if (end)
		{
			GameMap::ToDeletion.push_back(this); // The spell is put for deletion
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
		return; // this should have been removed from Movables before this happens, but it is here for sure
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
		if ((it != collider)&&(it->flag != "Spell")&&(it->flag != "EnemySpell")) // checking only colliders of other non-spell objects
		{
			if (((collider->flag == "Spell") && (it->flag != "Player"))||((collider->flag == "EnemySpell") && (it->flag != "Enemy")))
			// If enemy spell, it collides with the player. If player spell, it collides with the enemy			
			{
				// check for collision
				if (collider->HasCollided(*it))
				{
					if ((it->flag == "Player")||(it->flag == "Enemy"))
					{
						it->collided = true;
						it->DamageParent(spellID, spellDamage);
					}
					crashed = 1; // the spell crashed and goes to the first phase of dying
					collider->SetXY(x + collider_shift_x, y + collider_shift_y); // returns collider back
					return;
				}
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
}
