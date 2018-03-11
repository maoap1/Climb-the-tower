#include "GameMap.h"
#include "Header.h"
#include "Objects.h"
#include "Player.h"
#include "Enemy.h"

namespace GameMap
{
	list<GameObject*> ToDeletion;
	list<GameObject*> Drawables;
	list<ActiveGameObject*> Movables;
	list<Collider*> Colliders;

	/// <summary>
	/// The game map. Stores 0 for empty space, -1 for walls;  
	/// Imagine we would like to work with Map[i][j].  
	/// Then coordinates of top left corner of this are:
	/// x = (j + 1)*WALL_SIZE;
	/// y = (i + 1)*WALL_SIZE;
	/// </summary>
	vector<vector<int>> Map;
	int Map_height;
	int Map_width;

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
		Colliders.push_back(new Collider(WALL_SIZE, 0, WALL_SIZE, map_width*WALL_SIZE));					// Northern wall
		Colliders.push_back(new Collider(eastern_wall_x, WALL_SIZE, map_height*WALL_SIZE, WALL_SIZE));		// Eastern wall
		Colliders.push_back(new Collider(WALL_SIZE, southern_wall_y, WALL_SIZE, map_width*WALL_SIZE));		// Southern wall


		Map_height = map_height - 2;
		Map_width = map_width - 2;

		Map.resize(Map_height);
		for (int i = 0; i < Map_height; i++)
			Map[i].resize(Map_width);

		for (int i = 0; i < Map_height; i++)
		{
			for (int j = 0; j < Map_width; j++)
			{
				Map[i][j] = 0;
			}
		}

		Map[3][5] = 1;
		Map[3][6] = 1;
		Map[3][7] = 1;
		Map[4][6] = 1;
		Map[5][6] = 1;
		Map[6][6] = 1;

		for (int i = 0; i < Map_height; i++)
		{
			for (int j = 0; j < Map_width; j++)
			{
				if (Map[i][j] == 1)
				{
					Drawables.push_back(new Wall("Resources/image.png", (j + 1)*WALL_SIZE, (i + 1)*WALL_SIZE));
					Colliders.push_back(new Collider((j + 1)*WALL_SIZE, (i + 1)*WALL_SIZE, WALL_SIZE, WALL_SIZE));
				}
			}
		}

	}

	void CreateSpell(float x, float y, int orientation, int spellID)
	{
		Spell* spell = new Spell(x, y, orientation, spellID);
		Movables.push_back(spell);
		Drawables.push_back(spell);
	}

	void CreateEnemy(float x, float y, int orientation)
	{
		Enemy* enemy = new Enemy(x, y, orientation);
		Movables.push_back(enemy);
		Drawables.push_back(enemy);
	}
	
}