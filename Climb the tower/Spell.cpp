#include "Spell.h"


#pragma region Animations


vector<const char*> fileNamesLeft;
vector<const char*> fileNamesTop;
vector<const char*> fileNamesRight;
vector<const char*> fileNamesDown;

vector<const char*> fileNamesDeathLeft;
vector<const char*> fileNamesDeathTop;
vector<const char*> fileNamesDeathRight;
vector<const char*> fileNamesDeathDown;

#pragma endregion


Spell::Spell(float x, float y, int orientation, int spellID) : ActiveGameObject(x, y)
{
	this->orientation = orientation;
	this->spellID = spellID;
}

void Spell::Draw()
{

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
