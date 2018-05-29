#include "GameMap.h"
#include "Header.h"
#include "Objects.h"
#include "Player.h"
#include "Enemy.h"

namespace GameMap
{
	/// <summary>
	/// Here are stored Game Objects that cannot be deleted during the draw phase, so they are stored here and deleted just after the draw phase
	/// </summary>
	list<GameObject*> ToDeletion;
	/// <summary>
	/// Here are stored all Game Objects, for which the game calls function Draw()
	/// </summary>
	list<GameObject*> Drawables;
	/// <summary>
	/// Here are stored all Game Objects, for which the game calls function Move()
	/// </summary>
	list<ActiveGameObject*> Movables;
	/// <summary>
	/// Here are stored all colliders for purpose of colliding
	/// </summary>
	list<Collider*> Colliders;

	/// <summary>
	/// The game map. Its size is determined by the size of the monitor.
	/// Stores 0 for empty space, -1 for walls;  
	/// Imagine we would like to work with Map[i][j].
	/// 1.Then i is from 0 to heigth, j is from 0 to width. 
	/// 2.Then coordinates of top left corner of this are:
	/// x = (j + 1)*WALL_SIZE;
	/// y = (i + 1)*WALL_SIZE;
	/// </summary>
	vector<vector<int>> Map;

	/// <summary>
	/// Height of the Map
	/// </summary>
	int Map_height;

	/// <summary>
	/// Width of the Map
	/// </summary>
	int Map_width;

	/// <summary>
	/// Number of living enemies, when <= 0, the game ends
	/// </summary>
	int livingEnemies;

	/// <summary>
	/// Inicializes the Game map dor the first time
	/// </summary>
	/// <param name="map_width">Width of the map.</param>
	/// <param name="map_height">Height of the map.</param>
	void FirstGameMapInicialization(int map_width, int map_height)
	{

		int eastern_wall_x = WALL_SIZE*(map_width - 1);
		int southern_wall_y = WALL_SIZE*(map_height - 1);

		for (int i = 0; i < map_width; i++)
		{
			Drawables.push_back(new Wall("Resources/Wall.png", WALL_SIZE*i, 0));					// Northern wall
			Drawables.push_back(new Wall("Resources/Wall.png", WALL_SIZE*i, southern_wall_y));		// Southern wall
		}
		for (int i = 1; i < map_height - 1; i++)
		{
			Drawables.push_back(new Wall("Resources/Wall.png", 0, WALL_SIZE*i));					// Western wall
			Drawables.push_back(new Wall("Resources/Wall.png", eastern_wall_x, WALL_SIZE*i));		// Eastern wall
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

		// From here it isnt suitable for first game map inicialization
		Map[3][5] = -1;
		Map[3][6] = -1;
		Map[3][7] = -1;
		Map[4][6] = -1;
		Map[5][6] = -1;
		Map[6][6] = -1;

		for (int i = 0; i < Map_height; i++)
		{
			for (int j = 0; j < Map_width; j++)
			{
				if (Map[i][j] == -1)
				{
					Drawables.push_back(new Wall("Resources/Wall.png", (j + 1)*WALL_SIZE, (i + 1)*WALL_SIZE));
					Colliders.push_back(new Collider((j + 1)*WALL_SIZE, (i + 1)*WALL_SIZE, WALL_SIZE, WALL_SIZE));
				}
			}
		}

		auto generator = mt19937(random_device{}());

		uniform_int_distribution<int> widthDistribution(START_LOCATION_Y, Map_width - 1);
		uniform_int_distribution<int> heightDistribution(0, Map_height - 1);
		auto rndWidth = bind(widthDistribution, generator);
		auto rndHeight = bind(heightDistribution, generator);

		int createdEnemies = 0;
		int howMuchEnemies = 5;
		livingEnemies = howMuchEnemies;

		while (createdEnemies != howMuchEnemies)
		{
			int x = rndHeight();
			int y = rndWidth();
			if (Map[x][y] == 0)
			{
				CreateEnemy((y + 1)*WALL_SIZE, (x + 1)*WALL_SIZE, SLIME_HEALTH);
				Map[x][y] = 1;
				createdEnemies++;
			}
		}
	}

	/// <summary>
	/// Returns random empty position on the game map
	/// </summary>
	/// <param name="x">The x coordinate of the random position</param>
	/// <param name="y">The y coordinate of the random position</param>
	void RandomEmptyPosition(float& x, float& y)
	{
		auto generator = mt19937(random_device{}());

		uniform_int_distribution<int> widthDistribution(0, Map_width - 1);
		uniform_int_distribution<int> heightDistribution(0, Map_height - 1);
		auto rndWidth = bind(widthDistribution, generator);
		auto rndHeight = bind(heightDistribution, generator);

		int done = 0;
		while (done != 1)
		{
			int yy = rndHeight();
			int xx = rndWidth();
			if (Map[yy][xx] != -1) // it isnt wall
			{
				x = (xx + 1)*WALL_SIZE;
				y = (yy + 1)*WALL_SIZE;
				done = 1;
			}
		}
	}

	/// <summary>
	/// Creates the spell.
	/// </summary>
	/// <param name="x">The x coordinate of the spell</param>
	/// <param name="y">The y coordinate of the spell</param>
	/// <param name="orientation">The orientation of the spell</param>
	/// <param name="spellID">The identifier of spell -> see Constants.h</param>
	void CreateSpell(float x, float y, int orientation, int spellID)
	{
		Spell* spell = new Spell(x, y, orientation, spellID);
		Movables.push_back(spell);
		Drawables.push_back(spell);
	}

	/// <summary>
	/// Creates the enemy.
	/// </summary>
	/// <param name="x">The x coordinate of the enemy</param>
	/// <param name="y">The y coordinate of the enemy</param>
	/// <param name="lives">Lives of the enemy</param>
	void CreateEnemy(float x, float y, float lives)
	{
		Enemy* enemy = new Enemy(x, y, lives);
		Movables.push_back(enemy);
		Drawables.push_back(enemy);
	}
	
}