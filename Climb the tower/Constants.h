#pragma once

#pragma region GUI

#pragma region MainMenu
#define ID_START 1
#define ID_QUIT 2
#define ID_CONTROLS 3
#define ID_BACK 4
#define ID_CONTINUE 5
#define BUTTON_WIDTH_MULTIPLIER 0.3
#define BUTTON_HEIGHT_MULTIPLIER 0.15
#define TEXT_WIDTH_MULTIPLIER 0.5
#define TEXT_HEIGHT_MULTIPLIER 0.05
#pragma endregion


#pragma endregion

#pragma region Graphics

#define FPS 60
#define WALL_SIZE 75
#define PLAYER_SIZE 90
#define SPELL_SIZE 50
#define SLIME_SIZE 60
#define PLAYER_INIT_ATTACK_ANIM_DELAY 30 //5 for testing // 30 originally
#define START_LOCATION_Y 9
#pragma endregion

#pragma region Animations

#define PLAYER_TYPES_OF_ANIMATIONS 2
#define PLAYER_MOVE_HORIZONTALLY_LENGTH 3
#define PLAYER_MOVE_VERTICALLY_LENGTH 2
#define SPELL_MOVE_LENGTH 3
#define SPELL_DEATH_LENGTH 5
#define SLIME_ANIM_LENGTH 10
#define SLIME_ANIM_ADDITIONAL 4

#pragma endregion

#pragma region Colliders

#pragma region Player colliders

#define PLAYER_COLLIDER_SHIFT_X 15
#define PLAYER_COLLIDER_SHIFT_Y 9
#define PLAYER_COLLIDER_WIDTH 55
#define PLAYER_COLLIDER_HEIGHT 70

#define PLAYER_SPELL_COLLIDER_SHIFT_X 36
#define PLAYER_SPELL_COLLIDER_SHIFT_Y 9
#define PLAYER_SPELL_COLLIDER_WIDTH 18
#define PLAYER_SPELL_COLLIDER_HEIGHT 70

#pragma endregion

#pragma region Spell colliders


#pragma endregion

#pragma region Slime collider

#define SLIME_COLLIDER_SHIFT_X 2
#define SLIME_COLLIDER_SHIFT_Y 4
#define SLIME_COLLIDER_WIDTH 58
#define SLIME_COLLIDER_HEIGHT 54

#pragma endregion

#pragma endregion

#pragma region Player stats

#define PLAYER_SPEED 2
#define PLAYER_INIT_ATTACK_DELAY 50 //5 for testing // 50 originally

#pragma endregion

#pragma region Other stats

#define SPELL_DAMAGE 10
#define BURNING_DAMAGE 0.02
#define SPELL_SPEED 5
#define SLIME_SPEED 1
#define SLIME_HEALTH 30
#define SLIME_SPEED_RECOVERY 0.005
#define SLIME_HITTED_ANIM_DELAY 25
#define SLIME_ATTACK_DELAY 60
#define AGGRO_INIT_DISTANCE 350
#define AGGRO_MAX_DISTANCE 500

#pragma endregion

#pragma region ID_DIRECTION

#define ID_LEFT 0
#define ID_UP 1
#define ID_RIGHT 2
#define ID_DOWN 3

#pragma endregion

#pragma region ID_SPELLS

#define ID_FIREBALL 1
#define ID_WATERBLAST 2
#define ID_ARCANEBALL 3
#define ID_SLIMEBALL 4

#pragma endregion

#pragma region Other
#define SPELLS_COUNT 4
#define NUMBER_OF_ORIENTATIONS 4
#define NUMBER_OF_KEYS 7
#pragma endregion