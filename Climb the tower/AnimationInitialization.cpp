#include "AnimationInitialization.h"
#include "AllegroHandling.h"

#define MOVE_ANIMATION_LENGTH 3

vector<ALLEGRO_BITMAP*> FireballLeft;
vector<ALLEGRO_BITMAP*> FireballUp;
vector<ALLEGRO_BITMAP*> FireballRight;
vector<ALLEGRO_BITMAP*> FireballDown;



void AnimInit()
{
	typedef const char* moveFileNames[4][MOVE_ANIMATION_LENGTH];
	moveFileNames fireballFileNames =
	{
		{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Left
		{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Up
		{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Right
		{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Down
	};

	vector<vector<ALLEGRO_BITMAP*>*> vectors;
	vector<int> lenghts (4, MOVE_ANIMATION_LENGTH);
	vector<int> orientations = { ID_LEFT,ID_UP,ID_RIGHT,ID_DOWN };

	vectors.push_back(&FireballLeft);
	vectors.push_back(&FireballUp);
	vectors.push_back(&FireballRight);
	vectors.push_back(&FireballDown);


	moveFileNames* specificMoveFileNames = NULL;
	int width = FIREBALL_SIZE;
	int height = FIREBALL_SIZE;
	int orientation;


	specificMoveFileNames = &fireballFileNames;

	for (int i = 0; i < vectors.size(); i++)
	{
		orientation = orientations[i % 4];

		for (int j = 0; i < MOVE_ANIMATION_LENGTH; i++)
		{
			vectors[i]->push_back(AllegroHandling::load_resized_bitmap((*specificMoveFileNames)[orientation][j], width, height));
		}
	}

	/*for (int i = 0; i < MOVE_ANIMATION_LENGTH; i++)
	{
		fileNames.push_back((*specificMoveFileNames)[orientation][i]);
	}*/
/*
	for (auto it = sprites.begin(); it != sprites.end(); it++)
		*it = AllegroHandling::load_resized_bitmap("Resources/Fireball1.png", 5, 5);*/
}




//for (auto it = sprites.begin(); it != sprites.end(); it++) // or ++it?
//{
//	
//}
