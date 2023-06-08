#pragma once
#include "Obiekty.h"

class Character : public Object {
private:
	int HP;
	float velX;
	float velY;
	bool grounded;
	bool CanIMoveLeft;
	bool CanIMoveRight;
public:
	Character(SDL_Renderer* rend, const char* FilePath);
	virtual void move() = 0;
	void gravity();
	void setVelX(float p_velX);
	void setVelY(float p_velY);
	void setGroundState(bool state);
	void setCanIMove(bool left, bool right);
	float getVelX();
	float getVelY();
	bool getCanIMoveRight();
	bool getCanIMoveLeft();
	bool getGroundState();
	SDL_Rect getStartHeight();
	~Character();
};
