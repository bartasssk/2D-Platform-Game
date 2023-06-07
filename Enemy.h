#pragma once
#include "Character.h"

class Enemy : public Character {
public:
	Enemy(SDL_Renderer* rend);
	void move() override;
	~Enemy();
};
