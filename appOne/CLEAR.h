#include "SCENE.h"
class CLEAR :
    public SCENE
{
public:
    CLEAR(class GAME* game) : SCENE(game) {}
    void init();
    void draw();
    void nextScene();

};
