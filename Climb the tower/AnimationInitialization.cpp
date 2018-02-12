#include "AnimationInitialization.h"
#include "AllegroHandling.h"


namespace AnimationInitialization
{

#pragma region Spell movements
	vector<ALLEGRO_BITMAP*> FireballLeft;
	vector<ALLEGRO_BITMAP*> FireballUp;
	vector<ALLEGRO_BITMAP*> FireballRight;
	vector<ALLEGRO_BITMAP*> FireballDown;

	vector<ALLEGRO_BITMAP*> WaterblastLeft;
	vector<ALLEGRO_BITMAP*> WaterblastUp;
	vector<ALLEGRO_BITMAP*> WaterblastRight;
	vector<ALLEGRO_BITMAP*> WaterblastDown;

	vector<ALLEGRO_BITMAP*> ArcaneballLeft;
	vector<ALLEGRO_BITMAP*> ArcaneballUp;
	vector<ALLEGRO_BITMAP*> ArcaneballRight;
	vector<ALLEGRO_BITMAP*> ArcaneballDown;
#pragma endregion

#pragma region Spell deaths
	vector<ALLEGRO_BITMAP*> FireballDeathLeft;
	vector<ALLEGRO_BITMAP*> FireballDeathUp;
	vector<ALLEGRO_BITMAP*> FireballDeathRight;
	vector<ALLEGRO_BITMAP*> FireballDeathDown;

	vector<ALLEGRO_BITMAP*> WaterblastDeathLeft;
	vector<ALLEGRO_BITMAP*> WaterblastDeathUp;
	vector<ALLEGRO_BITMAP*> WaterblastDeathRight;
	vector<ALLEGRO_BITMAP*> WaterblastDeathDown;

	vector<ALLEGRO_BITMAP*> ArcaneballDeathLeft;
	vector<ALLEGRO_BITMAP*> ArcaneballDeathUp;
	vector<ALLEGRO_BITMAP*> ArcaneballDeathRight;
	vector<ALLEGRO_BITMAP*> ArcaneballDeathDown;
#pragma endregion

	/// <summary>
	/// Initialize vectors of bitmaps for move animations of spells
	/// </summary>
	void SpellsMoveInit()
	{
		const char* SpellFileNames[NUMBER_OF_ORIENTATIONS * SPELLS_COUNT][SPELL_MOVE_LENGTH] =

		{
			{ "Resources/Fireball_left_1.png","Resources/Fireball_left_2.png","Resources/Fireball_left_3.png" },	// Fireball Left
			{ "Resources/Fireball_up_1.png","Resources/Fireball_up_2.png","Resources/Fireball_up_3.png" },			// Fireball Up
			{ "Resources/Fireball_right_1.png","Resources/Fireball_right_2.png","Resources/Fireball_right_3.png" }, // Fireball Right
			{ "Resources/Fireball_down_1.png","Resources/Fireball_down_2.png","Resources/Fireball_down_3.png" },	// Fireball Down

			{ "Resources/Waterblast_left_1.png","Resources/Waterblast_left_2.png","Resources/Waterblast_left_3.png" },		// Waterblast Left
			{ "Resources/Waterblast_up_1.png","Resources/Waterblast_up_2.png","Resources/Waterblast_up_3.png" },			// Waterblast Up
			{ "Resources/Waterblast_right_1.png","Resources/Waterblast_right_2.png","Resources/Waterblast_right_3.png" },	// Waterblast Right
			{ "Resources/Waterblast_down_1.png","Resources/Waterblast_down_2.png","Resources/Waterblast_down_3.png" },		// Waterblast Down

			{ "Resources/Arcaneball_left_1.png","Resources/Arcaneball_left_2.png","Resources/Arcaneball_left_3.png" },		// Arcaneball Left
			{ "Resources/Arcaneball_up_1.png","Resources/Arcaneball_up_2.png","Resources/Arcaneball_up_3.png" },			// Arcaneball Up
			{ "Resources/Arcaneball_right_1.png","Resources/Arcaneball_right_2.png","Resources/Arcaneball_right_3.png" },	// Arcaneball Right
			{ "Resources/Arcaneball_down_1.png","Resources/Arcaneball_down_2.png","Resources/Arcaneball_down_3.png" },		// Arcaneball Down
		};


		vector<vector<ALLEGRO_BITMAP*>*> vectors;

		vectors.push_back(&FireballLeft);
		vectors.push_back(&FireballUp);
		vectors.push_back(&FireballRight);
		vectors.push_back(&FireballDown);
		vectors.push_back(&WaterblastLeft);
		vectors.push_back(&WaterblastUp);
		vectors.push_back(&WaterblastRight);
		vectors.push_back(&WaterblastDown);
		vectors.push_back(&ArcaneballLeft);
		vectors.push_back(&ArcaneballUp);
		vectors.push_back(&ArcaneballRight);
		vectors.push_back(&ArcaneballDown);

		for (int i = 0; i < vectors.size(); i++)
		{
			for (int j = 0; j < SPELL_MOVE_LENGTH; j++)
			{
				vectors[i]->push_back(AllegroHandling::load_resized_bitmap((SpellFileNames)[i][j], SPELL_SIZE, SPELL_SIZE));
			}
		}
	}
	
