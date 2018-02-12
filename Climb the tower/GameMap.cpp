#include "GameMap.h"
#include "Header.h"
#include "Objects.h"

namespace GameMap
{
	list<GameObject*> ToDeletion;
	list<GameObject*> Drawables;
	list<ActiveGameObject*> Movables;
	list<Collider*> Colliders;

	void FirstGameMapInicialization(int map_width, int map_height)
	{

		int eastern_wall_x = WALL_SIZE*(map_width - 1);
		int southern_wall_y = WALL_SIZE*(map_height - 1);

		for (int i = 0; i < map_width; i++)
		{
			Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, 0));					// Northern wall
			Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, southern_wall_y));		// Southern wall
		}
		for (int i = 1; i < map_height - 1; i++)
		{
			Drawables.push_back(new Wall("Resources/image.png", 0, WALL_SIZE*i));					// Western wall
			Drawables.push_back(new Wall("Resources/image.png", eastern_wall_x, WALL_SIZE*i));		// Eastern wall
		}

		//Walls:
		Colliders.push_back(new Collider(0, 0, map_height*WALL_SIZE, WALL_SIZE));							// Western wall
		Colliders.push_back(new Collider(WALL_SIZE, 0, WALL_SIZE, map_width*WALL_SIZE));						// Northern wall
		Colliders.push_back(new Collider(eastern_wall_x, WALL_SIZE, map_height*WALL_SIZE, WALL_SIZE));		// Eastern wall
		Colliders.push_back(new Collider(WALL_SIZE, southern_wall_y, WALL_SIZE, map_width*WALL_SIZE));		// Southern wall

	}

	void CreateSpell(float x, float y, int orientation, int spellID)
	{
		Spell* spell = new Spell(x, y, orientation, spellID);
		Movables.push_back(spell);
		Drawables.push_back(spell);
	}

	void DeleteMe(ActiveGameObject* sender)
	{
		Drawables.remove(sender); // this shouldnt be ok, there should be some BUG
		Movables.remove(sender); // this should call destructor -> test it!!!
		//sender->~ActiveGameObject();
	}
}