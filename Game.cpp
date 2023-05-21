#include "Game.h"


Game::Game() {
	cnt = 0;
}

SDL_Texture* playertex = nullptr;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int isFullscreen = 0;

	if (fullscreen == 1) {
		isFullscreen = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
	}

	SDL_Surface* tempSurf = IMG_Load("textures/stickman1.png");
	playertex = SDL_CreateTextureFromSurface(renderer, tempSurf);
	SDL_FreeSurface(tempSurf);
}

void Game::events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	default: {
		break;
	}
	}
}

void Game::update()
{
	cnt++;
	cout << cnt << endl;

}

void Game::render()
{

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderCopy(renderer, playertex, NULL, NULL);
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
	while (SDL_PollEvent(&quit)) {
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
	}
	return true;
}

Game::~Game() {}