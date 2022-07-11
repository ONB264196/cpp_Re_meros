#pragma once
#include "CHARACTER.h"
class BOSS :
    public CHARACTER
{
public:
    struct DATA {
        float TelapsedTime = 0;
        float Tinterval = 0;
        int triggerCnt = 0;
        int triggerInterval = 0;
        int trigger1st = 0;
        int trigger2nd = 0;
        int trigger3rd = 0;
        int trigger4th = 0;
        float bulletOffsetX = 0;
        char bulletCharaId = 0;

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
        float MelapsedTime = 0;
        float Minterval = 0;
        int moveCnt = 0;
        int moveInterval = 0;
        int move1st = 0;
        int move2nd = 0;
        int move3rd = 0;
        int move4th = 0;
        int move5th = 0;
        int move6th = 0;

        float damageTime = 0;
        float damageInterval = 0;
        COLOR damageColor;
        COLOR normalColor;

        int jumpSnd = 0;
        int landingSnd = 0;
        int throwSnd = 0;
    };
private:
    DATA Boss;
public:
    BOSS(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void Launch();
    void Algorithm();
    void ChangeColor();
    void damage();
private:
    void Move();
    void CollisionWithMap();
};

