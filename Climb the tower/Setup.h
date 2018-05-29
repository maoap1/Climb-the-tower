#pragma once
#include "Header.h"

/// <summary>
/// In this namespace the needed parts of Allegro library are initialized
/// </summary>
namespace Setup
{
	/// <summary>
	/// This function initializes allegro. Returns 0 if everything is fine, -1 otherwise
	/// </summary>
	bool Init();
	
	/// <summary>
	/// Allegro display
	/// </summary>
	extern ALLEGRO_DISPLAY* display;

	/// <summary>
	/// Allegro event queue
	/// </summary>
	extern ALLEGRO_EVENT_QUEUE* event_queue;

	/// <summary>
	/// Allegro timer
	/// </summary>
	extern ALLEGRO_TIMER* timer;

}

