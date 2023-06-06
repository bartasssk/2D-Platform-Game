#include "Player.h"
#include "Collider.h"


const int PLAYER_SPEED = 8;
const int JUMP_VEL = 24;
const int GRAVITY = 2;


Player::Player(SDL_Renderer* rend) : Character(rend), currentEvent(nullptr) {}

void Player::move() {
	int tempVelX = getVelX();
	int tempVelY = getVelY();
	if (currentEvent->type == SDL_KEYDOWN and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			tempVelX -= PLAYER_SPEED;
			setVelX(tempVelX);
			break;
		}
		case SDLK_RIGHT: {
			tempVelX += PLAYER_SPEED;
			setVelX(tempVelX);
			break;
		}
		case SDLK_SPACE: {
			if (getDst().y >= getStartHeight().y - 320 and tempVelY >= 0) {
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
			if (getVelX() != 0) {
				tempVelX += PLAYER_SPEED;
				setVelX(tempVelX);
				break;
			}
		}
		case SDLK_RIGHT: {
			if (getVelX() != 0) {
				tempVelX -= PLAYER_SPEED;
				setVelX(tempVelX);
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

void Player::gravity(
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

Player::~Player() {
}

