#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Obiekty.h"

class Player : public Object {
private:
	SDL_Rect sheight;

	int velX;
	int velY;
public:
	Player(SDL_Renderer* rend);
	void gravity();
	void side();
	void movement(SDL_Event &event);
	void jumping(SDL_Event &event);
	void setDst(SDL_Rect newDst);
	void render();
	~Player();
};