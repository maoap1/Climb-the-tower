#include "AnimationInitialization.h"
#include "AllegroHandling.h"


namespace AnimationInitialization
{
#pragma region Slime
	vector<ALLEGRO_BITMAP*> Slime;
	vector<ALLEGRO_BITMAP*> SlimeAttack;
#pragma endregion

#pragma region Player
	vector<ALLEGRO_BITMAP*> PlayerLeft;
	vector<ALLEGRO_BITMAP*> PlayerLeftAttack;
	vector<ALLEGRO_BITMAP*> PlayerRight;
	vector<ALLEGRO_BITMAP*> PlayerRightAttack;
	vector<ALLEGRO_BITMAP*> PlayerUp;
	vector<ALLEGRO_BITMAP*> PlayerUpAttack;
	vector<ALLEGRO_BITMAP*> PlayerDown;
	vector<ALLEGRO_BITMAP*> PlayerDownAttack;

	ALLEGRO_BITMAP* PlayerUpIdle;
	ALLEGRO_BITMAP* PlayerUpIdleAttack;
	ALLEGRO_BITMAP* PlayerDownIdle;
	ALLEGRO_BITMAP* PlayerDownIdleAttack;
#pragma endregion

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

	vector<ALLEGRO_BITMAP*> SlimeballLeft;
	vector<ALLEGRO_BITMAP*> SlimeballUp;
	vector<ALLEGRO_BITMAP*> SlimeballRight;
	vector<ALLEGRO_BITMAP*> SlimeballDown;
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

	vector<ALLEGRO_BITMAP*> SlimeballDeathLeft;
	vector<ALLEGRO_BITMAP*> SlimeballDeathUp;
	vector<ALLEGRO_BITMAP*> SlimeballDeathRight;
	vector<ALLEGRO_BITMAP*> SlimeballDeathDown;
#pragma endregion

	/// <summary>
	/// Initialize vectors of bitmaps for horizontal animations of Player
	/// </summary>
	void PlayerHorizontalInit()
	{

		const char* PlayerHorizontalFileNames[PLAYER_TYPES_OF_ANIMATIONS*NUMBER_OF_ORIENTATIONS/2 ][PLAYER_MOVE_HORIZONTALLY_LENGTH] =

		{
			{ "Resources/Player_left_going1.png","Resources/Player_left.png", "Resources/Player_left_going2.png" },		// Player Left
			{ "Resources/Player_right_going1.png","Resources/Player_right.png", "Resources/Player_right_going2.png" },	// Player Right
			{ "Resources/Player_left_going1_attack.png","Resources/Player_left_attack.png",
			  "Resources/Player_left_going2_attack.png" },																// Player Left Attack
			{ "Resources/Player_right_going1_attack.png","Resources/Player_right_attack.png",
			  "Resources/Player_right_going2_attack.png" },																// Player Right Attack
		};

		vector<vector<ALLEGRO_BITMAP*>*> vectors;

		vectors.push_back(&PlayerLeft);
		vectors.push_back(&PlayerRight);
		vectors.push_back(&PlayerLeftAttack);
		vectors.push_back(&PlayerRightAttack);

		for (int i = 0; i < vectors.size(); i++)
		{
			for (int j = 0; j < PLAYER_MOVE_HORIZONTALLY_LENGTH; j++)
			{
				vectors[i]->push_back(AllegroHandling::load_resized_bitmap((PlayerHorizontalFileNames)[i][j], PLAYER_SIZE, PLAYER_SIZE));
			}
		}

	}

	/// <summary>
	/// Initialize vectors of bitmaps for vertical animations of Player
	/// </summary>
	void PlayerVerticalInit()
	{
		const char* PlayerVerticalFileNames[PLAYER_TYPES_OF_ANIMATIONS*NUMBER_OF_ORIENTATIONS / 2][PLAYER_MOVE_VERTICALLY_LENGTH] =

		{
			{ "Resources/Player_back_going1.png", "Resources/Player_back_going2.png" },					// Player Up ... back is really Up
			{ "Resources/Player_front_going1.png", "Resources/Player_front_going2.png" },				// Player Down
			{ "Resources/Player_back_going1_attack.png" ,"Resources/Player_back_going2_attack.png" },	// Player Up Attack
			{ "Resources/Player_front_going1_attack.png", "Resources/Player_front_going2_attack.png" },	// Player Down Attack
		};

		vector<vector<ALLEGRO_BITMAP*>*> vectors;

		vectors.push_back(&PlayerUp);
		vectors.push_back(&PlayerDown);
		vectors.push_back(&PlayerUpAttack);
		vectors.push_back(&PlayerDownAttack);

		for (int i = 0; i < vectors.size(); i++)
		{
			for (int j = 0; j < PLAYER_MOVE_VERTICALLY_LENGTH; j++)
			{
				vectors[i]->push_back(AllegroHandling::load_resized_bitmap((PlayerVerticalFileNames)[i][j], PLAYER_SIZE, PLAYER_SIZE));
			}
		}

		PlayerUpIdle = AllegroHandling::load_resized_bitmap("Resources/Player_back.png", PLAYER_SIZE, PLAYER_SIZE);
		PlayerUpIdleAttack = AllegroHandling::load_resized_bitmap("Resources/Player_back_attack.png", PLAYER_SIZE, PLAYER_SIZE);
		PlayerDownIdle = AllegroHandling::load_resized_bitmap("Resources/Player_front.png", PLAYER_SIZE, PLAYER_SIZE);
		PlayerDownIdleAttack = AllegroHandling::load_resized_bitmap("Resources/Player_front_attack.png", PLAYER_SIZE, PLAYER_SIZE);
	}


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

