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
	SDL_Event* currentEvent;
public:
	Player(SDL_Renderer* rend);
	void gravity();
	void side();
	void movement();
	void jumping();
	void setDst(SDL_Rect newDst);
	void setCurrentSDLEvent(SDL_Event* event) { currentEvent = event; };
	//void render();
	~Player();
};