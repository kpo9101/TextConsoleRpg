#include "GameLog.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

GameLog::GameLog(const std::string& filePath) {
    // 이어쓰기 기능
    file_.open(filePath, std::ios::app);
}

GameLog::~GameLog() {
    if (file_.is_open()) {
        file_.close();
    }
}

void GameLog::write(LogType type, const std::string& message) {
    // 최종 출력 형식: [시간] [타입] 메시지
    std::string line = "[" + nowTime() + "] [" + typeToText(type) + "] " + message;

    std::cout << line << "\n";      // 콘솔 출력
    if (file_.is_open()) {
        file_ << line << "\n";      // 파일 저장
    }
}

std::string GameLog::nowTime() const {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm tmLocal{};
#ifdef _WIN32
    localtime_s(&tmLocal, &t);
#else
    localtime_r(&t, &tmLocal);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tmLocal, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string GameLog::typeToText(LogType type) const {
    switch (type) {
    case LogType::System:  return "시스템";
    case LogType::Combat:  return "전투";
    case LogType::LevelUp: return "레벨업";
    case LogType::Item:    return "아이템";
    default:               return "알수없음";
    }
}
