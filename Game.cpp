#include "Game.h"
#include "Collider.h"
#include <ctime>
using namespace std;


Game::Game() : window(nullptr), renderer(nullptr), player(nullptr), objects{}, collider{} {
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

	srand(time(NULL));

	player = new Player(renderer);
	setTer(objects);
	setEnemies(enemies);

}

void Game::events(SDL_Event& event) {
	player->setCurrentSDLEvent(&event);
}


void Game::update()
{
	//vector<character> characters(player, enemy)
	/*for (auto& character : characters)
	{
		vcharacter->movement();
		character->jump();
		character0 > gravity();

	}*/
	collider->Ground(player, objects);
	collider->Wall(player, objects);
	collider->GroundE(enemies, objects);
	collider->EndOfPlatform(enemies, objects);
	collider->WallE(enemies, objects);
	player->move();
	if (player->getGroundState() == false) {
		player->gravity();
	}
	for (auto& item : enemies) {
		if (item.getGroundState() == false) {
			item.gravity();
		}
		else if (item.getGroundState() == true) {
			item.move();
		}
	}
	//enemys->movement();

}

void Game::setTer(std::vector<Object>& vec) {
	//Object object1(renderer, "textures/DefaultowyBlok.png");
	for (int i = 0; i < 15; ++i) {
		//vec.push_back(object1);
		vec.emplace_back(renderer, "textures/DefaultowyBlok.png");
		//vec[i] = std::move(Object(renderer, "textures/DefaultowyBlok.png"));
		SDL_Rect newDst{};
		newDst.x = 128 + i * 64;
		newDst.y = 564 - 3 * 64;
		newDst.w = 64;
		newDst.h = 64;
		vec[i].setDst(newDst);
		if (i >= 6) {
			SDL_Rect newDst{};
			newDst.x = 64 + i * 64;
			newDst.y = 564;
			newDst.w = 64;
			newDst.h = 64;
			vec[i].setDst(newDst);
		}
	}
	vec.emplace_back(renderer, "textures/DefaultowyBlok.png");
	SDL_Rect newDst{};
	newDst.x = 128 + (13 * 64);
	newDst.y = 564 - 64;
	newDst.w = 64;
	newDst.h = 64;
	vec[15].setDst(newDst);
}

void Game::setEnemies(std::vector<Enemy>& vec) {
	for (int i = 0; i < 3; ++i) {
		vec.emplace_back(renderer);
		SDL_Rect newDst;
		newDst.x = (1 + i) * 257;
		newDst.y = 64;
		newDst.h = 64;
		newDst.w = 64;
		vec[i].setDst(newDst);
	}
}


void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for (size_t i = 0; i < objects.size(); ++i) {
		objects[i].render();
	}
	for (size_t j = 0; j < enemies.size(); ++j) {
		enemies[j].render();
	}
	player->render();
	SDL_RenderPresent(renderer);
}



void Game::clean()
{
	for (int i = 0; i < objects.size(); ++i) {
		objects[i].clean();
	}
	for (int i = 0; i < enemies.size(); ++i) {
		enemies[i].clean();
	}
	player->clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}

bool Game::running(SDL_Event& event) {
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

}