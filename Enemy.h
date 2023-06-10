#pragma once
#include "Character.h"

class Enemy : public Character {
private:
	Uint32 lastTime, currentTime;
	bool hit;
public:
	Enemy(SDL_Renderer* rend);
	void move() override;
	void attack(Enemy *enemy, Player* player) override;
	void die() override;
	~Enemy();
};
