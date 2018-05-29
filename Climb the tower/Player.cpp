#include "Player.h"
#include "AnimationInitialization.h"
#include "GameMap.h"


//Player::Player(const char* fileName, const char* fileName2, float x, float y, Collider* collider, int collider_shift_x, int collider_shift_y, list<Collider*>* Colliders) : GameObject(fileName, x, y)
Player::Player(float x, float y, float lives) : GameObject(x, y)
{
	this->collider = new Collider(x + PLAYER_COLLIDER_SHIFT_X, y + PLAYER_COLLIDER_SHIFT_Y,
								  PLAYER_COLLIDER_HEIGHT, PLAYER_COLLIDER_WIDTH, "Spell");
	this->spellCollider = new Collider(x + PLAYER_SPELL_COLLIDER_SHIFT_X, y + PLAYER_SPELL_COLLIDER_SHIFT_Y,
								       PLAYER_SPELL_COLLIDER_HEIGHT, PLAYER_SPELL_COLLIDER_WIDTH, "Player",this);
	GameMap::Colliders.push_back(this->collider);
	GameMap::Colliders.push_back(this->spellCollider);

	using namespace AnimationInitialization;

	vector<int> HorizontalFrameDelays = { 6, 4, 6 };
	vector<int> VerticalFrameDelays = { 8, 8 };

	this->RunLeft = new Animation(&PlayerLeft, &PlayerLeftAttack, HorizontalFrameDelays);
	this->RunRight = new Animation(&PlayerRight, &PlayerRightAttack, HorizontalFrameDelays);
	this->RunUp = new Animation(&PlayerUp, &PlayerUpAttack, VerticalFrameDelays);
	this->RunDown = new Animation(&PlayerDown, &PlayerDownAttack, VerticalFrameDelays);

	this->IdleLeft = new Animation(PlayerLeft[2], PlayerLeftAttack[2]);
	this->IdleRight = new Animation(PlayerRight[2], PlayerRightAttack[2]);
	this->IdleUp = new Animation(PlayerUpIdle, PlayerUpIdleAttack);
	this->IdleDown = new Animation(PlayerDownIdle, PlayerDownIdleAttack);

	lastDirection = ID_DOWN;
	moreDirections = false;
	attacked = false;
	animAttacked = false;
	currentAttackFrame = 0;

	this->lives = lives;
	living = true;
}

void Player::Draw()
{
	if (lives <= 0)
	{
		living = false;
	}
	if (attacked)
	{
		currentAttackFrame++;
		if (currentAttackFrame > attackDelay)
		{
			attacked = false;
		}
		if (animAttacked)
		{
			if (currentAttackFrame > attackAnimDelay)
			{
				animAttacked = false;
			}
		}
	}

	ALLEGRO_BITMAP* currentBitmap = 0;

	if (moved)
	{
		switch (lastDirection)
		{
		case ID_LEFT:
			currentBitmap = RunLeft->GetNext(animAttacked);
			break;
		case ID_UP:
			currentBitmap = RunUp->GetNext(animAttacked);
			break;
		case ID_RIGHT:
			currentBitmap = RunRight->GetNext(animAttacked);
			break;
		case ID_DOWN:
			currentBitmap = RunDown->GetNext(animAttacked);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (lastDirection)
		{
		case ID_LEFT:
			currentBitmap = IdleLeft->GetNext(animAttacked);
			break;
		case ID_UP:
			currentBitmap = IdleUp->GetNext(animAttacked);
			break;
		case ID_RIGHT:
			currentBitmap = IdleRight->GetNext(animAttacked);
			break;
		case ID_DOWN:
			currentBitmap = IdleDown->GetNext(animAttacked);
			break;
		default:
			break;
		}
	}

	al_draw_bitmap(currentBitmap, x, y, 0);
}

void Player::Move(int direction)
{
	moved = true;

	int xNew = x;
	int yNew = y;
	switch (direction)
	{
	case ID_LEFT:
		xNew -= speed;
		break;
	case ID_UP:
		yNew -= speed;
		break;
	case ID_RIGHT:
		xNew += speed;
		break;
	case ID_DOWN:
		yNew += speed;
		break;
	default:
		break;
	}
	collider->SetXY(xNew+PLAYER_COLLIDER_SHIFT_X, yNew+PLAYER_COLLIDER_SHIFT_Y); // check the new location for collisions
	for each (Collider* it in GameMap::Colliders)
	{
		if ((it != collider)&&(it->flag != "Spell")&&(it->flag != "Player"))
		{
			// check for collision
			if (collider->HasCollided(*it))
			{
				collider->SetXY(x+PLAYER_COLLIDER_SHIFT_X, y+PLAYER_COLLIDER_SHIFT_Y);
				return;
			}
		}
	}
	// if collision didnt occur
	x = xNew;
	y = yNew;
	spellCollider->SetXY(x + PLAYER_SPELL_COLLIDER_SHIFT_X, y + PLAYER_SPELL_COLLIDER_SHIFT_Y);
}

void Player::MoveUp()
{
	if ((!moreDirections)||(lastDirection == ID_DOWN)) // The second condition is bugfix
	{
		lastDirection = ID_UP;
	}
	Move(ID_UP);
}

void Player::MoveDown()
{
	if ((!moreDirections) || (lastDirection == ID_UP)) // The second condition is bugfix
	{
		lastDirection = ID_DOWN;
	}
	Move(ID_DOWN);
}

void Player::MoveLeft()
{
	if ((!moreDirections) || (lastDirection == ID_RIGHT)) // The second condition is bugfix
	{
		lastDirection = ID_LEFT;
	}
	Move(ID_LEFT);
}

void Player::MoveRight()
{
	if ((!moreDirections) || (lastDirection == ID_LEFT)) // The second condition is bugfix
	{
		lastDirection = ID_RIGHT;
	}
	Move(ID_RIGHT);
}

void Player::MoreDirections(bool moreDirections)
{
	this->moreDirections = moreDirections;
}

void Player::Attack(int spellID)
{
	if (!attacked)
	{
		attacked = true;
		animAttacked = true;

		switch (lastDirection)
		{
		case ID_LEFT:
			GameMap::CreateSpell(x, y, lastDirection, spellID);
			break;
		case ID_UP:
			GameMap::CreateSpell(x + 35, y, lastDirection, spellID);
			break;
		case ID_RIGHT:
			GameMap::CreateSpell(x + 35, y, lastDirection, spellID);
			break;
		case ID_DOWN:
			GameMap::CreateSpell(x + 1, y + 5, lastDirection, spellID);
			break;
		}

		currentAttackFrame = 0;
	}
	
}

float Player::Get_x()
{
	return x;
}
float Player::Get_y()
{
	return y;
}

void Player::Damage(int damageType, int value)
{
	lives -= value;
}

Player::~Player()
{
	delete RunLeft;
	delete RunRight;
	delete RunUp;
	delete RunDown;
	delete IdleLeft;
	delete IdleRight;
	delete IdleUp;
	delete IdleDown;
}