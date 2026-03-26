// PlayerCharacter.h
#pragma once
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"

class PlayerCharacter
{
private:
	std::string name;
	int Level, Health, MaxHealth, Attack, Experience, Gold;
<<<<<<< HEAD
	const int MaxExp = 100;
	Inventory<Item> inventory;
=======
	const int MaxExperience = 100;
	std::vector<int> inventory;
>>>>>>> f7b5e2c98e56ac5d2616d17badfb6cf845fbdcba

public:
	PlayerCharacter(std::string name);
	void GetExp(int exp);
	void ShowStatus();
	void LevelUp();
	//Item 관련 추가
	bool Heal(int amount);
	void ApplyAttackBoost(int value);
	int GetTotalAttack()const;
	void ResetBattleState();
	
	int TempAttackBoost;//아이템 사용시 상승하는 공격력
};

