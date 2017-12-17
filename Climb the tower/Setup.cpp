#include "Setup.h"


namespace Setup
{
	ALLEGRO_DISPLAY_MODE   disp_data; // here is stored the information about the monitor
	ALLEGRO_DISPLAY* display;

#pragma region forward declarations
	int Setup_display();
	int Setup_allegro();
#pragma endregion

	int Init()
	{
		if (Setup_allegro())
		{
			return -1;
		}
		if (Setup_display())
		{
			return -1;
		}

		return 0;
	}


#pragma region "private" functions

	int Setup_display()  // We are going to setup a display properly, returns 0 if ok, -1 if something has gone wrong
	{
		display = NULL;
		al_get_display_mode(al_get_num_display_modes() - 1, &disp_data); // getting maximum resolution and storing into disp_data
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);  // display yourself in fullscreen

		display = al_create_display(disp_data.width, disp_data.height);  // creation of display

		if (!display) {
			fprintf(stderr, "Failed to create display!\n");
			return -1;
		}
		return 0;
	}

	int Setup_allegro()
	{
		if (!al_init()) {
			fprintf(stderr, "Failed to initialize allegro!\n");
			return -1;
		}
		if (!al_init_image_addon()) {
			fprintf(stderr, "Failed to initialize image addon!\n");
			return -1;
		}
		if (!al_init_primitives_addon()) {
			fprintf(stderr, "Failed to initialize primitives addon!\n");
			return -1;
		}
		return 0;
	}

#pragma endregion

}