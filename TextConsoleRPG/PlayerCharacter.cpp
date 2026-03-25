// PlayerCharacter.cpp
#include "PlayerCharacter.h"
#include <iostream>

PlayerCharacter::PlayerCharacter(std::string name) :
	  Level (1)
	, Health (200)
	, MaxHealth (200)
	, Attack (30)
	, Experience (0)
	, Gold(0) 
{
	while (true)
	{
		int num = 0;
		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "[1]나의 정보 확인" << std::endl;
		std::cout << "[2]아이템 확인" << std::endl;
		std::cout << "[3]게임 로그 확인" << std::endl;
		std::cout << "[4]전투" << std::endl;
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
			// 아이템 함수 연결
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
	std::cout << "경험치	: " << Experience << std::endl;
	std::cout << "골드 : " << Gold << std::endl;
}
void PlayerCharacter::LevelUp()
{
	std::cout << "레벨업 함수";
	Level += 1;
}

void PlayerCharacter::GetExp(int exp)
{
	std::cout << "경험치를 획득했습니다!" << std::endl;
	Experience += exp;

	while (Experience >= 100)
	{
		Experience -= 100;
		LevelUp();
	}

}

