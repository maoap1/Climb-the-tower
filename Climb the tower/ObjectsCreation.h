#pragma once

#include "Header.h"
#include "Player.h"
#include "Animation.h"
#include "Collider.h"

/// <summary>
/// In this namespace is created the player.
/// </summary>
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
