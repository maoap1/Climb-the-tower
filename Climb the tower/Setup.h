#pragma once
#include "Header.h"

namespace Setup
{
	/// <summary>
	/// This function initializes allegro. Returns 0 if everything is fine, -1 otherwise
	/// </summary>
	bool Init();
	
	extern ALLEGRO_DISPLAY* display;
	extern ALLEGRO_EVENT_QUEUE* event_queue;
	extern ALLEGRO_TIMER* timer;

}