			{ "Resources/Slimeball_left_1.png","Resources/Slimeball_left_2.png","Resources/Slimeball_left_3.png" },			// Slimeball Left
			{ "Resources/Slimeball_up_1.png","Resources/Slimeball_up_2.png","Resources/Slimeball_up_3.png" },				// Slimeball Up
			{ "Resources/Slimeball_right_1.png","Resources/Slimeball_right_2.png","Resources/Slimeball_right_3.png" },		// Slimeball Right
			{ "Resources/Slimeball_down_1.png","Resources/Slimeball_down_2.png","Resources/Slimeball_down_3.png" },			// Slimeball Down
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
		vectors.push_back(&SlimeballLeft);
		vectors.push_back(&SlimeballUp);
		vectors.push_back(&SlimeballRight);
		vectors.push_back(&SlimeballDown);

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

			{ "Resources/Slimeball_left_death1.png","Resources/Slimeball_left_death2.png","Resources/Slimeball_left_death3.png",
			"Resources/Slimeball_left_death4.png","Resources/Slimeball_left_death5.png" },		// Slimeball Death Left
			{ "Resources/Slimeball_up_death1.png","Resources/Slimeball_up_death2.png","Resources/Slimeball_up_death3.png",
			"Resources/Slimeball_up_death4.png","Resources/Slimeball_up_death5.png" },			// Slimeball Death Up
			{ "Resources/Slimeball_right_death1.png","Resources/Slimeball_right_death2.png","Resources/Slimeball_right_death3.png",
			"Resources/Slimeball_right_death4.png","Resources/Slimeball_right_death5.png" },	// Slimeball Death Right
			{ "Resources/Slimeball_down_death1.png","Resources/Slimeball_down_death2.png","Resources/Slimeball_down_death3.png",
			"Resources/Slimeball_down_death4.png","Resources/Slimeball_down_death5.png" },		// Slimeball Death Down
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
		vectors.push_back(&SlimeballDeathLeft);
		vectors.push_back(&SlimeballDeathUp);
		vectors.push_back(&SlimeballDeathRight);
		vectors.push_back(&SlimeballDeathDown);

		for (int i = 0; i < vectors.size(); i++)
		{
			for (int j = 0; j < SPELL_DEATH_LENGTH; j++)
			{
				vectors[i]->push_back(AllegroHandling::load_resized_bitmap((FileNames)[i][j], SPELL_SIZE, SPELL_SIZE));
			}
		}
	}

	/// <summary>
	/// Initialize vectors of bitmaps for move animation of slime
	/// </summary>
	void SlimeInit()
	{
		// THIS IS SLIME ANIMATION FOR TESTING
		for (int i = 0; i < SLIME_ANIM_LENGTH; i++)
		{
			Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime1.png", SLIME_SIZE, SLIME_SIZE));
			Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime2.png", SLIME_SIZE, SLIME_SIZE));
		}
		Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime3.png", SLIME_SIZE, SLIME_SIZE));
		Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime4.png", SLIME_SIZE, SLIME_SIZE));
		Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime5.png", SLIME_SIZE, SLIME_SIZE));
		Slime.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime2.png", SLIME_SIZE, SLIME_SIZE));
		//END
	}

	void SlimeAttackInit()
	{
		//THIS IS SLIME ATTACK ANIMATION FOR TESTING
		for (int i = 0; i < 2 * SLIME_ANIM_LENGTH + SLIME_ANIM_ADDITIONAL; i++)
		{
			SlimeAttack.push_back(AllegroHandling::load_resized_bitmap("Resources/Slime_attack.png", SLIME_SIZE, SLIME_SIZE));
		}
		//END
	}

	/// <summary>
	/// This function calls all the others in this namespace
	/// </summary>
	void AnimInit()
	{
		PlayerHorizontalInit();
		PlayerVerticalInit();
		SpellsMoveInit();
		SpellsDeathInit();
		SlimeInit();
		SlimeAttackInit();
	}
}