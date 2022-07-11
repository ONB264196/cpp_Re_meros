#pragma once
#include"CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int jumpFlag = 0;
        float curWx = 0;
        float initVecDown = 0;
        float gravity = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
        float remain = 0;
        int jumpSnd = 0;
        int landingSnd = 0;
        int throwSnd = 0;
        int fallSnd = 0;
        int diedSnd = 0;
    };
    float TR = 0;
    char r = 'C';
    enum class STATE { STRUGGLING, DIED, FALL, SURVIVED };
    STATE State = STATE::STRUGGLING;
private:
    DATA Player;
public:
    PLAYER(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float  wx, float wy, float vx, float vy);
    void update();
private:
        void Launch();
        void Move();
        void CollisionWithMap();
public:
    void CheckState();
    void damage();
    void evaluation();
    bool died();
    bool survived();
    float overCenterVx();
};
