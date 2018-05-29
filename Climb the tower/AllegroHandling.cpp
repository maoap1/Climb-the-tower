#include "AllegroHandling.h"

namespace AllegroHandling
{
	/// <summary>
	/// Loads the bitmap and resize it
	/// </summary>
	/// <param name="fileName">Name of the file.</param>
	/// <param name="width">New width</param>
	/// <param name="height">New height</param>
	/// <returns></returns>
	ALLEGRO_BITMAP* load_resized_bitmap(const char * fileName, float width, float height)
	{
		ALLEGRO_BITMAP* temp = al_load_bitmap(fileName); // creates a temporary bitmap (= not resized)
		if (!temp) return NULL;
		ALLEGRO_BITMAP* image = al_create_bitmap(width, height); // creates an empty bitmap with right size
		if (!image)
		{
			al_destroy_bitmap(temp);
			return NULL;
		}

		ALLEGRO_BITMAP* previous = al_get_target_bitmap();
		al_set_target_bitmap(image);
		// next line draws an old temporary bitmap (= not resized) to the bigger one with GPU powered resizing
		al_draw_scaled_bitmap(temp, 0, 0, al_get_bitmap_width(temp), al_get_bitmap_height(temp), 0, 0, width, height, 0);
		al_set_target_bitmap(previous);

		al_destroy_bitmap(temp);
		return image;
	}
}