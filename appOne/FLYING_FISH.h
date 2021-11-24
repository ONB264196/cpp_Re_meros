#pragma once
#include "CHARACTER.h"
class FLYING_FISH :
    public CHARACTER
{
public:
    struct DATA {};
private:
    DATA Flying_fish;
public:
    FLYING_FISH(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
};

