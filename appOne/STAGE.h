#pragma once
#include "SCENE.h"
#include"COLOR.h"
#include"PLAYER.h"

class STAGE :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        int T0Img = 0;
        int T1Img = 0;
        int T2Img = 0;
        int T3Img = 0;
        int T4Img = 0;
        int T5Img = 0;
        int T6Img = 0;
        int T7Img = 0;
        int T8Img = 0;
        int T9Img = 0;
        int stageClearImg = 0;
        int gameOverImg = 0;
        float nextToRankTime = 0;
        COLOR backColor;
        COLOR gameOverColor;
        COLOR stageClearColor;
        float logoPx = 0;
        float logoPy = 0;
        float tImgSize = 0;
        float lmtTImgSize = 0;
        float timePx = 0;
        float timeOfsX = 0;
        float lmtTimePx = 0;
        float timePy = 0;
        float lmtTimePy = 0;
        int BGM = 0;
    };
    float TR = 0;
    DATA Stage;
private:
    void BackGround();
    void Logo(int img, const COLOR& color);
public:
    STAGE(class GAME* game) : SCENE(game) {}
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
    void disptime(float t);
};

