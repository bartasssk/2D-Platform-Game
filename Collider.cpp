#include "Collider.h"
#include "Player.h"

const int GRAVITY = 2;

Collider::Collider(){}

//Hamuje spadanie

void Collider::isGround(Player *player, std::vector<Object> &obj) {
	SDL_Rect PlayerDst = player->getDst();
	bool ground = false;
	const int playerBottom = PlayerDst.y + PlayerDst.h;
	const int playerLeft = PlayerDst.x;
	const int playerRight = PlayerDst.x + PlayerDst.w;

	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (playerBottom >= ObjectDst.y  and playerBottom <= ObjectDst.y + 20 and (playerRight > ObjectDst.x and playerRight < ObjectDst.x + ObjectDst.w or playerLeft > ObjectDst.x  and playerLeft < ObjectDst.x + ObjectDst.w) and player->getVelY()<=0) {
			SDL_Rect newDst;
			newDst.x = player->getDst().x;
			newDst.y = ObjectDst.y - PlayerDst.w;
			newDst.w = player->getDst().w;
			newDst.h = player->getDst().h;
			ground = true;
			player->setDst(newDst);
			player->setGroundState(ground);
			player->setVelY(0);
			return;
		}
	}
	player->setGroundState(ground);
}

//Hamuje poruszanie siê

void Collider::canImove(Player* player, std::vector<Object>& obj) {
	SDL_Rect PlayerDst = player->getDst();
 	bool check = true;
	const int playerTop = PlayerDst.y;

	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (SDL_HasIntersection(&PlayerDst, &ObjectDst)) {
			if (player->getVelX() > 0) {
				player->setVelX(0);
				player->setIfNulled(true);
				player->setCanIMove(true, false);
				check = false;
				return;
			}
			else if (player->getVelX() < 0) {
				player->setVelX(0);
				player->setIfNulled(true);
				player->setCanIMove(false, true);
				check = false;
				return;
			}
			else if (playerTop < ObjectDst.y + ObjectDst.h and playerTop > ObjectDst.y and SDL_HasIntersection(&PlayerDst, &ObjectDst) and player->getVelY()>0) {
				player->setVelY(0);
				SDL_Rect newDst;
				newDst.x = player->getDst().x;
				newDst.y = ObjectDst.y + ObjectDst.h;
				newDst.w = player->getDst().w;
				newDst.h = player->getDst().h;
				player->setDst(newDst);
			}
			else if (player->getVelX() == 0) {
				check = false;
				return;
			}
		}
	}

	if (check = true) {
		player->setCanIMove(true, true);
	}
}


Collider::~Collider(){}
