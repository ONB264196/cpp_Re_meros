#pragma once
#include "SCENE.h"
class CLEAR :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        float backToTitleTime = 0;
    };
private:
    DATA Clear;
public:
    CLEAR(class GAME* game) : SCENE(game) {}
    void init();
    void draw();
    void nextScene();
};
