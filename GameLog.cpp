#include "GameLog.h"
#include <iostream>

GameLog::GameLog(const std::string& filePath) {
    file_.open(filePath, std::ios::app); // 파일 이어쓰기
}

GameLog::~GameLog() {
    if (file_.is_open()) file_.close();
}

void GameLog::write(const std::string& message) {
    std::cout << message << "\n";          // 콘솔 출력
    if (file_.is_open()) file_ << message << "\n"; // 파일 저장
}
