// PlayerCharacter.h
#pragma once
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"

class GameManager;
class PlayerCharacter
{
private:
	std::string name;
	int Level, Health, MaxHealth, Attack, Experience, Gold;
	Inventory<Item> inventory;
	const int MaxExperience = 100;
	int TempAttackBoost;//아이템 사용시 상승하는 공격력
	GameManager* Game;
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

	//추가 내용
	int GetLevel() const;
	void takeDamage(int damage);
	int GetHealth() const;
	void AddItem(const Item& item);
	void BattleItem();
	std::string GetName() const;
<<<<<<< HEAD
	void OpenShop();
=======
	void Getgold(int Gold);
>>>>>>> 9795f73fbe48ed3b195f9da8ca1cd09f7f55fb27

};

