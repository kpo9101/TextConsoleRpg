#include "Monster.h"
#include <iostream>
#include <cstdlib>

// Slime 구현
Slime::Slime(int level) 
{
    name = "슬라임";
    health = 20 + (level * 5);
    attack = 5 + level;
}
std::string Slime::getName() { return name; }
int Slime::getHealth() { return health; }
int Slime::getAttack() 
{
    std::cout << name << "슬라임의 공격! (" << attack << " 데미지)" << std::endl;
    return attack;
}
void Slime::takeDamage(int damage) 
{
    health -= damage;
}

WildBoar::WildBoar(int level) 
{
    name = "멧돼지";
    health =30 + (level * 5);
    attack = 7 + level;
}
std::string WildBoar::getName() { return name; }
int WildBoar::getgHealth() { return health; }
    health = 30 + (level * 5);
    attack = 7 + level;
}
std::string WildBoar::getName() { return name; }
int WildBoar::getHealth() { return health; }
>>>>>>> main:TextConsoleRpg/Monster.cpp
int WildBoar::getAttack()
{
    std::cout << name << "의 돌진! (" << attack << " 데미지)" << std::endl;
    return attack;
}
void WildBoar::takeDamage(int damage) 
{
    health -= damage;
}

// 그림자 기사 구현부
ShadowKnight::ShadowKnight() 
{
    name = "그림자 기사";
    health = 200;
    attack = 25;
}
std::string ShadowKnight::getName() { return name; }
int ShadowKnight::getHealth() { return health; }
int ShadowKnight::getAttack() 
{
    int pattern = std::rand() % 2;
    if (pattern == 0) 
    {
        std::cout << name << "의 검 공격! " << attack << " 데미지!" << std::endl;
        return attack;
    }
    else 
    {
        std::cout << name << "의 돌진! " << attack + 15 << " 데미지!" << std::endl;
        return attack + 15;
    }
}
void ShadowKnight::takeDamage(int damage) { health -= damage; }

// 마왕 구현부
DemonKing::DemonKing() 
{
    name = "마왕";
    health = 500;
    attack = 50;
}
std::string DemonKing::getName() { return name; }
int DemonKing::getHealth() { return health; }
int DemonKing::getAttack() 
{
    int pattern = std::rand() % 3;
    switch (pattern) 
    {
        case 0: std::cout << "마왕의 화염구! " << attack << " 데미지!" << std::endl; return attack;
        case 1: std::cout << "마왕의 번개 폭풍! " << attack * 2 << " 데미지!" << std::endl; return attack * 2;
        default: std::cout << "마왕의 저주! " << attack / 2 << " 데미지!" << std::endl; return attack / 2;
    }
}
void DemonKing::takeDamage(int damage) { health -= damage; }