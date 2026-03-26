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