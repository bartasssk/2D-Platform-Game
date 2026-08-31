#pragma once
#include "Obiekty.h"
#include <vector>

class Enemy;
class Player;

/**
 * @brief Virtual class for Player and Enemy to inherit.
*/
class Character : public Object {
private:
	/**
	 * @brief Tells other functions if character is still alive.
	*/
	bool ifdead;
	/**
	 * @brief Health Points
	*/
	int HP;
	/**
	 * @brief Charcater's velocity in x axis.
	*/
	float velX;
	/**
	 * @brief Charcater's velocity in y axis.
	*/
	float velY;
	/**
	 * @brief Tells other functions if character is on the ground.
	*/
	bool grounded;
	/**
	 * @brief Tells a character if he can move in the left direction.
	*/
	bool CanIMoveLeft;
	/**
	 * @brief Tells a character if he can move in the right direction.
	*/
	bool CanIMoveRight;
public:

	/**
	 * @brief Constructor for character.
	*/
	Character(SDL_Renderer* rend, const char* FilePath);
	
	/**
	 * @brief Virtual function responsible for character's movement.
	*/
	virtual void move() = 0;

	/**
	 * @brief Virtual function responsible for characters' attacks.
	*/
	virtual void attack(Enemy *enemy, Player* player) = 0;
	/**
	 * @brief Virtual function responsible for character's death.
	*/
	virtual void die() = 0;
	friend class Enemy;
	friend class Player;
	/**
	 * @brief Function responsible for characters' gravity. Works only if grounded = false.
	*/
	void gravity();
	/**
	 * @brief Setter for VelX.
	*/
	void setVelX(float p_velX);
	/**
	 * @brief Setter for VelY.
	*/
	void setVelY(float p_velY);
	/**
	 * @brief Setter for parameter that tells if character is on the ground.
	*/
	void setGroundState(bool state);
	/**
	 * @brief Setter for parameters responsible for characters' ability to move left or right.
	*/
	void setCanIMove(bool left, bool right);
	/**
	 * @brief Setter for Charcter's HP.
	*/
	void setHP(int newHP);

	/**
	 * @brief Getter for velocity in x axis.
	*/
	float getVelX();
	/**
	 * @brief Getter for velocity in y axis.
	*/
	float getVelY();
	/**
	 * @brief Getter for character's health points. 
	*/
	int getHP();
	/**
	 * @brief Getter for parameter that tells if character is on the ground. 
	*/
	bool getGroundState();
	/**
	 * @brief Getter for parameter that tells if character is dead.
	*/
	bool getIfDead();
	/**
	 * @brief Destructor.
	*/
	~Character();
};
