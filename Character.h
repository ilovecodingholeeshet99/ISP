#pragma once
#include "Object.h"
class Character
{
	int health;
	int damage;
	int x;
	int y;
	int money;
	static const int inventorySize = 3;
	Object* inventory[inventorySize];
	int currentCapacity = 0;
public:
	Character();
	void addInventory(Object* object);
	int getX();
	int getY();
	int& getMoney();
	void move(char dir);
	void printInventory();
	~Character();
};



