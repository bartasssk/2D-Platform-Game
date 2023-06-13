#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
class Player;
class Object;
class Enemy;

/**
 * @brief Class that detects Characters' collision with other objects.
*/
class Collider {
public:
	/**
	 * @brief Constructor.
	*/
	Collider();
	/**
	 * @brief Detects if player collides with any of the objects from the bottom. If he does he is stopped and his ground state is set to true.
	 * @param player The player that it checks collision with.
	 * @param obj The vector of objects that it checks collision with.
	*/
	void Ground(Player* player, std::vector<Object>& obj);
	/**
	 * @brief Detects if any of enemies collides with any of the blocks from the bottom. If they do, they are stopped and their ground state is set to true.
	 * @param enemies Vector of enemies that it checks collision with.
	 * @param obj Vector of objects that it checks collision with.
	*/
	void GroundE(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	/**
	 * @brief Detects if player collides with any if the objects from top, left or right and stops them. Also this function prevents the player to move out of frame on the left and right side.
	 * @param player The player that it checks collision with.
	 * @param obj The vector of objects that it checks collision with.
	*/
	void Wall(Player* player, std::vector<Object>& obj);
	/**
	 * @brief Checks if enemy would fall down if he went further and inverts velocity direction if that is the case.
	 * @param enemies Vector of enemies that it checks collision with.
	 * @param obj The vector of objects that it checks collision with.
	*/
	void EndOfPlatform(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	/**
	 * @brief Checks if enemy collides with any of the objects and inverts velocity direction it that is the case.
	 * @param enemies Vector of enemies that it checks collision with.
	 * @param obj The vector of objects that it checks collision with.
	*/
	void WallE(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	/**
	 * @brief Destructor.
	*/
	~Collider();
};