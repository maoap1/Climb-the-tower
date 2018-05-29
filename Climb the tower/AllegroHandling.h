#pragma once

#include "Header.h"

/// <summary>
/// This is namespace AllegroHandling
/// In this namespace are useful functions made for handling with Allegro
/// </summary>
namespace AllegroHandling
{
	/// <summary>
	/// Loads the bitmap and resize it
	/// </summary>
	/// <param name="fileName">Name of the file.</param>
	/// <param name="width">New width</param>
	/// <param name="height">New height</param>
	/// <returns></returns>
	ALLEGRO_BITMAP* load_resized_bitmap(const char * fileName, float width, float height);
}

