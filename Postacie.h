#pragma once
#include <iostream>
using namespace std;

class Character {
private:
	int HP;
	int DMG;
public:
	Character();
	virtual void movement();
	virtual void jumping();
	~Character();
};

class Main_Character : public Character {
private:
	int STAMINA;
public:
	Main_Character();
	~Main_Character();
};

class Enemy : public Character {
public:
	Enemy();
	~Enemy();
};