#include <iostream>
#include <string>
#include <windows.h>
#include "conio.h"
#include <stdlib.h>
#include "World.h"
#include "Shop.h"

int main()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 30;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	World gameWorld;
	Character* hero = new Character;
	char dir = 0;
	Shop menu;
	bool shopOpen = false;
	while (true)
	{
		system("CLS");


		gameWorld.updateWorldPositions(hero,&menu);
		
		if (!shopOpen) 
		{
			gameWorld.printWorld(hero);
			std::cout << std::endl << std::endl << "What do you want to do?(WASD to move, IJKL to attack, M for map, Q to quit): " << std::endl;
		}
		if (shopOpen)
		{
			menu.printMenu(hero->getMoney());
		}
		/*hero->printInventory();*/
		dir = _getch();
		std::cout << std::endl;
		if (shopOpen)
		{
			hero->addInventory(menu.buy(dir, hero->getMoney()));
		}

	

		if (dir == 'w' && !shopOpen)
		{
			if (gameWorld.world[hero->getX() - 1][hero->getY()] == '.')
			{
				hero->move(dir);
				
			} 
			else
			{
				continue;
			}
		}
		else if (dir == 's' && !shopOpen)
		{
			if (gameWorld.world[hero->getX() + 1][hero->getY()] == '.')
			{
				hero->move(dir);
				
			}
			else
			{
				continue;
			}
		}
		else if (dir == 'a' && !shopOpen)
		{
			if (gameWorld.world[hero->getX()][hero->getY() - 1] == '.')
			{
				hero->move(dir);
				
			
			}
			else
			{
				continue;
			}
		}
		else if (dir == 'd' && !shopOpen)
		{
			if (gameWorld.world[hero->getX()][hero->getY() + 1] == '.')
			{
				hero->move(dir);
			}
			else
			{
				continue;
			}
		}
		else if (dir == 'm' && !shopOpen)
		{
			system("CLS");
			gameWorld.printWorldMap(hero);

			std::cout << std::endl << std::endl << std::endl;
			system("pause");

		}
		else if (dir == 'e')
		{
			if (hero->getX() == menu.getX() -1 && hero->getY() == menu.getY()   ||
				hero->getX() == menu.getX() && hero->getY() == menu.getY()+ 1   || 
				hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY() + 1 || 
				hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY()- 1  ||
				hero->getX() == menu.getX() -1 && hero->getY() == menu.getY() + 1 ||
				hero->getX() == menu.getX() - 1 && hero->getY() == menu.getY() -1 || 
				hero->getX() == menu.getX() && hero->getY() == menu.getY() - 1 ||
				hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY()
				)
			{
				shopOpen = !shopOpen;
			}
		}
		else if (dir == 'q')
		{
			exit(0);
		}
	}
	return 0;
}