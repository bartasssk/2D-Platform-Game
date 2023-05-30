#include "Game.h"
#include "Player.h"
using namespace std;


Game::Game(): window(nullptr), renderer(nullptr), player(nullptr) {
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
	object = new Object(renderer, "textures/DefaultowyBlok.png");
}

void Game::events(SDL_Event &event) {
	player->movement(event);
	player->jumping(event);
	player->gravity();
}

void Game::update()
{
}

void Game::render()
{

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	player->render();
	object->render();
	/*setTer();*/
	SDL_RenderPresent(renderer);
}

//void Game::setTer() {
//	Object object(renderer, "textures/DefaultowyBlok.png");
//	for (int i = 0; i < 20; ++i) {
//		objects.push_back(object);
//		SDL_Rect newDst;
//		newDst.x = i * 64;
//		newDst.y = 564;
//		newDst.w = 64;
//		newDst.h = 64;
//		objects[i].setDst(newDst);
//		objects[i].render();
//	}
//}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}

bool Game::running(SDL_Event &event) {
		switch (event.type) {
		case SDL_QUIT: {
			return false;
			break;
		}
		case SDL_KEYDOWN: {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				return false;
				break;
			}
		}
		}
	return true;
}

SDL_Texture* Game::loadTex(const char* FilePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, FilePath);

	return texture;
}

Game::~Game() {
	delete player;
	player = nullptr;
	delete object;
	object = nullptr;
}