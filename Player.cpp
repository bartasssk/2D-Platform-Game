#include "Player.h"
#include  "Game.h"


Player::Player(SDL_Renderer* renderer): velX(0), velY(0){
	rend = renderer;
	SDL_Surface* tempSurf = IMG_Load("textures/rycerzyk1.png");
	tex = SDL_CreateTextureFromSurface(rend, tempSurf);
	SDL_FreeSurface(tempSurf);
	dst.h = 64;
	dst.w = 64;
	dst.x = 100;
	dst.y = 500;
	src.h = 64;
	src.w = 64;
	src.x = 0;
	src.y = 0;
	sheight.y = dst.y;
}

void Player::movement(SDL_Event &event) {
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
		dst.x += velX;
}

void Player::jumping(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_UP: {
			if (dst.y >= sheight.y - 320 and velY >= 0) {
				velY = 40;
			}
			break;
		}
		}
	}
	dst.y -= velY;
	if (velY > 0 and dst.y < sheight.y) {
		velY -= 3;
	}
}

void Player::gravity() {
		if ((velY == 0 or velY<0) and velY > -20 and dst.y<sheight.y) {
			velY -= 4;
			dst.y += velY;
		}
		else if (dst.y >= sheight.y ) {
			velY = 0;
			dst.y = sheight.y;
		}
}

void Player::render() {
	SDL_RenderCopy(rend, tex, &src, &dst);
}

Player::~Player() {
	SDL_DestroyTexture;
	SDL_DestroyRenderer;
}
