#include "Character.h"

Character::Character(SDL_Renderer* rend): Object::Object(rend, "textures/rycerzyk1.png"), velX(0), velY(0), HP(3), grounded(false) {
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





