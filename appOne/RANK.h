#pragma once
#include "GAME_OBJECT.h"
class RANK :
    public GAME_OBJECT
{
public:
    struct DATA {
        int hp;
        int damage;
        int debuff;
    };
private:
    DATA Rank;
public:
    RANK(class GAME* game) : GAME_OBJECT(game) {}
    void create();
    virtual void rank(int hp, int d, int db);
};

