#include "Header.h"
#include <iostream> // DELETE in the final version
#include "Setup.h"
#include "Objects.h"
#include "GameMap.h"
#include "ObjectsCreation.h"
#include "AnimationInitialization.h"
#include "Gui.h"


using namespace Setup;

namespace Setup2
{
	ALLEGRO_BITMAP* snek = NULL;
	bool redraw = true;

	float snek_x;
	float snek_y;

	enum KEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_X, KEY_C, KEY_V};


	int initialize()
	{

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_flip_display();

		al_start_timer(timer);

		return 1;
	}
}

int main(int argc, char **argv)
{
	using namespace Setup2;
	
	if (!Init()) return 0;

	if (!initialize()) return 0;

#pragma region Kraviny, casem smazat
	snek = al_load_bitmap("Resources/image.png");
	snek_x = 0;
	snek_y = 0;

	if (!snek)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

#pragma endregion

	using namespace GameMap;
	using namespace ObjectsCreation;


	AnimationInitialization::AnimInit();


	bool key[NUMBER_OF_KEYS]{ false, false, false, false, false, false, false };

	int map_width = al_get_display_width(display) / WALL_SIZE; // begins with 0
	int map_height = al_get_display_height(display) / WALL_SIZE; // begins with 0
	
	Gui::InicializeGUI();
	if (Gui::MainMenu() == ID_QUIT)
	{
		al_flip_display();
		al_rest(1);
		al_destroy_display(display);
		return 0;
	}

	FirstGameMapInicialization(map_width, map_height);
	CreatePlayer(); // this line should be after FirstGameMapInicialization

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			player->moved = false;
			for each (ActiveGameObject* it in Movables)
			{
				it->Move();
			}

			if (key[KEY_UP])
			{
				if (key[KEY_LEFT])
				{
					player->MoreDirections(true);
				}
				player->MoveUp();
			}

			if (key[KEY_DOWN])
			{
				if (key[KEY_LEFT] || key[KEY_RIGHT])
				{
					player->MoreDirections(true);
				}
				player->MoveDown();
			}

			if (key[KEY_LEFT])
			{
				player->MoveLeft();
			}

			if (key[KEY_RIGHT])
			{
				player->MoveRight();
			}
			
			if (key[KEY_X])
			{
				player->Attack(ID_FIREBALL);
			}
			if (key[KEY_C])
			{
				player->Attack(ID_WATERBLAST);
			}
			if (key[KEY_V])
			{
				player->Attack(ID_ARCANEBALL);
			}
			redraw = true;
			player->MoreDirections(false);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_X:
				key[KEY_X] = true;
				break;

			case ALLEGRO_KEY_C:
				key[KEY_C] = true;
				break;

			case ALLEGRO_KEY_V:
				key[KEY_V] = true;
				break;

			case ALLEGRO_KEY_P:
				if (Gui::PauseMenu() == ID_QUIT)
				{
					al_flip_display();
					al_rest(1);
					al_destroy_display(display);
					return 0;
				}
				for (int i = 0; i < NUMBER_OF_KEYS; i++)
				{
					key[i] = false;
				}
				break;
			case ALLEGRO_KEY_O:
				/*if (Gui::StatsMenu() == ID_QUIT)
				{
					al_flip_display();
					al_rest(1);
					al_destroy_display(display);
					return 0;
				}
				for (int i = 0; i < NUMBER_OF_KEYS; i++)
				{
					key[i] = false;
				}
				break;*/
			case ALLEGRO_KEY_M:
				/*
				Mute or play music
				*/
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) 
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_X:
				key[KEY_X] = false;
				break;

			case ALLEGRO_KEY_C:
				key[KEY_C] = false;
				break;

			case ALLEGRO_KEY_V:
				key[KEY_V] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) 
		{

			snek_x = ev.mouse.x;
			snek_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
		{
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) 
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_scaled_bitmap(snek, 0, 0, 50, 50, 100, 100, 300, 300, 0);

			for each (GameObject* it in Drawables)
			{
				it->Draw();
			}
			for each (GameObject* it in ToDeletion)
			{
				Drawables.remove(it);
				delete it;
			}
			ToDeletion.clear();

			#ifdef DEBUG
			for each (Collider* it in Colliders)
			{
				it->Draw();
			}
			#endif // DEBUG

			al_draw_bitmap(snek, snek_x, snek_y, 0);

			al_flip_display();
		}
	}

	al_draw_bitmap(snek, 0, 0, 0);
	al_flip_display();
	al_rest(1);
	al_destroy_display(display);
	return 0;
}