#include "LevelManager.h"

LevelManager::LevelManager(SDL_Renderer* rend): renderer(rend), object(renderer, "textures/DefaultowyBlok.png") {
	level = 1;
}

const int BLOCK_WIDTH = 64;

void LevelManager::setTerrain(std::vector<Object>& objects) {
	if (level == 1) {
		for (int i = 0; i < 24; ++i) {
			objects.emplace_back(renderer, "textures/DefaultowyBlok.png");
		}
		SDL_Rect dst;
		dst = objects[0].getDst();
		for (int i = 0; i < 7; ++i) {
			dst.x = i * BLOCK_WIDTH;
			dst.y = 5 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 7; i < 15; ++i) {
			dst.x = (i-1) * BLOCK_WIDTH;
			dst.y = 8 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 15; i < 17; ++i) {
			dst.x = 13 * BLOCK_WIDTH;
			dst.y = (i-9) * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 17; i < 22; ++i) {
			dst.x = (i - 1) * BLOCK_WIDTH;
			dst.y = 4 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 22; i < 24; ++i) {
			dst.x = (i + 1) * BLOCK_WIDTH;
			dst.y = 10 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
	}
	else if (level == 2) {
		for (; objects.size() > 0;) {
			objects.pop_back();
		}
		for (int i = 0; i < 15; ++i) {
			objects.emplace_back(renderer, "textures/DefaultowyBlok.png");
		}
		SDL_Rect dst;
		dst = objects[0].getDst();
		for (int i = 0; i < 2; ++i) {
			dst.x = i * BLOCK_WIDTH;
			dst.y = 10 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 2; i < 5; ++i) {
			dst.x = (i+2) * BLOCK_WIDTH;
			dst.y = 10 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 5; i < 7; ++i) {
			dst.x = (2*i-2) * BLOCK_WIDTH;
			dst.y = (18-(2*i)) * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 7; i < 10; ++i) {
			dst.y = 6 * BLOCK_WIDTH;
			dst.x = (i + 7) * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 10; i < 15; ++i) {
			dst.y = 6 * BLOCK_WIDTH;
			dst.x = (i + 10) * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
	}
	else if (level == 3) {
		for (; objects.size() > 0;) {
			objects.pop_back();
		}
		for (int i = 0; i < 22; ++i) {
			objects.emplace_back(renderer, "textures/DefaultowyBlok.png");
		}
		SDL_Rect dst;
		dst = objects[0].getDst();
		for (int i = 0; i < 2; ++i) {
			dst.x = i * BLOCK_WIDTH;
			dst.y = 6 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 2; i < 4; ++i) {
			dst.x = (i+1) * BLOCK_WIDTH;
			dst.y = 3 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 4; i < 7; ++i) {
			dst.x = (i + 3) * BLOCK_WIDTH;
			dst.y = 7 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 7; i < 12; ++i) {
			dst.x = (5 + i) * BLOCK_WIDTH;
			dst.y = 5 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 12; i < 15; ++i) {
			dst.x = (i + 3) * BLOCK_WIDTH;
			dst.y = 8 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		for (int i = 15; i < 20; ++i) {
			dst.x = (i + 5) * BLOCK_WIDTH;
			dst.y = 5 * BLOCK_WIDTH;
			objects[i].setDst(dst);
		}
		dst.x = 18 * BLOCK_WIDTH;
		dst.y = 7 * BLOCK_WIDTH;
		objects[20].setDst(dst);
		dst.x = 20 * BLOCK_WIDTH;
		dst.y = 4 * BLOCK_WIDTH;
		objects[21].setDst(dst);
	}
}

void LevelManager::setEnemies(std::vector<Enemy>& enemies) {
	if (level == 1) {
		for (int i = 0; i < 3; ++i) {
			enemies.emplace_back(renderer);
		}

		SDL_Rect dst;
		dst = enemies[0].getDst();
		dst.y = BLOCK_WIDTH;
		dst.x = 7 * 65;
		enemies[0].setDst(dst);
		dst.x = 11 * BLOCK_WIDTH;
		enemies[1].setDst(dst);
		dst.x = 17 * BLOCK_WIDTH;
		enemies[2].setDst(dst);
	}
	else if (level == 2) {
		for (; enemies.size() > 0;) {
			enemies.pop_back();
		}
		for (int i = 0; i < 2; ++i) {
			enemies.emplace_back(renderer);
		}

		SDL_Rect dst;
		dst = enemies[0].getDst();
		dst.y = BLOCK_WIDTH;
		dst.x = 10 * BLOCK_WIDTH;
		enemies[0].setDst(dst);
		dst.x = 22 * BLOCK_WIDTH;
		enemies[1].setDst(dst);
	}
	else if (level == 3) {
		for (; enemies.size() > 0;) {
			enemies.pop_back();
		}
		for (int i = 0; i < 5; ++i) {
			enemies.emplace_back(renderer);
		}

		SDL_Rect dst;
		dst = enemies[0].getDst();
		dst.y = BLOCK_WIDTH;
		dst.x = 3 * BLOCK_WIDTH;
		enemies[0].setDst(dst);
		dst.x = 12 * BLOCK_WIDTH;
		enemies[1].setDst(dst);
		dst.x = 16 * BLOCK_WIDTH;
		enemies[2].setDst(dst);
		dst.x = 9 * BLOCK_WIDTH;
		enemies[3].setDst(dst);
		dst.x = 15 * BLOCK_WIDTH;
		dst.y = 7 * BLOCK_WIDTH;
		enemies[4].setDst(dst);
	}
}

void LevelManager::setLevel(int newLevel) {
	level = newLevel;
}

int LevelManager::getLevel() {
	return level;
}

LevelManager::~LevelManager() {
	SDL_DestroyRenderer(renderer);
}