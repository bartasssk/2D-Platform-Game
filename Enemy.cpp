#include "Enemy.h"
#include "Player.h"

const float ENEMY_SPEED = +2.0f;

Enemy::Enemy(SDL_Renderer* rend) : Character(rend, "textures/wrog1.png"), lastTime(0), currentTime(0), hit(false)  {
	velX = ENEMY_SPEED;
}

void Enemy::move() {
	SDL_Rect newDst = getDst();
	newDst.x += velX;
	setDst(newDst);
}

void Enemy::attack(Enemy *enemy, Player* player) {
	SDL_Rect EnemyDst = getDst();
	SDL_Rect PlayerDst = player->getDst();
		if (SDL_HasIntersection(&EnemyDst, &PlayerDst) == true) {
			currentTime = SDL_GetTicks();
			if ((currentTime - lastTime >= 3000 or hit == false) and player->getIfDead()== false and ifdead == false) {
				player->setHP(player->getHP() - 1);
				lastTime = currentTime;
				hit = true;
				return;
			}
		}
		else {
			hit = false;
		}
	
}

void Enemy::die() {
	if (HP <= 0) {
		ifdead = true;
		setDst({ 0,0,0,0 });
	}
}

Enemy::~Enemy() {}