	/// <summary>
	/// Initialize vectors of bitmaps for death animations of spells
	/// </summary>
	void SpellsDeathInit()
	{
		const char* FileNames[NUMBER_OF_ORIENTATIONS * SPELLS_COUNT][SPELL_DEATH_LENGTH] =
		{
			{ "Resources/Fireball_left_death1.png","Resources/Fireball_left_death2.png","Resources/Fireball_left_death3.png",
			"Resources/Fireball_left_death4.png","Resources/Fireball_left_death5.png" },	// Fireball Death Left
			{ "Resources/Fireball_up_death1.png","Resources/Fireball_up_death2.png","Resources/Fireball_up_death3.png",
			"Resources/Fireball_up_death4.png","Resources/Fireball_up_death5.png" },		// Fireball Death Up
			{ "Resources/Fireball_right_death1.png","Resources/Fireball_right_death2.png","Resources/Fireball_right_death3.png",
			"Resources/Fireball_right_death4.png","Resources/Fireball_right_death5.png" },	// Fireball Death Right
			{ "Resources/Fireball_down_death1.png","Resources/Fireball_down_death2.png","Resources/Fireball_down_death3.png",
			"Resources/Fireball_down_death4.png","Resources/Fireball_down_death5.png" },	// Fireball Death Down

			{ "Resources/Waterblast_left_death1.png","Resources/Waterblast_left_death2.png","Resources/Waterblast_left_death3.png",
			"Resources/Waterblast_left_death4.png","Resources/Waterblast_left_death5.png" },	// Waterblast Death Left
			{ "Resources/Waterblast_up_death1.png","Resources/Waterblast_up_death2.png","Resources/Waterblast_up_death3.png",
			"Resources/Waterblast_up_death4.png","Resources/Waterblast_up_death5.png" },		// Waterblast Death Up
			{ "Resources/Waterblast_right_death1.png","Resources/Waterblast_right_death2.png","Resources/Waterblast_right_death3.png",
			"Resources/Waterblast_right_death4.png","Resources/Waterblast_right_death5.png" },	// Waterblast Death Right
			{ "Resources/Waterblast_down_death1.png","Resources/Waterblast_down_death2.png","Resources/Waterblast_down_death3.png",
			"Resources/Waterblast_down_death4.png","Resources/Waterblast_down_death5.png" },	// Waterblast Death Down

			{ "Resources/Arcaneball_left_death1.png","Resources/Arcaneball_left_death2.png","Resources/Arcaneball_left_death3.png",
			"Resources/Arcaneball_left_death4.png","Resources/Arcaneball_left_death5.png" },	// Arcaneball Death Left
			{ "Resources/Arcaneball_up_death1.png","Resources/Arcaneball_up_death2.png","Resources/Arcaneball_up_death3.png",
			"Resources/Arcaneball_up_death4.png","Resources/Arcaneball_up_death5.png" },		// Arcaneball Death Up
			{ "Resources/Arcaneball_right_death1.png","Resources/Arcaneball_right_death2.png","Resources/Arcaneball_right_death3.png",
			"Resources/Arcaneball_right_death4.png","Resources/Arcaneball_right_death5.png" },	// Arcaneball Death Right
			{ "Resources/Arcaneball_down_death1.png","Resources/Arcaneball_down_death2.png","Resources/Arcaneball_down_death3.png",
			"Resources/Arcaneball_down_death4.png","Resources/Arcaneball_down_death5.png" },	// Arcaneball Death Down

		};


		vector<vector<ALLEGRO_BITMAP*>*> vectors;

		vectors.push_back(&FireballDeathLeft);
		vectors.push_back(&FireballDeathUp);
		vectors.push_back(&FireballDeathRight);
		vectors.push_back(&FireballDeathDown);
		vectors.push_back(&WaterblastDeathLeft);
		vectors.push_back(&WaterblastDeathUp);
		vectors.push_back(&WaterblastDeathRight);
		vectors.push_back(&WaterblastDeathDown);
		vectors.push_back(&ArcaneballDeathLeft);
		vectors.push_back(&ArcaneballDeathUp);
		vectors.push_back(&ArcaneballDeathRight);
		vectors.push_back(&ArcaneballDeathDown);

		for (int i = 0; i < vectors.size(); i++)
		{
			for (int j = 0; j < SPELL_DEATH_LENGTH; j++)
			{
				vectors[i]->push_back(AllegroHandling::load_resized_bitmap((FileNames)[i][j], SPELL_SIZE, SPELL_SIZE));
			}
		}
	}

	void AnimInit()
	{
		SpellsMoveInit();
		SpellsDeathInit();
	}
}