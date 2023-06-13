#pragma once
#include <vector>
#include <SDL.h>
#include "Enemy.h"

class LevelManager {
private:
	int level;
	SDL_Renderer* renderer;
	Object object;
public:
	LevelManager(SDL_Renderer* rend);
	LevelManager();
	void setTerrain(std::vector<Object>& objects);
	void setEnemies(std::vector<Enemy>& enemies);
	void setLevel(int newLevel);
	int getLevel();
	~LevelManager();
};