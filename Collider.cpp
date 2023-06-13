#include "Collider.h"
#include "Player.h"
#include "Enemy.h"

Collider::Collider() {}

//Hamuje spadanie

void Collider::Ground(Player* player, std::vector<Object>& obj) {
	SDL_Rect PlayerDst = player->getDst();
	bool ground = false;
	const int playerBottom = PlayerDst.y + PlayerDst.h;
	const int playerLeft = PlayerDst.x;
	const int playerRight = PlayerDst.x + PlayerDst.w;

	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (playerBottom >= ObjectDst.y and playerBottom < ObjectDst.y + 32 and ((playerRight > ObjectDst.x and playerRight <= ObjectDst.x + ObjectDst.w) or (playerLeft >= ObjectDst.x and playerLeft < ObjectDst.x + ObjectDst.w)) and player->getVelY() <= 0) {
			ground = true;
			player->setVelY(0);
			SDL_Rect newDst{};
			newDst.x = player->getDst().x;
			newDst.y = ObjectDst.y - PlayerDst.h;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			player->setDst(newDst);
			player->setGroundState(ground);
			return;
		}
	}
	player->setGroundState(ground);
}

void Collider::GroundE(std::vector<Enemy>& enemies, std::vector<Object>& obj) {
	for (auto& e : enemies) {
		bool ground = false;
		SDL_Rect EnemyDst = e.getDst();
		const int EnemyBottom = EnemyDst.y + EnemyDst.h;
		const int EnemyLeft = EnemyDst.x;
		const int EnemyRight = EnemyDst.x + EnemyDst.w;
		for (auto& obj : obj) {
			SDL_Rect ObjectDst = obj.getDst();
			if (EnemyBottom >= ObjectDst.y and EnemyBottom < ObjectDst.y + 32 and ((EnemyRight >= ObjectDst.x and EnemyRight <= ObjectDst.x + ObjectDst.w) or (EnemyLeft >= ObjectDst.x and EnemyLeft <= ObjectDst.x + ObjectDst.w)) and e.getVelY() <= 0) {
				ground = true;
				e.setVelY(0);
				SDL_Rect newDst{};
				newDst.x = e.getDst().x;
				newDst.y = ObjectDst.y - EnemyDst.h;
				newDst.w = e.getDst().w;
				newDst.h = e.getDst().h;
				e.setDst(newDst);
				e.setGroundState(ground);
				break;
			}
			e.setGroundState(ground);
		}
	}
}

//Hamuje poruszanie siê

void Collider::Wall(Player* player, std::vector<Object>& obj) {
	SDL_Rect PlayerDst = player->getDst();
	bool check = true;
	const int playerBottom = PlayerDst.y + PlayerDst.h;
	const int playerTop = PlayerDst.y;
	const int playerLeft = PlayerDst.x;
	const int playerRight = PlayerDst.x + PlayerDst.w;

	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (player->getVelX() > 0 and playerRight >= ObjectDst.x and playerRight <= ObjectDst.x + 20 and (playerBottom > ObjectDst.y and playerBottom < ObjectDst.y + ObjectDst.h or playerTop <= ObjectDst.y + ObjectDst.h and playerTop >= ObjectDst.y)) {
			SDL_Rect newDst;
			player->setVelX(0);
			newDst.x = ObjectDst.x - PlayerDst.w;
			newDst.y = player->getDst().y;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			player->setDst(newDst);
			player->setIfNulled(true);
			player->setCanIMove(true, false);
			check = false;
		}
		else if (player->getVelX() < 0 and playerLeft >= ObjectDst.x + 44 and playerLeft <= ObjectDst.x + ObjectDst.w and (playerBottom > ObjectDst.y and playerBottom < ObjectDst.y + ObjectDst.h or playerTop < ObjectDst.y + ObjectDst.h and playerTop >= ObjectDst.y)) {
			player->setVelX(0);
			SDL_Rect newDst;
			newDst.x = ObjectDst.x + ObjectDst.w;
			newDst.y = player->getDst().y;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			player->setDst(newDst);
			player->setIfNulled(true);
			player->setCanIMove(false, true);
			check = false;
		}
		else if ((playerTop <= ObjectDst.y + ObjectDst.h and playerTop > ObjectDst.y + 43) and ((playerRight > ObjectDst.x and playerRight <= ObjectDst.x + ObjectDst.w) or (playerLeft >= ObjectDst.x and playerLeft < ObjectDst.x + ObjectDst.w))) {
			player->setVelY(0);
			SDL_Rect newDst;
			newDst.x = player->getDst().x;
			newDst.y = ObjectDst.y + ObjectDst.h;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			player->setDst(newDst);
			check = false;
		}
		else if (playerLeft <= 0 and player->getVelX() < 0) {
			player->setVelX(0);
			SDL_Rect newDst;
			newDst.x = 0;
			newDst.y = player->getDst().y;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			player->setDst(newDst);
			player->setIfNulled(true);
			player->setCanIMove(false, true);
			check = false;
		}
	}

	if (check = true) {
		player->setCanIMove(true, true);
	}
}

void Collider::EndOfPlatform(std::vector<Enemy>& enemies, std::vector<Object>& obj) {
	for (int j = 0; j < enemies.size(); ++j) {
		const int EnemyRight = enemies[j].getDst().x + enemies[j].getDst().w;
		const int EnemyLeft = enemies[j].getDst().x;
		const int EnemyWidth = enemies[j].getDst().w;
		bool End = true;

		SDL_Rect nextBlockRight = enemies[j].getDst();
		SDL_Rect nextBlockLeft = enemies[j].getDst();
		nextBlockRight.x = EnemyRight + 2;
		nextBlockRight.y = enemies[j].getDst().y + 5;
		nextBlockLeft.x = EnemyLeft - EnemyWidth - 2;
		nextBlockLeft.y = enemies[j].getDst().y + 5;
		for (int i = 0; i < obj.size() and End == true; ++i) {
			SDL_Rect ObjectDst = obj[i].getDst();
			if ((SDL_HasIntersection(&nextBlockRight, &ObjectDst) == true and enemies[j].getVelX() > 0) or (SDL_HasIntersection(&nextBlockLeft, &ObjectDst) == true and enemies[j].getVelX() < 0)) {
				End = false;
			}

			/*if (SDL_HasIntersection(&nextBlockRight, &ObjectDst) == false and e.getVelX() >= 0 and (EnemyRight >= ObjectDst.x and EnemyRight <= ObjectDst.x + ObjectDst.w)) {
				e.setVelX(-e.getVelX());
			}
			else if (SDL_HasIntersection(&nextBlockLeft, &ObjectDst) == false and e.getVelX() <= 0 and  (EnemyLeft == ObjectDst.x and EnemyLeft <= ObjectDst.x + ObjectDst.w)) {
				e.setVelX(-e.getVelX());
			}*/
		}
		if (End == true) {
			enemies[j].setVelX(-enemies[j].getVelX());
		}
	}
}

void Collider::WallE(std::vector<Enemy>& enemies, std::vector<Object>& obj) {
	for (auto& e : enemies) {
		SDL_Rect EnemyDst = e.getDst();
		for (auto& obj : obj) {
			SDL_Rect ObjectDst = obj.getDst();
			if (SDL_HasIntersection(&EnemyDst, &ObjectDst) == true) {
				e.setVelX(-e.getVelX());
			}
		}
	}
}

Collider::~Collider(){}
