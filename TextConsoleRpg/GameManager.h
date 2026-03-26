//GameManager.h
#pragma once 
#include "PlayerCharacter.h"
#include "Monster.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class GameManager
{
public:
	GameManager();
	~GameManager();

	Monster* generateMonster(int level);
	void battle(PlayerCharacter* Player);
	void displayInventory(PlayerCharacter* Player);

};

