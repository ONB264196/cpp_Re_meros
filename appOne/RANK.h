#pragma once
#include "GAME_OBJECT.h"
class RANK :
    public GAME_OBJECT
{
public:
    RANK(class GAME* game) : GAME_OBJECT(game) {}
    void creat();
    void rank();
};

