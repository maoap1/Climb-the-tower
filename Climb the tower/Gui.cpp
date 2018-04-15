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
	int MainMenu()
	{
		int result = ID_QUIT;
		ALLEGRO_FONT* font;
		int refresh_rate;
		float size = 3.0;
		int font_size = 18;
		double fixed_dt;
		double old_time;
		double game_time;
		double start_time;
		WZ_WIDGET* gui;
		WZ_DEF_THEME theme;
		WZ_SKIN_THEME skin_theme;
		WZ_WIDGET* wgt;
		bool done = false;
		bool fancy_theme = true;

		al_init_font_addon();
		al_init_ttf_addon();

		font = al_load_font("data/DejaVuSans.ttf", font_size * size, 0);

		refresh_rate = 60;
		fixed_dt = 1.0f / refresh_rate;
		old_time = al_current_time();
		game_time = al_current_time();


		memset(&theme, 0, sizeof(theme));
		memcpy(&theme, &wz_def_theme, sizeof(theme));
		theme.font = font;
		theme.color1 = al_map_rgba_f(0.1, 0.1, 0.9, 1);
		theme.color2 = al_map_rgba_f(1, 0.6, 0.1, 1);

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

		gui = wz_create_widget(0, 0, 0, -1);
		wz_set_theme(gui, (WZ_THEME*)&skin_theme);
		
		//wz_create_fill_layout(gui, 50 * size, 50 * size, 300 * size, 450 * size, 50 * size, 20 * size, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);


#define BUTTON_WIDTH_MULTIPLIER 0.3
#define BUTTON_HEIGHT_MULTIPLIER 0.15

		int width = al_get_display_width(Setup::display); // = 1920
		int height = al_get_display_height(Setup::display); // = 1080
		int bWidth = width*BUTTON_WIDTH_MULTIPLIER;
		int bHeight = height*BUTTON_HEIGHT_MULTIPLIER;


															// size = 3

		wz_create_fill_layout(gui, width*0.2, height*0.1, width*0.6, height*0.8, width*0.05, height*0.05, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, bWidth, bHeight, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Climb the Tower"), 1, -1);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Start"), 1, ID_START);
		wz_set_shortcut(wgt, ALLEGRO_KEY_S, ALLEGRO_KEYMOD_CTRL);
		wgt = (WZ_WIDGET*)wz_create_button(gui, 0, 0, bWidth, bHeight, al_ustr_new("Quit"), 1, ID_QUIT);
		wz_set_shortcut(wgt, ALLEGRO_KEY_Q, ALLEGRO_KEYMOD_CTRL);
		//wz_create_toggle_button(gui, 0, 0, 200 * size, 50 * size, al_ustr_new("Toggle 1"), 1, 1, 5);
		//wz_create_toggle_button(gui, 0, 0, 200 * size, 50 * size, al_ustr_new("Toggle 2"), 1, 1, 6);
		//wz_create_toggle_button(gui, 0, 0, 200 * size, 50 * size, al_ustr_new("Toggle 3"), 1, 1, 7);
		//wz_create_button(gui, 0, 0, 200 * size, 50 * size, al_ustr_new("Switch Themes"), 1, 666);
		
		/*wz_create_fill_layout(gui, 350 * size, 50 * size, 300 * size, 450 * size, 50 * size, 20 * size, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, 200 * size, 50 * size, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Scroll Bars:"), 1, -1);
		wz_create_scroll(gui, 0, 0, 200 * size, 20 * size, 20, 50 * size, 9);
		wz_create_scroll(gui, 0, 0, 20 * size, 200 * size, 20, 50 * size, 9);
		wz_create_scroll(gui, 0, 0, 20 * size, 200 * size, 20, 50 * size, 9);
		wz_create_fill_layout(gui, 650 * size, 50 * size, 300 * size, 450 * size, 20 * size, 20 * size, WZ_ALIGN_CENTRE, WZ_ALIGN_TOP, -1);
		wz_create_textbox(gui, 0, 0, 200 * size, 50 * size, WZ_ALIGN_CENTRE, WZ_ALIGN_CENTRE, al_ustr_new("Edit Box:"), 1, -1);*/
		/*wgt = (WZ_WIDGET*)wz_create_editbox(gui, 0, 0, 200 * size, 50 * size, al_ustr_new("Type here..."), 1, -1);
		wz_create_textbox(gui, 0, 0, 200 * size, 50 * size, WZ_ALIGN_LEFT, WZ_ALIGN_TOP, al_ustr_new("A textbox with a lot of text"
			" in it. Also supports new lines:\n\nNew paragraph.\n"
			"Also supports unicode:\n\n"), 1, -1);*/

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
						case ID_QUIT:
						{
							result = ID_QUIT;
							done = true;
							break;
						}
						case 666:
						{
							fancy_theme = !fancy_theme;
							if (fancy_theme)
								wz_set_theme(gui, (WZ_THEME*)&skin_theme);
							else
								wz_set_theme(gui, (WZ_THEME*)&theme);
						}
						}

						break;
					}
					}
				}

				if (al_current_time() - start_time > fixed_dt) //break if we start taking too long
					break;
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

