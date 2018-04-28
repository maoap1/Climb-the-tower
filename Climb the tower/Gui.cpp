/*
This part of the game is heavily dependent on a GUI library named Widgetz.
I altered it much, althought there are still a lot of original ideas and code parts from the original one.
For more information see copyright below.
*/
/*
Copyright (c) 2011 Pavel Sountsov

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/


#include "Gui.h"
#include "Setup.h"



namespace Gui
{
	ALLEGRO_FONT* font;
	WZ_DEF_THEME theme;
	WZ_SKIN_THEME skin_theme;

	int font_size = 18;
	float size = 3.0;
	int refresh_rate;
	double fixed_dt;

	int width;
	int height;
	int bWidth;
	int bHeight;
	int tWidth;
	int tHeight;

	void InicializeGUI()
	{
		// Inicializing Allegro addons
		al_init_font_addon();
		al_init_ttf_addon();
		// Loading font
		font = al_load_font("data/DejaVuSans.ttf", font_size * size, 0);
		//Refreshing
		refresh_rate = 60;
		fixed_dt = 1.0f / refresh_rate;
		// Skin theme initialization
		memset(&theme, 0, sizeof(theme));
		memcpy(&theme, &wz_def_theme, sizeof(theme));
		theme.font = font;
		theme.color1 = al_map_rgba_f(0.1, 0.1, 0.9, 1);
		theme.color2 = al_map_rgba_f(1, 0.6, 0.1, 1);
		theme.color2 = al_map_rgba_f(0, 0.8, 0, 1);
		memset(&skin_theme, 0, sizeof(skin_theme));
		memcpy(&skin_theme, &wz_skin_theme, sizeof(skin_theme));
		skin_theme.theme.font = font;
		skin_theme.theme.color1 = al_map_rgba_f(0.1, 0.1, 0.9, 1);
		skin_theme.theme.color2 = al_map_rgba_f(1, 0.6, 0.1, 1);
		skin_theme.button_up_bitmap = al_load_bitmap("data/button_up.png");
		skin_theme.button_down_bitmap = al_load_bitmap("data/button_down.png");
		skin_theme.box_bitmap = al_load_bitmap("data/box.png");
		skin_theme.editbox_bitmap = al_load_bitmap("data/editbox.png");
		skin_theme.scroll_track_bitmap = al_load_bitmap("data/scroll_track.png");
		skin_theme.slider_bitmap = al_load_bitmap("data/slider.png");
		wz_init_skin_theme(&skin_theme);
		// Size initialiation
		width = al_get_display_width(Setup::display); // = 1920
		height = al_get_display_height(Setup::display); // = 1080
		bWidth = width * BUTTON_WIDTH_MULTIPLIER;
		bHeight = height * BUTTON_HEIGHT_MULTIPLIER;
		tWidth = width * TEXT_WIDTH_MULTIPLIER;
		tHeight = height * TEXT_HEIGHT_MULTIPLIER;
	}

	int ControlsMenu()
	{
		int result = ID_QUIT;

		WZ_WIDGET* gui;
		WZ_WIDGET* wgt;

		double old_time;
		double game_time;
		double start_time;
		bool done = false;

		old_time = al_current_time();
		game_time = al_current_time();

		// size = 3

		gui = wz_create_widget(0, 0, 0, -1);
		wz_set_theme(gui, (WZ_THEME*)&skin_theme);

		wz_create_fill_layout(gui, width*0.2, height*0.1, width*0.6, height*0.8, width*0.05, height*0.05, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Controls"), 1, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Move with arrows"), 1, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Press P for pause"), 1, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Press O for viewing your stats"), 1, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Press X, C, V for attacks"), 1, -1);
		wz_create_textbox(gui, 0, 0, tWidth, tHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Press M for mute/music"), 1, -1);

		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Back"), 1, ID_BACK);
		wz_set_shortcut(wgt, ALLEGRO_KEY_B, ALLEGRO_KEYMOD_CTRL);

		wz_register_sources(gui, Setup::event_queue);

		while (!done)
		{
			double dt = al_current_time() - old_time;
			al_rest(fixed_dt - dt); //rest at least fixed_dt
			dt = al_current_time() - old_time;
			old_time = al_current_time();

			if (old_time - game_time > dt)    //eliminate excess overflow
			{
				game_time += fixed_dt * floor((old_time - game_time) / fixed_dt);
			}

			start_time = al_current_time();

			while (old_time - game_time >= 0)
			{
				ALLEGRO_EVENT event;
				game_time += fixed_dt;
				/*
				Update gui
				*/
				wz_update(gui, fixed_dt);

				while (al_get_next_event(Setup::event_queue, &event))
				{
					/*
					Give the gui the event, in case it wants it
					*/
					wz_send_event(gui, &event);

					switch (event.type)
					{
					case WZ_BUTTON_PRESSED:
					{
						switch ((int)event.user.data1)
						{
							case ID_BACK:
							{
								result = ID_BACK;
								done = true;
								break;
							}

						}

						break;
					}
					}
				}

			}

			al_clear_to_color(al_map_rgb(0, 0, 0));
			/*
			Draw the gui
			*/
			wz_draw(gui);
			al_wait_for_vsync();
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		return result;
	}

	int MainMenu()
	{
		int result = ID_QUIT;

		WZ_WIDGET* gui;
		WZ_WIDGET* wgt;

		double old_time;
		double game_time;
		double start_time;
		bool done = false;

		old_time = al_current_time();
		game_time = al_current_time();

		// size = 3

		gui = wz_create_widget(0, 0, 0, -1);
		wz_set_theme(gui, (WZ_THEME*)&skin_theme);

		wz_create_fill_layout(gui, width*0.2, height*0.05, width*0.6, height*0.9, width*0.05, height*0.05, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, bWidth, bHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Climb the Tower"), 1, -1);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Start"), 1, ID_START);
		wz_set_shortcut(wgt, ALLEGRO_KEY_S, ALLEGRO_KEYMOD_CTRL);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Controls"), 1, ID_CONTROLS);
		wz_set_shortcut(wgt, ALLEGRO_KEY_C, ALLEGRO_KEYMOD_CTRL);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Quit"), 1, ID_QUIT);
		wz_set_shortcut(wgt, ALLEGRO_KEY_Q, ALLEGRO_KEYMOD_CTRL);

		wz_register_sources(gui, Setup::event_queue);

		while (!done)
		{
			double dt = al_current_time() - old_time;
			al_rest(fixed_dt - dt); //rest at least fixed_dt
			dt = al_current_time() - old_time;
			old_time = al_current_time();

			if (old_time - game_time > dt)    //eliminate excess overflow
			{
				game_time += fixed_dt * floor((old_time - game_time) / fixed_dt);
			}

			start_time = al_current_time();

			while (old_time - game_time >= 0)
			{
				ALLEGRO_EVENT event;
				game_time += fixed_dt;
				/*
				Update gui
				*/
				wz_update(gui, fixed_dt);

				while (al_get_next_event(Setup::event_queue, &event))
				{
					/*
					Give the gui the event, in case it wants it
					*/
					wz_send_event(gui, &event);

					switch (event.type)
					{
					case WZ_BUTTON_PRESSED:
					{
						switch ((int)event.user.data1)
						{
						case ID_START:
						{
							result = ID_START;
							done = true;
							break;
						}

						case ID_CONTROLS:
						{
							ControlsMenu();
							break;
						}

						case ID_QUIT:
						{
							result = ID_QUIT;
							done = true;
							break;
						}

						}

						break;
					}
					}
				}
			}

			al_clear_to_color(al_map_rgb(0, 0, 0));
			/*
			Draw the gui
			*/
			wz_draw(gui);
			al_wait_for_vsync();
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		return result;
	}

	int PauseMenu()
	{
		int result = ID_QUIT;

		WZ_WIDGET* gui;
		WZ_WIDGET* wgt;

		double old_time;
		double game_time;
		double start_time;
		bool done = false;

		old_time = al_current_time();
		game_time = al_current_time();

		// size = 3

		gui = wz_create_widget(0, 0, 0, -1);
		wz_set_theme(gui, (WZ_THEME*)&skin_theme);

		wz_create_fill_layout(gui, width*0.2, height*0.1, width*0.6, height*0.8, width*0.05, height*0.05, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, bWidth, bHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Climb the Tower"), 1, -1);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Continue"), 1, ID_CONTINUE);
		wz_set_shortcut(wgt, ALLEGRO_KEY_S, ALLEGRO_KEYMOD_CTRL);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Quit"), 1, ID_QUIT);
		wz_set_shortcut(wgt, ALLEGRO_KEY_Q, ALLEGRO_KEYMOD_CTRL);

		wz_register_sources(gui, Setup::event_queue);

		while (!done)
		{
			double dt = al_current_time() - old_time;
			al_rest(fixed_dt - dt); //rest at least fixed_dt
			dt = al_current_time() - old_time;
			old_time = al_current_time();

			if (old_time - game_time > dt)    //eliminate excess overflow
			{
				game_time += fixed_dt * floor((old_time - game_time) / fixed_dt);
			}

			start_time = al_current_time();

			while (old_time - game_time >= 0)
			{
				ALLEGRO_EVENT event;
				game_time += fixed_dt;
				/*
				Update gui
				*/
				wz_update(gui, fixed_dt);

				while (al_get_next_event(Setup::event_queue, &event))
				{
					/*
					Give the gui the event, in case it wants it
					*/
					wz_send_event(gui, &event);

					switch (event.type)
					{
					case WZ_BUTTON_PRESSED:
					{
						switch ((int)event.user.data1)
						{
						case ID_CONTINUE:
						{
							result = ID_CONTINUE;
							done = true;
							break;
						}
						case ID_QUIT:
						{
							result = ID_QUIT;
							done = true;
							break;
						}

						}

						break;
					}
					}
				}
			}

			al_clear_to_color(al_map_rgb(0, 0, 0));
			/*
			Draw the gui
			*/
			wz_draw(gui);
			al_wait_for_vsync();
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		return result;
	}

}

