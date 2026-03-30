// GameManager.cpp

#include "GameManager.h"
#include "PlayerCharacter.h"
#include "Inventory.h"
#include "MonsterAA.h"


GameManager::GameManager() {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
}

GameManager::~GameManager() {

}

Monster* GameManager::generateMonster(int level) 
{
    std::cout << "\n";

    if (level == 10) 
    {
        std::cout << "최종 보스 'DemonKing' 출현!!!" << std::endl;
        bClearDemonKing = true;
        std::cout << MonsterAA::DemonKing << std::endl;
        return new DemonKing(level);
    }
    else if (level == 6 && !bClearShadowKnight) {
        std::cout << "중간보스 'ShadowKnight' 출현!" << std::endl;
        bClearShadowKnight = true;
        std::cout << MonsterAA::ShadowKnight << std::endl;
        return new ShadowKnight(level);
    }
    else if (rand() % 2 == 0)
    {
        std::cout << MonsterAA::Slime << std::endl;
        return new Slime(level);
    }
    else
    {
        std::cout << MonsterAA::WildBoar << std::endl;
        return new WildBoar(level);
    }
}

void GameManager::battle(PlayerCharacter* player) {
    std::cout << "\n 전투 시작! \n" << std::endl;

    // 플레이어 턴
    int currentLevel = player->GetLevel();
    Monster* monster = generateMonster(currentLevel);

    if (monster == nullptr) return;  

    std::cout << monster->getName() << " [레벨 " << currentLevel << "] 등장!" << std::endl;

    while (monster->getHealth() > 0 && player->GetHealth() > 0) {
        std::cout << " 당신의 선택은?" << std::endl;
        std::cout << " 1. 공격" << std::endl;
        std::cout << " 2. 아이템 사용" << std::endl;
        std::cout << " 3. Run" << std::endl;

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "숫자 입력해주세요";
            continue;
        }

        if (choice == 1)
        {
            int playerDamage = player->GetTotalAttack();
            monster->takeDamage(playerDamage);
            std::cout << "[" << player->GetName() << "] 공격! \n" << monster->getName() << "에게" << playerDamage << " 데미지 주었다!" << std::endl;
        }
        else if (choice == 2)
        {
            player->BattleItem();
        }
        else if (choice == 3)
        {
            std::cout << "RUN \n";
            break; // 게임 종료
        }
        else {
            std::cout << "1,2,3 중 택 1 해주세요" << std::endl;
            continue;
        }

        if (monster->getHealth() <= 0) break;
        // 몬스터 hp 0 확인

        std::cout << "\n--- " << monster->getName() << "공격" << std::endl;
        int monsterDamage = monster->getAttack();
        player->takeDamage(monsterDamage);

        std::cout << "플레이어 HP: " << player->GetHealth() << std::endl;
        std::cout << "몬스터 HP: " << monster->getHealth() << std::endl;
    }

            // 몬스터 사망
                if (monster->getHealth() <= 0) {
                    std::cout << " 전투 승리! " << monster->getName() << "을 물리쳤습니다!\n" << std::endl;
                    player->GetExp(50);
                    player->Getgold(std::rand() % 51);

                    if (std::rand() % 2 == 0) {
                        player->AddItem(Item(ItemType::Potion));
                    }
                    else {
                        player->AddItem(Item(ItemType::AttackBoost));
                    }

                    if (monster->getName() == "마왕") {
                        std::cout << "\n GAME CLEAR!!!" << std::endl;
                        exit(0);
                    }
                }
            
            else if(player->GetHealth() <=0 && monster->getHealth() > 0){
                std::cout << "GAME OVER" << std::endl;
                exit(0);
                }
            
            // 소멸
            player->ResetBattleState();
            delete monster;
}


void GameManager::displayInventory(PlayerCharacter* Player)
{
    Player->ShowStatus();          
    std::cout << "[인벤토리]" << std::endl;

}