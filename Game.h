#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include "Obiekty.h"

class Player;
class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player* player = nullptr;
	Object* object = nullptr;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void events(SDL_Event &event);
	void update();
	void render();
	void clean();
	bool running(SDL_Event &event);
	SDL_Texture* loadTex(const char* FilePath);
};