#pragma once
#include "GAME_OBJECT.h"
class RANK :
    public GAME_OBJECT
{
public:
    struct DATA {
        int SImg = 0;
        int AImg = 0;
        int BImg = 0;
        int CImg = 0;
        int applauseSnd = 0;
    };
private:
    DATA Rank;
public:
    void dispRank(char r);
    RANK(class GAME* game) : GAME_OBJECT(game) {}
};

