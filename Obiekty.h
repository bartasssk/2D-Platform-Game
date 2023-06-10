#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Object {
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect dst;
	SDL_Rect src;
public:
	Object(SDL_Renderer* rend, const char* FilePath);
	Object() = default;
	void render();
	void setDst(SDL_Rect newDst);
	void setSrc(SDL_Rect newSrc);
	void setTex(SDL_Texture* newTexture);
	void clean();
	SDL_Renderer* getRend();
	SDL_Rect getDst();
	SDL_Rect getSrc();
	SDL_Texture* getTex();
	~Object();
};