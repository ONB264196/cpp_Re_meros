#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "CAT.h"

void CAT::create()
{
	Chara = game()->container()->data().catChara;
	Cat = game()->container()->data().cat;
}

void CAT::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().catChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = Cat.initVecX;
	Chara.vy = Cat.initVecY;
	Chara.animId = Cat.leftAnimId;
	Cat.fallFlag = 0;
}

void CAT::update()
{
}