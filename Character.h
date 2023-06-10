#pragma once
#include "Obiekty.h"
#include <vector>

class Enemy;
class Player;

class Character : public Object {
private:
	bool ifdead;
	int HP;
	float velX;
	float velY;
	bool grounded;
	bool CanIMoveLeft;
	bool CanIMoveRight;
public:
	Character(SDL_Renderer* rend, const char* FilePath);
	virtual void move() = 0;
	virtual void attack(Enemy *enemy, Player* player) = 0;
	virtual void die() = 0;
	friend class Enemy;
	friend class Player;
	void gravity();
	void setVelX(float p_velX);
	void setVelY(float p_velY);
	void setGroundState(bool state);
	void setCanIMove(bool left, bool right);
	void setHP(int newHP);
	float getVelX();
	float getVelY();
	int getHP();
	bool getGroundState();
	bool getIfDead();
	~Character();
};
