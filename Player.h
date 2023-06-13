#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Character.h"
/**
 * @brief Class responsible for player's behaviour.
*/
class Player : public Character {
private:
	/**
	 * @brief SDL_Event which is responsible for example for any inputs.
	*/
	SDL_Event* currentEvent;
	/**
	 * @brief Texture if player faces left.
	*/
	SDL_Texture* leftTexture;
	/**
	 * @brief Texture if player faces right.
	*/
	SDL_Texture* rightTexture;
	/**
	 * @brief Sword texture if player faces left.
	*/
	SDL_Texture* swordLeft;
	/**
	 * @brief Sword texture if player faces right.
	*/
	SDL_Texture* swordRight;
	/**
	 * @brief Sword that is assigned to the player.
	*/
	Object sword;
	/**
	 * @brief Variable that tells if player has hit someone.
	*/
	bool hit;
	/**
	 * @brief Variable that tells if player's velocity has been zeroed.
	*/
	bool ifnulled;
	/**
	 * @brief Enum for actions of a player.
	*/
	enum class State {STANDING, MOVING, JUMPING, ATTACKING};
	/**
	 * @brief Side which player faces.
	*/
	enum class Side {LEFT,RIGHT};
	/**
	 * @brief Current action.
	*/
	State currentState;
	/**
	 * @brief Current side of a player.
	*/
	Side currentSide;
	/**
	 * @brief Current frame of animation.
	*/
	int currentFrame;
	/**
	 * @brief Delay in which animation of standing changes.
	*/
	int standingDelay;
	/**
	 * @brief Delay in which animation of moving changes.
	*/
	int movingDelay;
	/**
	 * @brief Delay in which animation of sword changes.
	*/
	int swordDelay;
public:
	/**
	 * @brief Constructor.
	*/
	Player(SDL_Renderer* rend, const char* FilePathLeft, const char* FilePathRight);
	/**
	 * @brief Function responsible for player's movement.
	*/
	void move() override;
	/**
	 * @brief Function responsible for player's attacks.
	 * @param enemy Potential enemy it can hit.
	 * @param player The player that attacks.
	*/
	void attack(Enemy *enemy, Player* player) override;
	/**
	 * @brief Function responsible for player's death.
	*/
	void die() override;
	/**
	 * @brief Function responsible for player's animations.
	*/
	void animate();
	/**
	 * @brief Function responsible for rendering sword when player is attacking.
	*/
	void renderSword();
	/**
	 * @brief Setter for current event.
	*/
	void setCurrentSDLEvent(SDL_Event* event) { currentEvent = event; };
	/**
	 * @brief Setter for ifnulled variable. 
	*/
	void setIfNulled(bool result);
	/**
	 * @brief Setter for death state.
	*/
	void setIfDead(bool newState);
	/**
	 * @brief Destructor.
	*/
	~Player();
};