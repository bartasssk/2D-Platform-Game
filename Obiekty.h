#pragma once
#include <iostream>

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
