#pragma once
#include "Header.h"
#include "widgetz\widgetz.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace Gui
{
	/// <summary>
	/// Inicializes the GUI
	/// </summary>
	void InicializeGUI();

	/// <summary>
	/// Opens Main Menu
	/// </summary>
	int MainMenu();

	/// <summary>
	/// Opens Pause Menu
	/// </summary>
	int PauseMenu();

	/// <summary>
	/// Opens Game Over Menu
	/// </summary>
	int QuitMenu();

	/// <summary>
	/// Opens Game Win Menu
	/// </summary>
	int WinMenu();
}
