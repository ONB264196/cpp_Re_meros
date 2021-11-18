#pragma once
#include "CHARACTER.h"
class ITEM :
    public CHARACTER
{
public:
    struct DATA{
        
    };
    enum item{
        SportsDrink,
        Tobiuo
    };
private:
    DATA Item;
public:
    ITEM(class GAME* game) : CHARACTER(game) {}
    void create();
    void appear(float wx, float wy);
    void update();
};

