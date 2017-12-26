#include "Header.h"
#include <iostream>
#include "Setup.h"
#include "Objects.h"


#define WALL_SIZE 75
#define FPS 60

using namespace Setup;

namespace Setup2
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	ALLEGRO_BITMAP* snek = NULL;
	bool redraw = true;

	float snek_x;
	float snek_y;

	enum KEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };


	int initialize()
	{
		if (!al_install_mouse()) {
			fprintf(stderr, "failed to initialize the mouse!\n");
			return 0;
		}
		if (!al_install_keyboard()) {
			fprintf(stderr, "failed to initialize the keyboard!\n");
			return -1;
		}
		timer = al_create_timer(1.0 / FPS);
		if (!timer) {
			fprintf(stderr, "failed to create timer!\n");
			return 0;
		}
		event_queue = al_create_event_queue();
		if (!event_queue) {
			fprintf(stderr, "failed to create event_queue!\n");
			al_destroy_display(display);
			al_destroy_timer(timer);
			return 0;
		}
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
		al_register_event_source(event_queue, al_get_display_event_source(display));

		al_register_event_source(event_queue, al_get_timer_event_source(timer));

		al_register_event_source(event_queue, al_get_mouse_event_source());

		al_register_event_source(event_queue, al_get_keyboard_event_source());


		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_flip_display();

		al_start_timer(timer);




		return 1;
	}
}



//class GameObject2 // tohleto bude pak samozrejme abstraktni, obsahovat bude pouze Draw(), konstruktor,
//				 // destruktor, souradnice a bitmapu
//{
//
//private:
//	ALLEGRO_BITMAP* image;
//	float x;
//	float y;
//
//public:
//	GameObject2(const char* fileName, float x, float y)
//	{
//		image = al_load_bitmap(fileName);
//		this->x = x;
//		this->y = y;
//		//this->display = display;
//		/*if (!image)     // budu tohle muset nejak vymyslet
//		{
//			al_show_native_message_box(GetDisplay(), "Error", "Error", "Failed to load image!",
//				NULL, ALLEGRO_MESSAGEBOX_ERROR);
//			al_destroy_display(GetDisplay());
//		}*/
//	}
//	~GameObject2()
//	{
//
//	}
//	void Draw()
//	{
//		al_draw_bitmap(image,x,y,0);
//	}
//	void SetCoordinates(float x, float y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//};

int main(int argc, char **argv)
{
	using namespace Setup2;
	
	if (Init()) return 0;

	if (!initialize()) return 0;

	list<GameObject*> Drawables;
	list<Collider*> Colliders;

	bool key[4]{ false, false, false, false };

	for (int i = 0; i < al_get_display_width(display)/WALL_SIZE; i++)
	{
		Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, 0)); // Northern wall
		Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*i, WALL_SIZE*(int)((al_get_display_height(display) - 1) / WALL_SIZE - 1))); // Southern wall
	}
	for (int i = 1; i < (al_get_display_height(display)-1)/WALL_SIZE-1; i++)
	{
		Drawables.push_back(new Wall("Resources/image.png", 0, WALL_SIZE*i)); // Western wall
		Drawables.push_back(new Wall("Resources/image.png", WALL_SIZE*((int)(al_get_display_width(display) / WALL_SIZE)-1), WALL_SIZE*i)); // Eastern wall
	}
	Player* player;
	{
		int player_starting_x = 100;
		int player_starting_y = 100;
		int collider_shift_x = 15;
		int collider_shift_y = 9;
		player = new Player("Resources/Player_left_going1.png", "Resources/Player_left_going2.png", player_starting_x, player_starting_y,
									new Collider(player_starting_x + collider_shift_x, player_starting_y + collider_shift_y, 70, 55, "Player"), 
									collider_shift_x, collider_shift_y, &Colliders);
	}
	Colliders.push_back(player->GetCollider());

	//Walls:
	Colliders.push_back(new Collider(0, 0, al_get_display_height(display), WALL_SIZE));				// Western wall
	Colliders.push_back(new Collider(WALL_SIZE, 0, WALL_SIZE, al_get_display_width(display)));		// Northern wall
	Colliders.push_back(new Collider(WALL_SIZE*((int)(al_get_display_width(display) / WALL_SIZE) - 1),
									 WALL_SIZE, al_get_display_height(display), WALL_SIZE));		// Eastern wall
	Colliders.push_back(new Collider(WALL_SIZE, WALL_SIZE*(int)((al_get_display_height(display) - 1) / WALL_SIZE - 1),
									 WALL_SIZE, al_get_display_width(display)));					// Southern wall

	Drawables.push_back(player);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			
			if (key[KEY_UP])
			{
				player->MoveUp(); // move should be done with respect to collisions: https://wiki.allegro.cc/index.php?title=Bounding_Box
			}

			if (key[KEY_DOWN])
			{
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
			
			redraw = true;

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