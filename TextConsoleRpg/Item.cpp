#include "Item.h"
#include "PlayerCharacter.h"

Item::Item(ItemType t)
	:type(t) {
}
bool Item::Use(PlayerCharacter& player)
{
	switch (type)
	{
	case ItemType::Potion:
		return player.Heal(50);

	case ItemType::AttackBoost:
		player.ApplyAttackBoost(10);
		std::cout << "[아이템] 부스터(공격력,전투시에만 상승) 사용\n";
		return true;
	}
	return false;
}

void Item::Print()const
{
	switch (type)
	{
	case ItemType::Potion:
		std::cout << "포션 (Hp +50)";
		break;

	case ItemType::AttackBoost:
		std::cout << "부스터(공격력,전투시에만 상승) (Att +50)";
		break;

	}

}