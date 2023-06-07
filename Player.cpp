#include "Player.h"
#include "Collider.h"


const int PLAYER_SPEED = 8;
const int JUMP_VEL = 24;


Player::Player(SDL_Renderer* rend) : Character(rend), currentEvent(nullptr), ifnulled(false) {}

void Player::move() {
	int tempVelX = getVelX();
	int tempVelY = getVelY();
	if (currentEvent->type == SDL_KEYDOWN and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			if (getCanIMoveLeft() == true) {
				tempVelX -= PLAYER_SPEED;
				setVelX(tempVelX);
			}
			break;
		}
		case SDLK_RIGHT: {
			if (getCanIMoveRight() == true) {
				tempVelX += PLAYER_SPEED;
				setVelX(tempVelX);
			}
			break;
		}
		case SDLK_SPACE: {
			if (getGroundState() == true) {
				setCanIMove(true, true);
				tempVelY += JUMP_VEL;
				setVelY(tempVelY);
				setGroundState(false);
			}
			break;
		}
		}
	}
	else if (currentEvent->type == SDL_KEYUP and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			if (getVelX() < 0 or ifnulled == false) {
				tempVelX += PLAYER_SPEED;
				setVelX(tempVelX);
				ifnulled = false;
				break;
			}
		}
		case SDLK_RIGHT: {
			if (getVelX() > 0 or ifnulled == false) {
				tempVelX -= PLAYER_SPEED;
				setVelX(tempVelX);
				ifnulled = false;
				break;
			}
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.x += getVelX();
	newDst.y -= getVelY();
	setDst(newDst);
}

void Player::setIfNulled(bool result) {
	ifnulled = result;
}

Player::~Player() {
}

