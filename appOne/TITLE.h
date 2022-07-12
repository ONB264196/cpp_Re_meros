#pragma once
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    TITLE(class GAME* game) : SCENE(game) {}
    struct DATA {
        int startSnd = 0;
    };
private:
    DATA Title;
public:
    void init();
    void draw();
    void nextScene();

};