#pragma once
#include "Header.h"
#include "GameObject.h"
#include "ActiveGameObject.h"
#include "Collider.h"

namespace GameMap
{
	extern list<GameObject*> ToDeletion;
	extern list<GameObject*> Drawables;
	extern list<ActiveGameObject*> Movables;
	extern list<Collider*> Colliders;

	extern vector<vector<int>> Map;


	void FirstGameMapInicialization(int map_width, int map_height);
	void CreateSpell(float x, float y, int orientation, int spellID);
	void CreateEnemy(float x, float y);
	void RandomEmptyPosition(float& x, float& y);


}