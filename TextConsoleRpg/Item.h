#pragma once

#include <iostream>

class PlayerCharacter;
enum class ItemType
{
	Potion,
	AttackBoost
};

class Item
{
public:
	Item(ItemType t);

	bool Use(PlayerCharacter& player);
	void Print() const;
	int GetPrice()const;
private:
	ItemType type;
};

