#include "Player.h"
#include  "Game.h"


Player::Player(SDL_Renderer* rend) : Object::Object(rend, "textures/rycerzyk1.png"), velX(0), velY(0) {

	SDL_Rect PlayerDst{};
	PlayerDst.x = 10;
	PlayerDst.y = 500;
	PlayerDst.h = 64;
	PlayerDst.w = 64;
	sheight.y = PlayerDst.y;
	setDst(PlayerDst);
}

void Player::movement(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT: {
			velX -= 8;
			break;
		}
		case SDLK_RIGHT: {
			velX += 8;
			break;
		}
		}

	}
	else if (event.type == SDL_KEYUP and event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT: {
			velX += 8;
			break;
		}
		case SDLK_RIGHT: {
			velX -= 8;
			break;
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.x += velX;
	setDst(newDst);
}

void Player::jumping(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_UP: {
			if (getDst().y >= sheight.y - 320 and velY >= 0) {
				velY = 40;
			}
			break;
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.y -= velY;
	setDst(newDst);
	if (velY > 0 and getDst().y < sheight.y) {
		velY -= 3;
	}
}

void Player::gravity() {
	SDL_Rect newDst = getDst();
	if ((velY == 0 or velY < 0) and velY > -20 and getDst().y < sheight.y) {
		velY -= 4;
		newDst.y += velY;
		setDst(newDst);
	}
	else if (getDst().y >= sheight.y) {
		velY = 0;
		newDst.y = sheight.y;
		setDst(newDst);
	}
}

void Player::setDst(SDL_Rect newDst) {
	Object::setDst(newDst);
}

void Player::render() {
	SDL_Rect srcRect = getSrc();
	SDL_Rect dstRect = getDst();
	SDL_RenderCopy(getRend(), getTex(), &srcRect, &dstRect);
}

Player::~Player() {
	SDL_DestroyTexture(getTex());
	SDL_DestroyRenderer(getRend());
}

