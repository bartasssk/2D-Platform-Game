#pragma once
#include "Character.h"

/**
 * @brief Class responsible for enemies' behaviour.
*/
class Enemy : public Character {
private:
	/**
	 * @brief Parameters responsible for time between enemy's attacks.
	*/
	Uint32 lastTime, currentTime;
	/**
	 * @brief Parameter that tells if enemy has already hit the player while it intersects.
	*/
	bool hit;
public:
	/**
	 * @brief Constructor.
	*/
	Enemy(SDL_Renderer* rend);
	/**
	 * @brief Default constructor.
	*/
	Enemy();
	/**
	 * @brief Function responsible for enemy's constant movement.
	*/
	void move() override;
	/**
	 * @brief Function responsible for dealing damage to player if he intersects with enemy.
	 * @param enemy Enemy that deals the damage.
	 * @param player Player that the damage is dealt to.
	*/
	void attack(Enemy *enemy, Player* player) override;
	/**
	 * @brief Function responsible for death of enemy.
	*/
	void die() override;
	/**
	 * @brief Destructor.
	*/
	~Enemy();
};
