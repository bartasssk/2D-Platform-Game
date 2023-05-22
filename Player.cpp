#include "Player.h"
#include  "Game.h"

Player::Player(SDL_Renderer* renderer): velX(0), velY(0){
	rend = renderer;
	SDL_Surface* tempSurf = IMG_Load("textures/kwadrat1.png");
	tex = SDL_CreateTextureFromSurface(rend, tempSurf);
	SDL_FreeSurface(tempSurf);
	dst.h = 200;
	dst.w = 200;
	dst.x = SCREEN_WIDTH/2 - 200;
	dst.y = SCREEN_HEIGHT/2 -200;
}

void Player::movement(SDL_Event &event) {
		if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
			switch (event.key.keysym.sym) {
			case SDLK_UP: {
				velY += -1;
				break;
			}
			case SDLK_DOWN: {
				velY += 1;
				break;
			}
			case SDLK_LEFT: {
				velX += -1;
				break;
			}
			case SDLK_RIGHT: {
				velX += 1;
				break;
			}
			}
		}
		else if (event.type == SDL_KEYUP and event.key.repeat == 0) {
			switch (event.key.keysym.sym) {
			case SDLK_UP: {
				velY += 1;
				break;
			}
			case SDLK_DOWN: {
				velY += -1;
				break;
			}
			case SDLK_LEFT: {
				velX += 1;
				break;
			}
			case SDLK_RIGHT: {
				velX += -1;
				break;
			}
			}
		}
		else if (dst.x < 0 or dst.x>1280) {
			dst.x -= velX;
		}
		else if (dst.y < 0 or dst.y > 720) {
			dst.y -= velY;
		}
		dst.y += velY;
		dst.x += velX;
}

void Player::render() {
	SDL_RenderCopy(rend, tex, NULL, &dst);
}

Player::~Player() {
	SDL_DestroyTexture;
	SDL_DestroyRenderer;
}
