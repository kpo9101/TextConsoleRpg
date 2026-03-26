#pragma once
#include <vector>
#include <iostream>
#include "PlayerCharacter.h"

template <typename T>
class Inventory
{
private:
    std::vector<T> items;

public:
    void AddItem(const T& item)
    {
        items.push_back(item);
    }

    void ShowItems() const
    {
        std::cout << "\n=== 인벤토리 ===\n";

        for (size_t i = 0; i < items.size(); ++i)
        {
            std::cout << i << ": ";
            items[i].Print();
            std::cout << std::endl;
        }
    }

    void UseItem(size_t index, PlayerCharacter& player)
    {
        if (index >= items.size())
        {
            std::cout << "잘못된 선택\n";
            return;
        }

        items[index].Use(player);

        items.erase(items.begin() + index);
    }

    bool IsEmpty() const
    {
        return items.empty();
    }

    size_t GetSize() const
    {
        return items.size();
    }
};