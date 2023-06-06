#pragma once
#include "Obiekty.h"

class Character : public Object {
private:
	int HP;
	int velX;
	int velY;
	SDL_Rect sheight;
	bool grounded;
public:
	Character(SDL_Renderer* rend);
	virtual void move() = 0;
	void side();
	void setVelX(int p_velX);
	void setVelY(int p_velY);
	void setGroundState(bool state);
	int getVelX();
	int getVelY();
	bool getGroundState();
	SDL_Rect getStartHeight();
	~Character();
};
