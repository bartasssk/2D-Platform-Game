#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Character.h"

class Collider;

class Player : public Character {
private:
	SDL_Event* currentEvent;
public:
	Player(SDL_Renderer* rend);
	void move() override;
	void gravity();
	void setCurrentSDLEvent(SDL_Event* event) { currentEvent = event; };
	~Player();
};