#include <windows.h>
#include "GameLog.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    GameLog log;
    log.write(u8"게임 시작");
    log.write(u8"플레이어1이 슬라임3을 공격하여 25 피해");
    log.write(u8"플레이어1이 레벨업");
    log.write(u8"플레이어1이 아이템 획득: 나무검");

    return 0;
}
