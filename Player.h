#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Player {
private:
	SDL_Renderer* rend;
	SDL_Rect dst;
	SDL_Texture* tex;

	int velX;
	int velY;
public:
	Player(SDL_Renderer* renderer);
	void render();
	void gravity();
	void side();
	void movement(SDL_Event &event);
	void jumping();
	~Player();
};