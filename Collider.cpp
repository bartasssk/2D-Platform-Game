#include "Collider.h"
#include "Player.h"

const int GRAVITY = 2;

Collider::Collider(){}

//Hamuje spadanie

void Collider::isGround(Player *player, std::vector<Object> &obj) {
	SDL_Rect PlayerDst = player->getDst();
	bool ground = false;
	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (PlayerDst.y + PlayerDst.h >= ObjectDst.y  and PlayerDst.y + PlayerDst.h <= ObjectDst.y + ObjectDst.h and (PlayerDst.x + PlayerDst.w >= ObjectDst.x and PlayerDst.x + PlayerDst.w <= ObjectDst.x + ObjectDst.w or PlayerDst.x >= ObjectDst.x and PlayerDst.x <= ObjectDst.x + ObjectDst.w) and player->getVelY()<=0) {
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

	for (auto& item : obj) {
		SDL_Rect ObjectDst = item.getDst();
		if (SDL_HasIntersection(&PlayerDst, &ObjectDst)  and (player->getVelX() > 0 or player->getVelX() < 0)){
			if (player->getVelX() > 0) {
				player->setVelX(0);
			}
			else if (player->getVelX() < 0) {
				player->setVelX(0);
			}
		}
	}
}

Collider::~Collider(){}
