#include "GameObject.h"

GameObject::GameObject(const char* fileName, float x, float y)
{
	image = al_load_bitmap(fileName);
	this->x = x;
	this->y = y;
	//this->display = display;
	/*if (!image)     // budu tohle muset nejak vymyslet
	{
	al_show_native_message_box(GetDisplay(), "Error", "Error", "Failed to load image!",
	NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_display(GetDisplay());
	}*/
}