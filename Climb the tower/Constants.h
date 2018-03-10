#pragma once

#pragma region Graphics

#define FPS 60
#define WALL_SIZE 75
#define PLAYER_SIZE 90
#define SPELL_SIZE 50
#define SLIME_SIZE 60
#define PLAYER_INIT_ATTACK_ANIM_DELAY 30 //5 for testing // 30 originally

#pragma endregion

#pragma region Animations

#define PLAYER_TYPES_OF_ANIMATIONS 2
#define PLAYER_MOVE_HORIZONTALLY_LENGTH 3
#define PLAYER_MOVE_VERTICALLY_LENGTH 2
#define SPELL_MOVE_LENGTH 3
#define SPELL_DEATH_LENGTH 5
#define SLIME_ANIM_LENGTH 10

#pragma endregion

#pragma region Colliders

#pragma region Player collider

#define PLAYER_COLLIDER_SHIFT_X 15
#define PLAYER_COLLIDER_SHIFT_Y 9
#define PLAYER_COLLIDER_WIDTH 70
#define PLAYER_COLLIDER_HEIGHT 55

#pragma endregion

#pragma region Spell colliders


#pragma endregion

#pragma endregion

#pragma region Player stats

#define PLAYER_SPEED 2
#define PLAYER_INIT_ATTACK_DELAY 50 //5 for testing // 50 originally

#pragma endregion

#pragma region Other stats

#define SPELL_SPEED 5

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
#pragma endregion