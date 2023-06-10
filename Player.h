#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Character.h"

class Player : public Character {
private:
	SDL_Event* currentEvent;
	SDL_Texture* leftTexture;
	SDL_Texture* rightTexture;
	SDL_Texture* swordLeft;
	SDL_Texture* swordRight;
	Object sword;
	bool hit;
	bool ifnulled;
	enum class State {STANDING, MOVING, JUMPING, ATTACKING};
	enum class Side {LEFT,RIGHT};
	State currentState;
	Side currentSide;
	int currentFrame;
	int standingDelay;
	int movingDelay;
	int swordDelay;

public:
	Player(SDL_Renderer* rend, const char* FilePathLeft, const char* FilePathRight);
	void move() override;
	void attack(Enemy *enemy, Player* player) override;
	void die() override;
	void animate();
	void renderSword();
	void setCurrentSDLEvent(SDL_Event* event) { currentEvent = event; };
	void setIfNulled(bool result);
	State getState();
	~Player();
};