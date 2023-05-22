#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Game {
private:
	int cnt;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void events();
	void update();
	void render();
	void clean();
	bool running();
};