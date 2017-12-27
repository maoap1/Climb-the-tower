#include "GameObject.h"

GameObject::GameObject(float x, float y)
{
	
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