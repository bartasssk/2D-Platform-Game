#pragma once
#include <iostream>
#include <vector>
class Player;
class Object;

class Collider {
public:
	Collider();
	void isGround(Player* player, std::vector<Object>& obj);
	bool canImove(Player* player, std::vector<Object>& obj);
	~Collider();
};