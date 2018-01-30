#pragma once

#define MOVE_ANIMATION_LENGTH 3
#define DEATH_ANIMATION_LENGTH 5

typedef const char* moveFileNames[4][MOVE_ANIMATION_LENGTH];
typedef const char* deathFileNames[4][DEATH_ANIMATION_LENGTH];

moveFileNames fireballFileNames =
{
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Left
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Up
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Right
	{ "Resources/Fireball1.png","Resources/Fireball2.png","Resources/Fireball3.png" }, // Down
};

deathFileNames fireballDeathFileNames =
{
	{ "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	"Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Left
	{ "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	"Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Up
	{ "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	"Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Right
	{ "Resources/Fireball_death1.png","Resources/Fireball_death2.png","Resources/Fireball_death3.png",
	"Resources/Fireball_death4.png","Resources/Fireball_death5.png" }, // Down
};