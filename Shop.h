#pragma once
#include "Object.h"
#include <iostream>
class Shop
{
private:
	char shopIcon;
	int x;
	int y;
	Object** accessory;
	const int shopCapacity = 3;
	std::string buffer = "Welcome to URAYA .What would you like to purchase? 1 - Weapon |  2 - Knights Armor | 3 - Elixir";
public:
	Shop();
	int getX();
	int getY();
	void printMenu(int& money);
	Object* buy(int number , int &money);
	

};

