#include "Header.h"
#include <iostream>
#include "Setup.h"
#include "Objects.h"




using namespace Setup;

namespace Setup2
{

	ALLEGRO_BITMAP* snek = NULL;
	bool redraw = true;

	float snek_x;
	float snek_y;

	enum KEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_X };


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

	list<GameObject*> Drawables;
	list<Collider*> Colliders;

	bool key[5]{ false, false, false, false, false };

	int map_width = al_get_display_width(display) / WALL_SIZE; // begins with 0
	int map_height = al_get_display_height(display) / WALL_SIZE; // begins with 0

	int eastern_wall_x = WALL_SIZE*(map_width - 1);
	int southern_wall_y = WALL_SIZE*(map_height - 1);

	for (int i = 0; i < map_width; i++)
	{
		Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, 0));					// Northern wall
		Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, southern_wall_y));		// Southern wall
	}
	for (int i = 1; i < map_height - 1; i++)
	{
		Drawables.push_back(new Wall("Resources/image.png", 0, WALL_SIZE*i));					// Western wall
		Drawables.push_back(new Wall("Resources/image.png", eastern_wall_x, WALL_SIZE*i));		// Eastern wall
	}
	
	Player* player;
	{
#pragma region Declarations of local variables
		int player_starting_x = 100;
		int player_starting_y = 100;
		int collider_shift_x = 15;
		int collider_shift_y = 9;
#pragma endregion
#pragma region Animations

		vector<const char*> fileNames;
		vector<const char*> fileNamesAttacks;
		vector<int> frameDelays;

#pragma region RunLeft, RunRight
		frameDelays = { 6, 4, 6 };

		fileNames = { "Resources/Player_left_going1.png","Resources/Player_left.png", "Resources/Player_left_going2.png" };
		fileNamesAttacks = { "Resources/Player_left_going1_attack.png","Resources/Player_left_attack.png","Resources/Player_left_going2_attack.png" };
		Animation* RunLeft = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_right_going1.png","Resources/Player_right.png", "Resources/Player_right_going2.png" };
		fileNamesAttacks = { "Resources/Player_right_going1_attack.png","Resources/Player_right_attack.png","Resources/Player_right_going2_attack.png" };
		Animation* RunRight = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma region RunUp, RunDown
		frameDelays = { 8, 8 };

		fileNames = { "Resources/Player_back_going1.png", "Resources/Player_back_going2.png" };
		fileNamesAttacks = { "Resources/Player_back_going1_attack.png" ,"Resources/Player_back_going2_attack.png" };
		Animation* RunUp = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_front_going1.png", "Resources/Player_front_going2.png" };
		fileNamesAttacks = { "Resources/Player_front_going1_attack.png", "Resources/Player_front_going2_attack.png" };
		Animation* RunDown = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma region IdleLeft, IdleRight, IdleUp, IdleDown

		frameDelays = { 2 };

		fileNames = {"Resources/Player_left.png"};
		fileNamesAttacks = { "Resources/Player_left_attack.png"};
		Animation* IdleLeft = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_right.png" };
		fileNamesAttacks = { "Resources/Player_right_attack.png" };
		Animation* IdleRight = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_back.png" };
		fileNamesAttacks = { "Resources/Player_back_attack.png" };
		Animation* IdleUp = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);

		fileNames = { "Resources/Player_front.png" };
		fileNamesAttacks = { "Resources/Player_front_attack.png" };
		Animation* IdleDown = new Animation(fileNames, fileNamesAttacks, frameDelays, PLAYER_SIZE, PLAYER_SIZE);
#pragma endregion

#pragma endregion 

		
		player = new Player(player_starting_x, player_starting_y,														// starting coordinates
			new Collider(player_starting_x + collider_shift_x, player_starting_y + collider_shift_y, 70, 55, "Player"), // Collider itself
			collider_shift_x, collider_shift_y, &Colliders,																// Collider, collisions
			RunLeft, RunRight, RunUp, RunDown, IdleLeft, IdleRight, IdleUp, IdleDown);									// Animations
			
	}
	Colliders.push_back(player->GetCollider());

	//Walls:
	Colliders.push_back(new Collider(0, 0, map_height*WALL_SIZE, WALL_SIZE));							// Western wall
	Colliders.push_back(new Collider(WALL_SIZE, 0, WALL_SIZE,map_width*WALL_SIZE));						// Northern wall
	Colliders.push_back(new Collider(eastern_wall_x, WALL_SIZE, map_height*WALL_SIZE, WALL_SIZE));		// Eastern wall
	Colliders.push_back(new Collider(WALL_SIZE, southern_wall_y, WALL_SIZE, map_width*WALL_SIZE));		// Southern wall

	Drawables.push_back(player);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			player->moved = false;
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
				player->Attack();
			}
			redraw = true;
			player->MoreDirections(false);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
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
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
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
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			snek_x = ev.mouse.x;
			snek_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_scaled_bitmap(snek, 0, 0, 50, 50, 100, 100, 300, 300, 0);

			for each (GameObject* it in Drawables)
			{
				it->Draw();
			}

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