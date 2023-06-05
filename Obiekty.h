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
	void setDst(SDL_Rect newDst);
	SDL_Texture* getTex();
	SDL_Renderer* getRend();
	SDL_Rect getDst();
	SDL_Rect getSrc();
	~Object();
};