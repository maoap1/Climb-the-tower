#include "Setup.h"


namespace Setup
{
	ALLEGRO_DISPLAY_MODE   disp_data; // here is stored the information about the monitor
	
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
		
#pragma region "private" functions

	bool Setup_allegro()
	{
		if (!al_init())
		{
			fprintf(stderr, "Failed to initialize allegro!\n");
			return false;
		}
		if (!al_init_image_addon())
		{
			fprintf(stderr, "Failed to initialize image addon!\n");
			return false;
		}
		if (!al_init_primitives_addon())
		{
			fprintf(stderr, "Failed to initialize primitives addon!\n");
			return false;
		}
		return true;
	}

	bool Setup_display()  // We are going to setup a display properly, returns 0 if ok, -1 if something has gone wrong
	{
		display = NULL;
		al_get_display_mode(al_get_num_display_modes() - 1, &disp_data); // getting maximum resolution and storing into disp_data
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);  // display yourself in fullscreen

		display = al_create_display(disp_data.width, disp_data.height);  // creation of display

		if (!display)
		{
			fprintf(stderr, "Failed to create display!\n");
			return false;
		}
		return true;
	}

	bool Setup_input()
	{
		if (!al_install_mouse())
		{
			fprintf(stderr, "failed to initialize the mouse!\n");
			return false;
		}
		if (!al_install_keyboard())
		{
			fprintf(stderr, "failed to initialize the keyboard!\n");
			return false;
		}

		return true;
	}

	bool Setup_timer()
	{
		timer = al_create_timer(1.0 / FPS);
		if (!timer)
		{
			fprintf(stderr, "failed to create timer!\n");
			return false;
		}
		return true;
	}

	bool Setup_event_queue()
	{
		event_queue = al_create_event_queue();
		if (!event_queue)
		{
			fprintf(stderr, "failed to create event_queue!\n");
			al_destroy_display(display);
			al_destroy_timer(timer);
			return false;
		}

		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_register_event_source(event_queue, al_get_mouse_event_source());
		al_register_event_source(event_queue, al_get_keyboard_event_source());

		return true;
	}

#pragma endregion

	bool Init()
	{
		if (!Setup_allegro())
		{
			return false;
		}
		if (!Setup_display())
		{
			return false;
		}
		if (!Setup_input())
		{
			return false;
		}
		if (!Setup_timer())
		{
			return false;
		}
		if (!Setup_event_queue())
		{
			return false;
		}

		return true;
	}


}