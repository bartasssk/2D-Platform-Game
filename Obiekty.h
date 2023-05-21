#pragma once
#include <iostream>
using namespace std;

class Platform {
private:
	int width;
	int height;
public:
	Platform();
	~Platform();
};

class Obstacle {
private:
	int width;
	int height;
	int DMG;
public:
	Obstacle();
	void stagger();
	~Obstacle();
};
