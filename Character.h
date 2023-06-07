#pragma once
#include "Obiekty.h"

class Character : public Object {
private:
	int HP;
	int velX;
	int velY;
	SDL_Rect sheight;
	bool grounded;
	bool CanIMoveLeft;
	bool CanIMoveRight;
public:
	Character(SDL_Renderer* rend);
	virtual void move() = 0;
	void gravity();
	void setVelX(int p_velX);
	void setVelY(int p_velY);
	void setGroundState(bool state);
	void setCanIMove(bool left, bool right);
	int getVelX();
	int getVelY();
	bool getCanIMoveRight();
	bool getCanIMoveLeft();
	bool getGroundState();
	SDL_Rect getStartHeight();
	~Character();
};
