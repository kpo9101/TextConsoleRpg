// PlayerCharacter.cpp
#include "PlayerCharacter.h"
#include "Inventory.h"
#include "GameManager.h"

#include <iostream>
#include <string>

PlayerCharacter::PlayerCharacter(std::string name) :
	  name(name)
	, Level (1)
	, Health (200)
	, MaxHealth (200)
	, Attack (30)
	, Experience (0)
	, Gold(100) 
	, TempAttackBoost (0)
{
	Game = new GameManager;
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
		std::cout << "[5]상점" << std::endl;
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
			Game->battle(this);          
		
		}
		if (num == 5)
		{
			OpenShop();
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
	std::cout << "→ 현재 레벨 : " << Level + 1 << std::endl;
	Level += 1;
	Attack += 10;
	MaxHealth += 50;
	Health = MaxHealth;

	if (Level >= 10) {
		std::cout << "만렙 달성" << std::endl;
		return;
	}

}

void PlayerCharacter::GetExp(int exp) // 전투 종료후 불러올 함수
{
	std::cout << exp << " 경험치를 획득했습니다!" << std::endl;
	Experience += exp;

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
void PlayerCharacter::OpenShop()
{
	while (true)
	{
		std::cout << "\n=== 상점 ===\n";
		std::cout << "보유 골드: " << Gold << "\n";
		std::cout << "[1] 아이템 구매\n";
		std::cout << "[2] 아이템 판매\n";
		std::cout << "[0] 나가기\n";

		int choice;
		std::cin >> choice;

		if (choice == 0)
			return;

		//구매
		if (choice == 1)
		{
			std::cout << "\n[구매]\n";
			std::cout << "1. 포션 (50골드)\n";
			std::cout << "2. 공격력 부스터 (100골드)\n";

			int buy;
			std::cin >> buy;

			Item item = Item(ItemType::Potion);
			int price = 0;

			if (buy == 1)
			{
				item = Item(ItemType::Potion);
				price = item.GetPrice();
			}
			else if (buy == 2)
			{
				item = Item(ItemType::AttackBoost);
				price = item.GetPrice();
			}
			else
			{
				std::cout << "잘못된 선택\n";
				continue;
			}

			if (Gold < price)
			{
				std::cout << "골드 부족!\n";
				continue;
			}

			Gold -= price;
			inventory.AddItem(item);
			std::cout << "구매 완료!\n";
		}

		//판매
		else if (choice == 2)
		{
			std::cout << "\n[판매]\n";
			inventory.ShowItems();

			if (inventory.IsEmpty())
			{
				std::cout << "판매할 아이템 없음\n";
				continue;
			}

			std::cout << "판매할 아이템 번호 선택 (0 취소): ";
			int sell;
			std::cin >> sell;

			if (sell == 0)
				continue;

			if (sell > inventory.GetSize())
			{
				std::cout << "잘못된 선택\n";
				continue;
			}

			Item item = inventory.GetItem(sell - 1);

			int sellPrice = item.GetPrice() * 0.6; 

			Gold += sellPrice;
			inventory.RemoveItem(sell - 1);

			std::cout << sellPrice << " 골드 획득!\n";
		}

		else
		{
			std::cout << "잘못된 선택\n";
		}
	}
}

// 여기 밑에는 추가한 내용

int PlayerCharacter::GetLevel() const  // 레벨 불러오기
{
	return Level;
}

void PlayerCharacter::takeDamage(int damage)   // 플레이어가 데미지를 받는 것
{
	Health -= damage;
	if (Health < 0) {
		std::cout << "[몬스터 공격]" << name << "가" << damage << "데미지 입음! 남은 Hp: " << Health << std::endl;
	}
}

int PlayerCharacter::GetHealth() const   // 현재 health 확인
{
	return Health;
}

void PlayerCharacter::AddItem(const Item& item)
{
	inventory.AddItem(item);
	std::cout << " " << name << "아이템 획득!" << std::endl;
}


void PlayerCharacter::BattleItem()
{

	while (1)
	{
		inventory.ShowItems();
		if (inventory.IsEmpty())
		{
			std::cout << "아이템이 없습니다.\n";
			return;
		}

		std::cout << "사용할 아이템 번호 선택 (0 입력시 취소) : ";
		int choice;
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "숫자만 입력해주세요";
			continue;
		}

		if (choice ==0)
		{
			std::cout << " 아이템 사용 취소 \n" << std::endl;
			return;
		}

		if (choice > inventory.GetSize())
		{
			std::cout << "잘못된 선택\n";
			return;
		}
		inventory.UseItem(choice - 1, *this);
	}
	
}

std::string PlayerCharacter::GetName() const
{
	return name;
}