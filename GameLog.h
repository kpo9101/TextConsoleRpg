#pragma once
#include <string>
#include <fstream>

class GameLog {
public:
    GameLog(const std::string& filePath = "game.log");
    ~GameLog();

    void write(const std::string& message); // 로그 한 줄 기록

private:
    std::ofstream file_;
};
