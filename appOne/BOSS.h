#pragma once
#include "CHARACTER.h"
class BOSS :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int jumpFlag = 0;
        int fallFlag = 0;
        float curWx = 0;
        float initVecUp = 0;
        float initVecDown = 0;
        float initVecX = 0;
        float initVecY = 0;
        float gravity = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
        float damageTime = 0;
        float damageInterval = 0;
        COLOR damageColor;
        COLOR normalColor;
    };
private:
    DATA Boss;
public:
    BOSS(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void ChangeColor();
    void damage();
private:
    void Move();
    void CollisionWithMap();
};

