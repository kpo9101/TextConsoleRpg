// PlayerCharacter.h
#pragma once
#include <string>
#include <vector>
class PlayerCharacter
{
private:
	std::string name;
	int Level, Health, MaxHealth, Attack, Experience, Gold;
	const int MaxExperience = 100;
	std::vector<int> inventory;

public:
	PlayerCharacter(std::string name);
	void GetExp(int exp);
	void ShowStatus();
	void LevelUp();
};

