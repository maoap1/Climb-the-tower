#pragma once
#include "Header.h"
#include "widgetz\widgetz.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace Gui
{
	void InicializeGUI();
	int MainMenu();
	int PauseMenu();
	int QuitMenu();
}
