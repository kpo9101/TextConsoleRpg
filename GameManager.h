//GameManager.h

#pragma once 
#include "PlayerCharacter.h"
#include "Monster.h"

class GameManager {
public:
	Monster* generateMonster(int level);
	void battle(Character* player);
	void displayInventory(Character* player);

};