#include "Character.h"

const int GRAVITY = 2;

Character::Character(SDL_Renderer* rend): Object::Object(rend, "textures/rycerzyk1.png"), velX(0), velY(0), HP(3), grounded(false), CanIMoveLeft(true), CanIMoveRight(true){
	SDL_Rect CharacterDst{};
	CharacterDst.x = 100;
	CharacterDst.y = 490;
	CharacterDst.h = 64;
	CharacterDst.w = 64;
	sheight.y = CharacterDst.y;
	setDst(CharacterDst);
}

Character::~Character() {}


void Character::setVelX(int p_velX) {
	velX = p_velX;
}

void Character::setVelY(int p_velY) {
	velY = p_velY;
}

void Character::setGroundState(bool state) {
	grounded = state;
}

void Character::setCanIMove(bool left, bool right) {
	CanIMoveLeft = left;
	CanIMoveRight = right;
}

int Character::getVelX() {
	return velX;
}
int Character::getVelY() {
	return velY;
}

SDL_Rect Character::getStartHeight() {
	return sheight;
}

bool Character::getGroundState() {
	return grounded;
}

bool Character::getCanIMoveRight() {
	return CanIMoveRight;
}

bool Character::getCanIMoveLeft() {
	return CanIMoveLeft;
}

void Character::gravity(
) {
	if (getGroundState() == false) {
		int tempVelY = getVelY();
		SDL_Rect newDst = getDst();
		if (tempVelY > -20) {
			tempVelY -= GRAVITY;
			setVelY(tempVelY);
			newDst.y -= getVelY();
			setDst(newDst);
		}
	}
}





