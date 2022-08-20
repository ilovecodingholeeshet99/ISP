#include "World.h"
#include <iomanip>
#include <iostream>
#include <windows.h>

World::World()
{
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			world[x][y] = '.';
		}
	}
}

void World::updateWorldPositions(Character* player, Shop* shopLocate)
{
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			if (x == 0 || x == 100 || y == 0 || y == 100)
			{
				world[x][y] = '+';
			}
			else if (x == 50 && (y == 40 || y == 41 || y == 42 || y == 43))
			{
				world[x][y] = '-';
			}
			else if (x == player->getX() && y == player->getY())
			{
				world[x][y] = 'P';
			}
			else if (x == shopLocate->getX() && y == shopLocate->getY())
			{
				world[x][y] = 'S';
			}
			else
			{
				world[x][y] = '.';
			}
		}
	}
}

void World::printWorld(Character* player)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int tempX = -10;
	int tempY = -10;

	for (size_t x = 0; x < 21; x++)
	{
		tempY = -10;
		std::cout << std::setw(30);

		for (size_t y = 0; y < 21; y++)
		{
			if (world[player->getX() + tempX][player->getY() + tempY] == '-')
			{
				SetConsoleTextAttribute(h, 0xff);
			}
			if (((player->getY() + tempY) >= 0) &&
				((player->getY() + tempY) <= 100) &&
				((player->getX() + tempX) >= 0) &&
				((player->getX() + tempX) <= 100))
			{
				std::cout << world[player->getX() + tempX][player->getY() + tempY];
			}
			else
			{
				std::cout << ' ';
			}

			std::cout << ' ';

			SetConsoleTextAttribute(h, 0x0f);
			tempY++;
		}
		std::cout << std::endl;
		tempX++;
	}
}

void World::printWorldMap(Character* player)
{
	for (size_t x = 0; x < 101; x++)
	{
		//std::cout << std::setw(55);
		for (size_t y = 0; y < 101; y++)
		{
			std::cout << world[x][y];
		}
		std::cout << std::endl;
	}
}

World::~World()
{

}

