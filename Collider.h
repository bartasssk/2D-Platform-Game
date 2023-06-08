#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
class Player;
class Object;
class Enemy;

//Wykrywacz kolizji

class Collider {
public:
	Collider();
	void Ground(Player* player, std::vector<Object>& obj);
	void GroundE(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	void Wall(Player* player, std::vector<Object>& obj);
	void EndOfPlatform(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	void WallE(std::vector<Enemy>& enemies, std::vector<Object>& obj);
	~Collider();
};