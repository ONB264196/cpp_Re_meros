#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "SHEEP.h"

void SHEEP::create()
{
	Chara = game()->container()->data().sheepChara;
	Sheep = game()->container()->data().sheep;
}

void SHEEP::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().sheepChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = Sheep.initVecX;
	Chara.vy = Sheep.initVecY;
	Chara.animId = Sheep.leftAnimId;
	Sheep.fallFlag = 0;
}

void SHEEP::update()
{
}