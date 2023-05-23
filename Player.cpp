#include "Player.h"
#include  "Game.h"


Player::Player(SDL_Renderer* renderer): velX(0), velY(0){
	rend = renderer;
	SDL_Surface* tempSurf = IMG_Load("textures/kwadrat1.png");
	tex = SDL_CreateTextureFromSurface(rend, tempSurf);
	SDL_FreeSurface(tempSurf);
	dst.h = 200;
	dst.w = 200;
	dst.x = 0;
	dst.y = 500;
	sheight.y = dst.y;
}

void Player::movement(SDL_Event &event) {
		if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT: {
					velX = -8;
					break;
				}
				case SDLK_RIGHT: {
					velX = 8;
					break;
				}
				}
			
		}
		else if (event.type == SDL_KEYUP and event.key.repeat == 0) {
			switch (event.key.keysym.sym) {
			case SDLK_LEFT: {
				velX = 0;
				break;
			}
			case SDLK_RIGHT: {
				velX = 0;
				break;
			}
			}
		}
		else if (velX > 8) {
			velX = 8;
		}
		else if (velX < -8) {
			velX = -8;
		}
		dst.x += velX;
}

void Player::jumping(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_UP: {
			if (dst.y >= sheight.y - 320 and velY >= 0) {
				velY = 50;
			}
			break;
		}
		}
	}
	dst.y -= velY;
	if (velY > 0 and dst.y < sheight.y) {
		velY -= 5;
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
	SDL_RenderCopy(rend, tex, NULL, &dst);
}

Player::~Player() {
	SDL_DestroyTexture;
	SDL_DestroyRenderer;
}
