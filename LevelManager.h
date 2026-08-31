#pragma once
#include <vector>
#include <SDL.h>
#include "Enemy.h"
/**
 * @brief Class responsible for levels.
*/
class LevelManager {
private:
	/**
	 * @brief Variable that tells which level it is.
	*/
	int level;
	/**
	 * @brief SDL_Renderer
	*/
	SDL_Renderer* renderer;
public:
	/**
	 * @brief Constructor.
	*/
	LevelManager(SDL_Renderer* rend);
	/**
	 * @brief Default constructor.
	*/
	LevelManager();
	/**
	 * @brief Sets objects on the map.
	 * @param objects Vector of objects.
	*/
	void setTerrain(std::vector<Object>& objects);
	/**
	 * @brief Sets enemies on the map
	 * @param enemies Vector of enemies.
	*/
	void setEnemies(std::vector<Enemy>& enemies);
	/**
	 * @brief Setter for levels.
	 * @param newLevel New Level.
	*/
	void setLevel(int newLevel);
	/**
	 * @brief Getter for levels.
	 * @return Current level.
	*/
	int getLevel();
	/**
	 * @brief Destructor.
	*/
	~LevelManager();
};