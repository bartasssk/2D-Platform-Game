#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Player {
private:
	SDL_Rect pos;
	SDL_Texture* tex;
public:
	Player();
	void draw();
	void position();
	void gravity();
	void side();
	void movement();
	void jumping();
	~Player();
};