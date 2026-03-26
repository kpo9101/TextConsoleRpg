// GameManager.cpp

#include "GameManager.h"

GameManager::GameManager() {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
}

GameManager::~GameManager() {

}

Monster* GameManager::generateMonster(int level) {
    std::cout << "\n";

    if (level == 10) {
        std::cout << "최종 보스 'DemonKing' 출현!!!" << std::endl;
        return new DemonKing(level);
    }
    else if (level == 6) {
        std::cout << "중간보스 'ShadowKnight' 출현!" << std::endl;
 
        return new ShadowKnight(level);
    }
    else if (level >= 1 && level <= 3) {
        return new Slime(level);           
    }
    else if (level >= 4 && level <= 5) {
        return new WildBoar(level);       
    }
    else if (level >= 7 && level <= 9) {
        if (std::rand() % 2 == 0) {
            return new Slime(level);
        }
        else {
            return new WildBoar(level);
        }
    }

}

void GameManager::battle(PlayerCharacter* player) {
    std::cout << "\n 전투 시작! \n" << std::endl;

    // 플레이어 턴
    int currentLevel = player->GetLevel();
    Monster* monster = generateMonster(currentLevel);

    std::cout << monster->getName() << " [레벨 " << currentLevel << "] 등장!" << std::endl;

    while (monster->getHealth() > 0 && player->GetHealth() > 0) { 
        
        int playerDamage = player->GetTotalAttack();
        monster->takeDamage(playerDamage);
        std::cout << "플레이어가 " << monster->getName() << "에게 " << playerDamage << " 데미지를 입혔다!" << std::endl;

        if (monster->getHealth() <= 0) break; // 몬스터 hp 0 확인

        //몬스터 턴
        std::cout << "\n--- " << monster->getName() << "공격" << std::endl;
        int monsterDamage = monster->getAttack();   
        player->takeDamage(monsterDamage);        

        // 전투 시작으로 가면서 계속 확인
        std::cout << "몬스터 HP: " << monster->getHealth() << std::endl << std::endl;
    }

    // 몬스터 사망
    if (monster->getHealth() <= 0) {
        std::cout << " 전투 승리! " << monster->getName() << "을 물리쳤습니다!\n" << std::endl;
        player->GetExp(50);


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
    else {
        std::cout << "GAME OVER" << std::endl;
  
        exit(0);
    }

    player->ResetBattleState();
    delete monster;
}

