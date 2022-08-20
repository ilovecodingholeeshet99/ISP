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
	std::string buffer = "Welcome to Los Pollos Hermanos.What do you like to purchase? ";
public:
	Shop();
	int getX();
	int getY();
	void printMenu(int& money);
	Object* buy(int number , int &money);
	

};

