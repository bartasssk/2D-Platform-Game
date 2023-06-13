#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Collider.h"
#include "LevelManager.h"

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player* player = nullptr;
	LevelManager* levelmanager;
	std::vector <Object> objects;
	std::vector <Enemy> enemies;
	Collider* collider;
	TTF_Font* font1;
	TTF_Font* font2;
	TTF_Font* font3;
	TTF_Font* font4;
	SDL_Color text_color{};
	bool started;
	bool ended;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void events(SDL_Event& event);
	void start(SDL_Event& event);
	void update();
	void render();
	void showPlayerHP();
	void death();
	void progress();
	void reset();
	void clean();
	bool running(SDL_Event& event);
	SDL_Texture* loadTex(const char* FilePath);
};