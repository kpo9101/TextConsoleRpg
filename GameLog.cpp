#include "GameLog.h"
#include <iostream>

// 생성자: 로그 파일을 이어쓰기 모드로 연다.
// (기존 로그를 유지하면서 뒤에 추가)
GameLog::GameLog(const std::string& filePath)
{
    file.open(filePath, std::ios::app);
}

// 소멸자: 파일이 열려 있으면 닫는다.
GameLog::~GameLog()
{
    if (file.is_open())
    {
        file.close();
    }
}

// 로그 기록 함수
// 1) 콘솔에 출력
// 2) 파일이 열려 있으면 파일에도 저장
void GameLog::Write(const std::string& message)
{
    //메시지에 "ERROR"가 포함되어 있으면 "[ERROR]" 출력
    bool isError = message.find("ERROR") != std::string::npos;
    std::string line = isError ? "[ERROR] " + message : message;
    
    std::cout << message << std::endl;

    if (file.is_open())
    {
        file << message << std::endl;
    }
}