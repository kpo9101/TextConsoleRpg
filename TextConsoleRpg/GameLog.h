<<<<<<< HEAD:GameLog.h
#pragma once
#include <string>
#include <fstream>

// 게임 로그를 콘솔 + 파일에 기록하는 클래스
class GameLog
{
public:
    // 기본 파일명은 game.log
    GameLog(const std::string& filePath = "game.log");

    // 파일 리소스 정리
    ~GameLog();

    // 로그 한 줄 기록
    void Write(const std::string& message);

private:
    // 로그 파일 스트림
    std::ofstream file;
};
=======
#pragma once
#include <string>
#include <fstream>

// 로그 종류
enum class LogType {
    System,   // 시스템 메시지
    Combat,   // 전투
    LevelUp,  // 레벨업
    Item      // 아이템
};

// 콘솔 + 파일에 로그를 기록
class GameLog {
public:
    GameLog(const std::string& filePath = "game.log"); // 파일 열기
    ~GameLog();                                         // 파일 닫기

    // 로그 1줄 기록
    void write(LogType type, const std::string& message);

private:
    std::ofstream file_; // 로그 파일 스트림

    std::string nowTime() const;            // 현재 시간 문자열 생성
    std::string typeToText(LogType type) const; // 로그 타입 한글 변환
};
>>>>>>> GameManager:TextConsoleRpg/GameLog.h
