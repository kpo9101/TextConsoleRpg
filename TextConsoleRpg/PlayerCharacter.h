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
	const int MaxExp = 100;
	Inventory<Item> inventory;

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

