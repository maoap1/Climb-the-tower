#pragma once
#include "Header.h"
#include "GameObject.h"
#include "ActiveGameObject.h"
#include "Collider.h"

namespace GameMap
{

	extern list<GameObject*> Drawables;
	extern list<ActiveGameObject*> Movables;
	extern list<Collider*> Colliders;

	void FirstGameMapInicialization(int map_width, int map_height);
	void CreateSpell(float x, float y, int orientation, int spellID);
	void DeleteMe(GameObject* sender);
}