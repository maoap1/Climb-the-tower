#include "ObjectsCreation.h"
#include "GameMap.h"

namespace ObjectsCreation
{
	Player* player;

	void CreatePlayer()
	{

#pragma region Declarations of local variables
		int player_starting_x = 100;
		int player_starting_y = 100;
#pragma endregion

		player = new Player(player_starting_x, player_starting_y);		// starting coordinates

		GameMap::Drawables.push_back(player);

	}
}
