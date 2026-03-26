#include <windows.h>
#include "GameLog.h"

int main() {
    // 팀 테스트용 샘플 로그
    log.write(LogType::System, u8"게임 시작");
    log.write(LogType::Combat, u8"플레이어1이 슬라임3을 공격하여 25 피해");
    log.write(LogType::LevelUp, u8"플레이어1이 레벨 2로 상승");
    log.write(LogType::Item, u8"플레이어1이 아이템 획득: 나무검");

    return 0;
}
