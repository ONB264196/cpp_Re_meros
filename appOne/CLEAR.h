#pragma once
#include "SCENE.h"
class CLEAR :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        int logoImg = 0;
        float logoPx;
        float logoPy;
        float backToTitleTime = 0;
    };
public:
    CLEAR(class GAME* game) : SCENE(game) {}
    void init();
    void draw();
    void nextScene();
};
