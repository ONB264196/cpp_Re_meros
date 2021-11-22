#pragma once
#include "CHARACTER.h"
class BOSS_BULLET :
    public CHARACTER
{
    BOSS_BULLET(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();

};

