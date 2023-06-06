#pragma once
#include <iostream>
#include <vector>
class Player;
class Object;

//Wykrywacz kolizji

class Collider {
public:
	Collider();
	void isGround(Player* player, std::vector<Object>& obj);
	void canImove(Player* player, std::vector<Object>& obj);
	~Collider();
};