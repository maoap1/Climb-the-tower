#pragma once
#include "Header.h"

namespace Setup
{
	bool Init(); // We call this function in order to initialize the allegro, return 0 if everything is fine, -1 otherwise
	
	extern ALLEGRO_DISPLAY* display;
	extern ALLEGRO_EVENT_QUEUE* event_queue;
	extern ALLEGRO_TIMER* timer;

}

