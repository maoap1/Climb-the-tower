#pragma once

#include "Header.h"
#include "Player.h"
#include "Animation.h"
#include "Collider.h"

namespace ObjectsCreation
{
	/// <summary>
	///  The instance of player
	/// </summary>
	extern Player* player;

	/// <summary>
	/// This inicializes the player
	/// </summary>
	void CreatePlayer();
}
