// PlayerCharacter.cpp
#include "PlayerCharacter.h"
#include "Inventory.h"
#include <iostream>
#include <string>

PlayerCharacter::PlayerCharacter(std::string name) :
<<<<<<< HEAD
	  name(name),
	  Level(1)
	, Health(200)
	, MaxHealth(200)
	, Attack(30)
	, Experience(0)
	, Gold(0)
	,TempAttackBoost(0)
=======
	  name(name)
	, Level (1)
	, Health (200)
	, MaxHealth (200)
	, Attack (30)
	, Experience (0)
	, Gold(0) 
	, TempAttackBoost (0)
>>>>>>> f7b5e2c98e56ac5d2616d17badfb6cf845fbdcba
{
	//기본 아이템 지급
	inventory.AddItem(Item(ItemType::Potion));
	inventory.AddItem(Item(ItemType::AttackBoost));

	while (true)
	{
		int num = 0;
		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "[1]나의 정보 확인" << std::endl;
		std::cout << "[2]아이템 확인" << std::endl;
		std::cout << "[3]게임 로그 확인" << std::endl;
		std::cout << "[4]전투" << std::endl;
		std::cin >> num;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (num == 1)
		{
			ShowStatus();
		}
		if (num == 2)
		{
			inventory.ShowItems();

			if (inventory.IsEmpty())
			{
				std::cout << "아이템이 없습니다.\n";
				continue;
			}
			std::cout << "사용할 아이템 번호 선택 (0 취소) : ";
			int choice;
			std::cin >> choice;

			if (choice == 0)
			{
				continue;
			}

			if (choice > inventory.GetSize())
			{
				std::cout << "잘못된 선택\n";
				continue;
			}

			inventory.UseItem(choice - 1, *this);

		}
		if (num == 3)
		{
			// 게임 로그 확인 창 연결
		}
		if (num == 4)
		{
			//전투 연결
		}
	}
}
void PlayerCharacter::ShowStatus()
{
	std::cout << "\n---" << name << "의 정보---" << std::endl;
	std::cout << "이름 : " << name << std::endl;
	std::cout << "레벨 : " << Level << std::endl;
	std::cout << "체력 : " << Health << "/" << MaxHealth << std::endl;
	std::cout << "공격력 : " << Attack << std::endl;
	std::cout << "경험치 : " << Experience << "/" << MaxExperience << std::endl;
	std::cout << "골드 : " << Gold << std::endl << std::endl;
}
void PlayerCharacter::LevelUp()
{
	std::cout << "축하합니다!! 레벨업!" << std::endl;
	Level += 1;
	Attack += 10;
	MaxHealth += 50;
	Health = MaxHealth;
}

void PlayerCharacter::GetExp(int exp) // 전투 종료후 불러올 함수
{
	int fixExp = 50;
	std::cout << fixExp << " 경험치를 획득했습니다!" << std::endl;
	Experience += fixExp;


	while (Experience >= 100)
	{
		Experience -= 100;
		LevelUp();
	}

}
//Item관련
bool PlayerCharacter::Heal(int amount)
{
	if (Health >= MaxHealth)
	{
		std::cout << "이미 체력이 가득 찼습니다 .\n";
		return false;
	}

	int before = Health;

	Health += amount;

	if(Health>MaxHealth)
	
		Health = MaxHealth;
	
	std::cout << "체력 +" << (Health-before) << std::endl;

	return true;
}

void PlayerCharacter::ApplyAttackBoost(int value)
{
	TempAttackBoost += value;
	std::cout << "공격력 +" << value << " (전투 중)\n";
}

int PlayerCharacter::GetTotalAttack() const
{
	return Attack + TempAttackBoost;
}

void PlayerCharacter::ResetBattleState()//전투 후 공격력 상승 초기화
{
	TempAttackBoost = 0;
}