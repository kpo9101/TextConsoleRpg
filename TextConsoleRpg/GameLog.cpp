<<<<<<< HEAD:GameLog.cpp
<<<<<<< HEAD
#include "GameLog.h"
#include <iostream>

// »ı¼ºÀÚ: ·Î±× ÆÄÀÏÀ» ÀÌ¾î¾²±â ¸ğµå·Î ¿¬´Ù.
// (±âÁ¸ ·Î±×¸¦ À¯ÁöÇÏ¸é¼­ µÚ¿¡ Ãß°¡)
GameLog::GameLog(const std::string& filePath)
{
    file.open(filePath, std::ios::app);
}

// ¼Ò¸êÀÚ: ÆÄÀÏÀÌ ¿­·Á ÀÖÀ¸¸é ´İ´Â´Ù.
GameLog::~GameLog()
{
    if (file.is_open())
    {
        file.close();
    }
}

// ·Î±× ±â·Ï ÇÔ¼ö
// 1) ÄÜ¼Ö¿¡ Ãâ·Â
// 2) ÆÄÀÏÀÌ ¿­·Á ÀÖÀ¸¸é ÆÄÀÏ¿¡µµ ÀúÀå
void GameLog::Write(const std::string& message)
{
    std::cout << message << std::endl;

    if (file.is_open())
    {
        file << message << std::endl;
    }
=======
#include "GameLog.h"
#include <iostream>

// »ı¼ºÀÚ: ·Î±× ÆÄÀÏÀ» ÀÌ¾î¾²±â ¸ğµå·Î ¿¬´Ù.
// (±âÁ¸ ·Î±×¸¦ À¯ÁöÇÏ¸é¼­ µÚ¿¡ Ãß°¡)
GameLog::GameLog(const std::string& filePath)
{
    file.open(filePath, std::ios::app);
}

// ¼Ò¸êÀÚ: ÆÄÀÏÀÌ ¿­·Á ÀÖÀ¸¸é ´İ´Â´Ù.
GameLog::~GameLog()
{
    if (file.is_open())
    {
        file.close();
    }
}

// ·Î±× ±â·Ï ÇÔ¼ö
// 1) ÄÜ¼Ö¿¡ Ãâ·Â
// 2) ÆÄÀÏÀÌ ¿­·Á ÀÖÀ¸¸é ÆÄÀÏ¿¡µµ ÀúÀå
void GameLog::Write(const std::string& message)
{
    std::cout << message << std::endl;

    if (file.is_open())
    {
        file << message << std::endl;
    }
>>>>>>> Mine
}
=======
ï»¿#include "GameLog.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

GameLog::GameLog(const std::string& filePath) {
    // ì´ì–´ì“°ê¸° ê¸°ëŠ¥
    file_.open(filePath, std::ios::app);
}

GameLog::~GameLog() {
    if (file_.is_open()) {
        file_.close();
    }
}

void GameLog::write(LogType type, const std::string& message) {
    // ìµœì¢… ì¶œë ¥ í˜•ì‹: [ì‹œê°„] [íƒ€ì…] ë©”ì‹œì§€
    std::string line = "[" + nowTime() + "] [" + typeToText(type) + "] " + message;

    std::cout << line << "\n";      // ì½˜ì†” ì¶œë ¥
    if (file_.is_open()) {
        file_ << line << "\n";      // íŒŒì¼ ì €ì¥
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
    case LogType::System:  return "ì‹œìŠ¤í…œ";
    case LogType::Combat:  return "ì „íˆ¬";
    case LogType::LevelUp: return "ë ˆë²¨ì—…";
    case LogType::Item:    return "ì•„ì´í…œ";
    default:               return "ì•Œìˆ˜ì—†ìŒ";
    }
}
>>>>>>> GameManager:TextConsoleRpg/GameLog.cpp
