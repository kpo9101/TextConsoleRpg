#ifndef MONSTER_H
#define MONSTER_H

#include <string>

//몬스터 클래스 
class Monster
{
protected:
    std::string name;
    int health = 0;
    int attack = 0;

public:
    virtual ~Monster() {}
    virtual std::string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual void takeDamage(int damage) = 0;
};

// 하위 클래스
class Slime : public Monster 
{
public:
    Slime(int level);
    std::string getName() override;
    int getHealth() override;
    int getAttack() override;
    void takeDamage(int damage) override;
};
class WildBoar : public Monster 
{
public:
    WildBoar(int level);
    std::string getName() override;
    int getHealth() override;
    int getAttack() override;
    void takeDamage(int damage) override;
};
class ShadowKnight : public Monster 
{
public:
    ShadowKnight(int level);
    std::string getName() override;
    int getHealth() override;
    int getAttack() override;
    void takeDamage(int damage) override;
};
class DemonKing : public Monster 
{
public:
    DemonKing(int level);
    std::string getName() override;
    int getHealth() override;
    int getAttack() override;
    void takeDamage(int damage) override;
};



#endif