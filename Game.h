#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include <vector>
#include "Character.h"
#include "Player.h"


class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player* player = nullptr;
	std::vector <Character> characters;
	std::vector <Object> objects;
	Collider *collider;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void events(SDL_Event &event);
	void update();
	void render();
	void setTer(std::vector <Object>& vec);
	void clean();
	bool running(SDL_Event &event);
	SDL_Texture* loadTex(const char* FilePath);
};