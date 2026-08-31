#include "Character.h"
#include "Enemy.h"
#include "Player.h"

const float GRAVITY = 2.0f;

Character::Character(SDL_Renderer* rend, const char* FilePath) : Object::Object(rend, FilePath), velX(0), velY(0), HP(3), grounded(false), CanIMoveLeft(true), CanIMoveRight(true), ifdead(false) {
	SDL_Rect CharacterDst{};
	CharacterDst.x = 128;
	CharacterDst.y = 128;
	CharacterDst.h = 64;
	CharacterDst.w = 64;
	setDst(CharacterDst);
}

Character::~Character() {}


void Character::setVelX(float p_velX) {
	velX = p_velX;
}

void Character::setVelY(float p_velY) {
	velY = p_velY;
}

void Character::setGroundState(bool state) {
	grounded = state;
}

void Character::setCanIMove(bool left, bool right) {
	CanIMoveLeft = left;
	CanIMoveRight = right;
}

void Character::setHP(int newHP) {
	HP = newHP;
}

float Character::getVelX() {
	return velX;
}
float Character::getVelY() {
	return velY;
}

int Character::getHP() {
	return HP;
}

bool Character::getGroundState() {
	return grounded;
}


bool Character::getIfDead() {
	return ifdead;
}

void Character::gravity(
) {
	if (getGroundState() == false) {
		float tempVelY = getVelY();
		SDL_Rect newDst = getDst();
		if (tempVelY > -30.0f) {
			tempVelY -= GRAVITY;
			setVelY(tempVelY);
		}
		newDst.y -= getVelY();
		setDst(newDst);
	}
}





