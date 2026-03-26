#include "GameLog.h"

int main()
{
    GameLog log; // 기본 파일명: game.log

    log.Write("[로그] 게임 시작");
    log.Write("[로그] 플레이어 생성 완료");
    log.Write("[로그] 튜토리얼 진입");

    return 0;
}