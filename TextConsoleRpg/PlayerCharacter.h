// PlayerCharacter.h
#pragma once
#include <string>
#include <vector>
class PlayerCharacter
{
private:
	std::string name;
	int Level, Health, MaxHealth, Attack, Experience, Gold;
	std::vector<int> inventory;

public:
	PlayerCharacter(std::string name);
	void GetExp(int exp);
	void ShowStatus();
	void LevelUp();
	//Item 관련 추가
	void Heal(int amount);
	void ApplyAttackBoost(int value);
	int GetTotalAttack()const;
	void ResetBattleState();
	
	int TempAttackBoost;//아이템 사용시 상승하는 공격력
};

