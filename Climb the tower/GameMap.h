#pragma once
#include "Header.h"
#include "GameObject.h"
#include "ActiveGameObject.h"
#include "Collider.h"

namespace GameMap
{
	/// <summary>
	/// Here are stored Game Objects that cannot be deleted during the draw phase, so they are stored here and deleted just after the draw phase
	/// </summary>
	extern list<GameObject*> ToDeletion;

	/// <summary>
	/// Here are stored all Game Objects, for which the game calls function Draw()
	/// </summary>
	extern list<GameObject*> Drawables;

	/// <summary>
	///  Here are stored all Game Objects, for which the game calls function Move()
	/// </summary>
	extern list<ActiveGameObject*> Movables;

	/// <summary>
	/// Here are stored all colliders for purpose of colliding
	/// </summary>
	extern list<Collider*> Colliders;

	/// <summary>
	/// The game map. Its size is determined by the size of the monitor.
	/// Stores 0 for empty space, -1 for walls;  
	/// Imagine we would like to work with Map[i][j].
	/// 1.Then i is from 0 to heigth, j is from 0 to width. 
	/// 2.Then coordinates of top left corner of this are:
	/// x = (j + 1)*WALL_SIZE;
	/// y = (i + 1)*WALL_SIZE;
	/// </summary>
	extern vector<vector<int>> Map;

	/// <summary>
	/// Number of living enemies, when <= 0, the game ends
	/// </summary>
	extern int livingEnemies;

	/// <summary>
	/// Inicializes the Game map dor the first time
	/// </summary>
	/// <param name="map_width">Width of the map.</param>
	/// <param name="map_height">Height of the map.</param>
	void FirstGameMapInicialization(int map_width, int map_height);

	/// <summary>
	/// Returns random empty position on the game map
	/// </summary>
	/// <param name="x">The x coordinate of the random position</param>
	/// <param name="y">The y coordinate of the random position</param>
	void RandomEmptyPosition(float& x, float& y);

	/// <summary>
	/// Creates the spell.
	/// </summary>
	/// <param name="x">The x coordinate of the spell</param>
	/// <param name="y">The y coordinate of the spell</param>
	/// <param name="orientation">The orientation of the spell</param>
	/// <param name="spellID">The identifier of spell -> see Constants.h</param>
	void CreateSpell(float x, float y, int orientation, int spellID);

	/// <summary>
	/// Creates the enemy.
	/// </summary>
	/// <param name="x">The x coordinate of the enemy</param>
	/// <param name="y">The y coordinate of the enemy</param>
	/// <param name="lives">Lives of the enemy</param>
	void CreateEnemy(float x, float y, float lives);

}