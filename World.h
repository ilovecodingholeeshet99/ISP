#pragma once
#include "Character.h"
#include "Shop.h"
class World
{
public:
	World();

	char world[101][101];
	void updateWorldPositions(Character* player, Shop* menu);
	void printWorld(Character* player);
	void printWorldMap(Character* player);

	~World();
};
