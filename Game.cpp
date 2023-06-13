#include "Game.h"
#include <ctime>
#include <string>
using namespace std;


Game::Game() : window(nullptr), renderer(nullptr), player(nullptr), objects{}, enemies{}, collider{}, font1(nullptr), font2(nullptr), font3(nullptr) {
	started = false;
	ended = false;
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

	TTF_Init();

	player = new Player(renderer, "textures/rycerzykLeft.png", "textures/rycerzykRight.png");
	font1 = TTF_OpenFont("font/slkscr.ttf", 64);
	font2 = TTF_OpenFont("font/slkscr.ttf", 192);
	font3 = TTF_OpenFont("font/slkscr.ttf", 20);
	font4 = TTF_OpenFont("font/slkscr.ttf", 128);
	text_color = { 255, 255, 255 };
	levelmanager = new LevelManager(renderer);
	levelmanager->setTerrain(objects);
	levelmanager->setEnemies(enemies);
}

void Game::start(SDL_Event& event) {

	std::string title = "RISE FROM THE ASHES";
	SDL_Surface* surfTitle = TTF_RenderText_Solid(font4, title.c_str(), text_color);
	SDL_Texture* TitleTex = SDL_CreateTextureFromSurface(renderer, surfTitle);
	SDL_Rect src1, dst1, src2, dst2;
	src1.x = 0;
	src1.y = 0;
	src1.w = surfTitle->w;
	src1.h = surfTitle->h;
	dst1.x = 50;
	dst1.y = 250;
	dst1.w = surfTitle->w;
	dst1.h = surfTitle->h;
	SDL_FreeSurface(surfTitle);
	std::string instruction = "Press any button to start or ESC to quit";
	SDL_Surface* surfInst = TTF_RenderText_Solid(font3, instruction.c_str(), text_color);
	SDL_Texture* InstTex = SDL_CreateTextureFromSurface(renderer, surfInst);
	src2 = src1;
	src2.w = surfInst->w;
	src2.h = surfInst->h;
	dst2.x = dst1.x;
	dst2.y = dst1.y + dst1.h + 3;
	dst2.w = surfInst->w;
	dst2.h = surfInst->h;
	SDL_FreeSurface(surfInst);

	if (started == false) {
		SDL_RenderCopy(renderer, TitleTex, &src1, &dst1);
		SDL_RenderCopy(renderer, InstTex, &src2, &dst2);
	}

	if (event.type == SDL_KEYDOWN and event.key.repeat == 0) {
		if (SDLK_KP_ENTER) {
			player->setIfDead(false);
			started = true;
		}
	}
}

void Game::events(SDL_Event& event) {
	player->setCurrentSDLEvent(&event);
}


void Game::update()
{
	collider->Ground(player, objects);
	collider->Wall(player, objects);
	collider->GroundE(enemies, objects);
	collider->EndOfPlatform(enemies, objects);
	collider->WallE(enemies, objects);
	player->move();
	player->animate();
	player->die();
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
		item.attack(&item, player);
		item.die();
	}
	for (auto& item : enemies) {
		player->attack(&item, player);
	}
	progress();
}

void Game::progress() {

	bool alldead = false;
	for (auto& e : enemies) {
		if (e.getIfDead() == false) {
			alldead = false;
			break;
		}
		else if (e.getIfDead() == true) {
			alldead = true;
		}
	}

	if (player->getDst().x >= 1600 and alldead == true and levelmanager->getLevel()<4) {
		SDL_Rect dst;
		levelmanager->setLevel(levelmanager->getLevel() + 1);
		levelmanager->setTerrain(objects);
		levelmanager->setEnemies(enemies);
		dst = player->getDst();
		dst.x = 0;
		player->setDst(dst);
	}
	if (levelmanager->getLevel() > 3) {
		std::string ggwp = "GG WP";
		SDL_Surface* surfgg = TTF_RenderText_Solid(font2, ggwp.c_str(), text_color);
		SDL_Texture* ggTex = SDL_CreateTextureFromSurface(renderer, surfgg);
		SDL_Rect src, dst, src2, dst2;
		src.x = 0;
		src.y = 0;
		src.w = surfgg->w;
		src.h = surfgg->h;
		dst.x = 450;
		dst.y = 275;
		dst.w = surfgg->w;
		dst.h = surfgg->h;
		SDL_FreeSurface(surfgg);
		SDL_RenderCopy(renderer, ggTex, &src, &dst);
		ended = true;
		std::string instruction = "Press ESC to quit";
		SDL_Surface* surfInst = TTF_RenderText_Solid(font3, instruction.c_str(), text_color);
		SDL_Texture* InstTex = SDL_CreateTextureFromSurface(renderer, surfInst);
		src2 = src;
		src2.w = surfInst->w;
		src2.h = surfInst->h;
		dst2.x = dst.x;
		dst2.y = dst.y + dst.h + 3;
		dst2.w = surfInst->w;
		dst2.h = surfInst->h;
		SDL_FreeSurface(surfInst);
		SDL_RenderCopy(renderer, InstTex, &src2, &dst2);
	}
}

void Game::render()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
	if (ended == true) {
		return;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for (size_t i = 0; i < objects.size(); ++i) {
		objects[i].render();
	}

	for (size_t j = 0; j < enemies.size(); ++j) {
		if (enemies[j].getIfDead() == false)
			enemies[j].render();
	}

	if (player->getIfDead() == false) {
		player->render();
		player->renderSword();
	}

	showPlayerHP();
	death();
}

void Game::showPlayerHP() {
	if (started == true) {
		int tempHP = player->getHP();
		SDL_Color text_color = { 255, 255, 255 };
		std::string message = std::to_string(tempHP);
		message = "HP: " + message;
		SDL_Surface* surfHP = TTF_RenderText_Solid(font1, message.c_str(), text_color);
		SDL_Texture* HP = SDL_CreateTextureFromSurface(renderer, surfHP);

		SDL_Rect dst, src;

		src.x = 0;
		src.y = 0;
		src.w = surfHP->w;
		src.h = surfHP->h;
		dst.x = 0;
		dst.y = 0;
		dst.w = surfHP->w;
		dst.h = surfHP->h;

		SDL_RenderCopy(renderer, HP, &src, &dst);
		SDL_FreeSurface(surfHP);
	}
}

void Game::death() {
	if (player->getIfDead() == true and started == true) {
		text_color = { 255, 255, 255 };
		std::string message = "GAME OVER";
		SDL_Surface* surfMessage = TTF_RenderText_Solid(font2, message.c_str(), text_color);
		SDL_Texture* GameOver = SDL_CreateTextureFromSurface(renderer, surfMessage);
		SDL_Rect src, dst;
		src.x = 0;
		src.y = 0;
		src.w = surfMessage->w;
		src.h = surfMessage->h;
		dst.x = 200;
		dst.y = 250;
		dst.w = surfMessage->w;
		dst.h = surfMessage->h;
		SDL_FreeSurface(surfMessage);
		SDL_RenderCopy(renderer, GameOver, &src, &dst);
	}
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
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);
	TTF_CloseFont(font3);
	TTF_Quit();
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
	delete levelmanager;
	levelmanager = nullptr;

}