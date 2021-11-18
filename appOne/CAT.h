#pragma once
#include "CHARACTER.h"
class CAT :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int fallFlag = 0;
        float curWx = 0;
        float initVecX = 0;
        float initVecY = 0;
        float gravity = 0;
    };
private:
    DATA Cat;
public:
    CAT(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
private:
    void Move();
    void CollisionWithMap();
};

