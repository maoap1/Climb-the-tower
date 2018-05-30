#include "Header.h"
#include <iostream> // DELETE in the final version
#include "Setup.h"
#include "Objects.h"
#include "GameMap.h"
#include "ObjectsCreation.h"
#include "AnimationInitialization.h"
#include "Gui.h"


using namespace Setup;
using namespace GameMap;
using namespace ObjectsCreation;

enum KEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_X, KEY_C, KEY_V }; // used keys in this game except for the gui handling

/// <summary>
/// Initializes the game: (!should be called just once)
/// Specifically: Game loop, display, animations, GUI.
/// </summary>
/// <returns></returns>
void initialize()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer); // Starts the game loop
	AnimationInitialization::AnimInit();
	Gui::InicializeGUI();
}

int main(int argc, char **argv)
{	
	if (!Init()) return 0;
	initialize();

	bool redraw = true;
	bool key[NUMBER_OF_KEYS]{ false, false, false, false, false, false, false };

	int map_width = al_get_display_width(display) / WALL_SIZE; // begins with 0
	int map_height = al_get_display_height(display) / WALL_SIZE; // begins with 0
	
	if (Gui::MainMenu() == ID_QUIT) // opens Main Menu
	{
		al_flip_display();
		al_rest(1);
		al_destroy_display(display);
		return 0;
	}

	FirstGameMapInicialization(map_width, map_height); // initializes the Game Map for the first time
	CreatePlayer(); // this line should be after FirstGameMapInicialization, creates player

	while (1) // game loop itself
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (!player->living) // the player is death, we should quit the game with Game Over screen
			{
				if (Gui::QuitMenu() == ID_QUIT)
				{
					al_flip_display();
					al_rest(1);
					al_destroy_display(display);
					return 0;
				}
			}

			if (livingEnemies <= 0) // all enemies are death, we should quit the game with Winning screen
			{
				if (Gui::WinMenu() == ID_QUIT)
				{
					al_flip_display();
					al_rest(1);
					al_destroy_display(display);
					return 0;
				}
			}
			player->moved = false;
			for each (ActiveGameObject* it in Movables) // now we move with all the movable objects
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
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) // now we just put the information that we hold a key to key[]
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

			case ALLEGRO_KEY_P: // it pauses the game and displays Pause menu 
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
				Mutes or plays music
				*/
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) // now we just put the information that we stopped holding a key to key[]
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

		if (redraw && al_is_event_queue_empty(event_queue)) // a standard way how to in allegro separate the physics and drawing of the game
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			for each (GameObject* it in Drawables) // draws every object
			{
				it->Draw();
			}
			for each (GameObject* it in ToDeletion) // delete those objects, that couldn't be deleted during drawing
			{
				Drawables.remove(it);
				delete it;
			}
			ToDeletion.clear();

			#ifdef DEBUG
			for each (Collider* it in Colliders) // draws green rectagles for debugging collisions
			{
				it->Draw();
			}
			#endif // DEBUG

			al_flip_display();
		}
	}

	al_flip_display();
	al_rest(1);
	al_destroy_display(display);
	return 0;
}