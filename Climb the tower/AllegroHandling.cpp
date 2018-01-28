#include "AllegroHandling.h"

namespace AllegroHandling
{
	ALLEGRO_BITMAP* load_resized_bitmap(const char * fileName, float width, float height)
	{
		ALLEGRO_BITMAP* temp = al_load_bitmap(fileName);
		if (!temp) return NULL;
		ALLEGRO_BITMAP* image = al_create_bitmap(width, height);
		if (!image)
		{
			al_destroy_bitmap(temp);
			return NULL;
		}

		ALLEGRO_BITMAP* previous = al_get_target_bitmap();
		al_set_target_bitmap(image);
		al_draw_scaled_bitmap(temp, 0, 0, al_get_bitmap_width(temp), al_get_bitmap_height(temp), 0, 0, width, height, 0);
		al_set_target_bitmap(previous);

		al_destroy_bitmap(temp);
		return image;
	}
}