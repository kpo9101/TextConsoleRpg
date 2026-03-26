#include "Item.h"
#include "PlayerCharacter.h"

Item::Item(ItemType t)
	:type(t){ }
void Item::Use(PlayerCharacter& player)
{
	switch (type)
	{
	case ItemType::Potion:
		player.Heal(50);
		std::cout << "[아이템] 포션 사용\n";
		break;

	case ItemType::AttackBoost:
		player.ApplyAttackBoost(10);
		std::cout << "[아이템] 부스터(공) 사용\n";
		break;
	}
}

void Item::Print()const
{
	switch(type)
	{
	case ItemType::Potion:
		std::cout << "포션 (Hp +50)";
		break;

	case ItemType::AttackBoost:
		std::cout << "부스터(공) (Att +50)";
		break;

	}

}