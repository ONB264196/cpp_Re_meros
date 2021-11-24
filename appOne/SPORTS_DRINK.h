#pragma once
#include "CHARACTER.h"
class SPORTS_DRINK :
    public CHARACTER
{
public:
    struct DATA {};
private:
    DATA Sports_drink;
public:
    SPORTS_DRINK(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
};

