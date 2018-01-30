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
		int collider_shift_x = 15;
		int collider_shift_y = 9;
		int player_collider_width = 70;
		int player_collider_height = 55;
#pragma endregion
#pragma region Animations

		vector<const char*> fileNames;
		vector<const char*> fileNamesAttacks;
		vector<int> frameDelays;

#pragma region RunLeft, RunRight
		frameDelays = { 6, 4, 6 };

		fileNames = { "Resources/Player_left_going1.png","Resources/Player_left.png", "Resources/Player_left_going2.png" };
		fileNamesAttacks = { "Resources/Player_left_going1_attack.png","Resources/Player_left_attack.png","Resources/Player_left_going2_attack.png" };
		Animation* RunLeft = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_right_going1.png","Resources/Player_right.png", "Resources/Player_right_going2.png" };
		fileNamesAttacks = { "Resources/Player_right_going1_attack.png","Resources/Player_right_attack.png","Resources/Player_right_going2_attack.png" };
		Animation* RunRight = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma region RunUp, RunDown
		frameDelays = { 8, 8 };

		fileNames = { "Resources/Player_back_going1.png", "Resources/Player_back_going2.png" };
		fileNamesAttacks = { "Resources/Player_back_going1_attack.png" ,"Resources/Player_back_going2_attack.png" };
		Animation* RunUp = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_front_going1.png", "Resources/Player_front_going2.png" };
		fileNamesAttacks = { "Resources/Player_front_going1_attack.png", "Resources/Player_front_going2_attack.png" };
		Animation* RunDown = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma region IdleLeft, IdleRight, IdleUp, IdleDown

		frameDelays = { 2 };

		fileNames = { "Resources/Player_left.png" };
		fileNamesAttacks = { "Resources/Player_left_attack.png" };
		Animation* IdleLeft = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_right.png" };
		fileNamesAttacks = { "Resources/Player_right_attack.png" };
		Animation* IdleRight = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_back.png" };
		fileNamesAttacks = { "Resources/Player_back_attack.png" };
		Animation* IdleUp = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_front.png" };
		fileNamesAttacks = { "Resources/Player_front_attack.png" };
		Animation* IdleDown = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma endregion 

		player = new Player(player_starting_x, player_starting_y,											// starting coordinates
			new Collider(player_starting_x + collider_shift_x, player_starting_y + collider_shift_y,
						 player_collider_width, player_collider_height, "Player"),							// Collider itself
			collider_shift_x, collider_shift_y, &GameMap::Colliders,										// Collider, collisions
			RunLeft, RunRight, RunUp, RunDown, IdleLeft, IdleRight, IdleUp, IdleDown);						// Animations

		GameMap::Colliders.push_back(player->GetCollider());
		GameMap::Drawables.push_back(player);

	}
}
