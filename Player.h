#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Player {
private:
	SDL_Renderer* rend;
	SDL_Rect pos;
	SDL_Texture* tex;

	int velocityX;
	int velocityY;
public:
	Player(SDL_Renderer* rend, const char* imgpth, int x, int y);
	void gravity();
	void side();
	void movement();
	void jumping();
	~Player();
};