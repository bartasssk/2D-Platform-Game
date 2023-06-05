#include "Player.h"
#include  "Game.h"

const int PLAYER_SPEED = 8;
const int JUMP_VEL = 40;
const int GRAVITY = 3;


Player::Player(SDL_Renderer* rend) : Object::Object(rend, "textures/rycerzyk1.png"), velX(0), velY(0), currentEvent(nullptr) {

	SDL_Rect PlayerDst{};
	PlayerDst.x = 10;
	PlayerDst.y = 500;
	PlayerDst.h = 64;
	PlayerDst.w = 64;
	sheight.y = PlayerDst.y;
	setDst(PlayerDst);
}

void Player::movement() {
	if (currentEvent->type == SDL_KEYDOWN and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			velX -= PLAYER_SPEED;
			break;
		}
		case SDLK_RIGHT: {
			velX += PLAYER_SPEED;
			break;
		}
		}

	}
	else if (currentEvent->type == SDL_KEYUP and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			velX += PLAYER_SPEED;
			break;
		}
		case SDLK_RIGHT: {
			velX -= PLAYER_SPEED;
			break;
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.x += velX;
	setDst(newDst);
}

void Player::jumping() {
	if (currentEvent->type == SDL_KEYDOWN and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_UP: {
			if (getDst().y >= sheight.y - 320 and velY >= 0) {
				velY = JUMP_VEL;
			}
			break;
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.y -= velY;
	setDst(newDst);
	if (velY > 0 and getDst().y < sheight.y) {
		velY -= GRAVITY;
	}
}

void Player::gravity() {
	SDL_Rect newDst = getDst();
	if ((velY == 0 or velY < 0) and velY > -20 and getDst().y < sheight.y) {
		velY -= GRAVITY;
		newDst.y += velY;
		setDst(newDst);
	}
	else if (getDst().y >= sheight.y) {
		//velY = 0;
		newDst.y = sheight.y;
		//setDst(newDst);
	}
}

void Player::setDst(SDL_Rect newDst) {
	Object::setDst(newDst);
}

//void Player::render() {
//	SDL_Rect srcRect = getSrc();
//	SDL_Rect dstRect = getDst();
//	SDL_RenderCopy(getRend(), getTex(), &srcRect, &dstRect);
//}

Player::~Player() {
}

