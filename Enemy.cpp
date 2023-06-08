#include "Enemy.h"

const float ENEMY_SPEED = +2.0f;

Enemy::Enemy(SDL_Renderer* rend) : Character(rend, "textures/wrog1.png") {
	setVelX(ENEMY_SPEED);
}

void Enemy::move() {
	SDL_Rect newDst = getDst();
	newDst.x += getVelX();
	setDst(newDst);
}

Enemy::~Enemy() {}