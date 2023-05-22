#include "Game.h"
#include "Player.h"

Player* player = nullptr;

Game::Game() {
	cnt = 0;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int isFullscreen = 0;

	if (fullscreen) {
		isFullscreen = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
	}

	player = new Player(renderer);
}

void Game::events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	player->movement(event);
	switch (event.type) {
	default: {
		break;
	}
	}
}

void Game::update()
{
}

void Game::render()
{

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}

bool Game::running() {
	SDL_Event quit;
	SDL_PollEvent(&quit);
		switch (quit.type) {
		case SDL_QUIT: {
			return false;
			break;
		}
		case SDL_KEYDOWN: {
			if (quit.key.keysym.sym == SDLK_ESCAPE) {
				return false;
				break;
			}
		}
		}
	return true;
}

Game::~Game() {}