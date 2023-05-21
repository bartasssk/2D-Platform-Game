#include "Player.h"

Player::Player(SDL_Renderer* rend, const char* imgpth, int x, int y): rend(rend), velocityX(0), velocityY(0) {
	SDL_Surface* tempSurf = IMG_Load("textures/kwadrat1.png");
	tex = SDL_CreateTextureFromSurface(rend, tempSurf);
	SDL_FreeSurface(tempSurf);

	pos.x = x;
	pos.y = y;
}
