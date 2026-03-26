// Main.cpp

#include <iostream>
#include <string>
#include "PlayerCharacter.h"


int main(void)
{
	int select;
	std::string Name;
	std::cout << "평화롭던 '스파르타' 왕국에 갑자기 나타난 **'마왕'**이 왕국의 보물을 훔쳐 달아났습니다. \n 보물이 없으면 왕국의 결계가 깨져 몬스터들이 쳐들어오게 됩니다. \n 당신은 국왕의 부름을 받은 초보 용사입니다.";
	std::cout << std::endl << "용사님, 당신의 이름을 입력하십시오." << std::endl;
	std::getline(std::cin, Name);
	std::cout << "당신의 이름은 \"" << Name << "\" 이군요" << std::endl;

	while (true)
	{
		std::cout << std::endl << "당신은 고민합니다." << std::endl;
		std::cout << "[1]나는 이 상황을 변화시킬 힘이 없다 용사를 포기한다." << std::endl;
		std::cout << "[2]나는 그림자 마왕을 쓰러뜨리고, 왕국의 보물을 되찾을 것이다." << std::endl;
		std::cin >> select;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (select == 1)
		{
			std::cout << "당신은 왕국과 용사가 되기를 포기하고 스파르타 왕국을 떠났습니다..." << std::endl;
			return 0;
		}
		else if (select == 2)
		{
			std::cout << "당신은 용사가 되어 왕국의 보물을 되찾고 결계를 복구하여 모두를 지킬 것을 선택했습니다." << std::endl;
			PlayerCharacter* Player = new PlayerCharacter(Name);

			delete Player;
			Player = nullptr;
		}
		else
		{
			std::cout << "잘못된 입력입니다! '1'또는 '2'를 입력하십시오.";
			continue;
		}


	}

	return 0;
}