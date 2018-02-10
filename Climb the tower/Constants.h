#pragma once

#pragma region Graphics

#define FPS 60
#define WALL_SIZE 75
#define PLAYER_SIZE 90
#define FIREBALL_SIZE 50
#define PLAYER_INIT_ATTACK_ANIM_DELAY 30 //5 for testing

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
#define PLAYER_INIT_ATTACK_DELAY 50 //5 for testing

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

#pragma region ID_SPELL

//missiles
#define ID_ARCANE_MISSILE 1
#define ID_SLIME_BALL 2 
#define ID_MUD_BALL 3
#define ID_SNOW_BALL 4

//spells
#define ID_FIREBALL 5
#define ID_FROSTBOLT 6
#define ID_DEATH_BALL 7
#define ID_ARCANE_SPELL 8

#pragma endregion