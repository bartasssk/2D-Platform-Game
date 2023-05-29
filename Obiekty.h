#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Object {
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect dst;
	SDL_Rect src;
public:
	Object(SDL_Renderer* rend, const char* FilePath);
	void render();
	SDL_Texture* getTex();
	~Object();
};