#include "Character.h"
#include <iostream>
Character::Character()
{
	health = 100;
	damage = 5;
	x = 1;
	y = 1;
	money = 95;
	for (int i = 0; i < inventorySize; i++)
	{
		inventory[i] = nullptr;
	}
}

void Character::addInventory(Object* object)
{
	if (currentCapacity >= inventorySize)
	{
		return;
	}
	inventory[currentCapacity++] = object;


}

int Character::getX()
{
	return x;
}

int Character::getY()
{
	return y;
}

int& Character::getMoney()
{
	return money;
}

void Character::move(char dir)
{
	switch (dir)
	{
	case 'w':
		x--;
		break;
	case 's':
		x++;
		break;
	case 'a':
		y--;
		break;
	case 'd':
		y++;
		break;
	default:
		break;
	}
}

void Character::printInventory()
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory[i] == nullptr)
		{
			continue;
		}
		std::cout << inventory[i]->getPrice() << std::endl;
	
	}
	
}

Character::~Character()
{
}

