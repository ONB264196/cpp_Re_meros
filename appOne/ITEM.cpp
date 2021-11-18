#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "ITEM.h"

void ITEM::create()
{
	Chara = game()->container()->data().itemChara;
	Item = game()->container()->data().item;
}

void ITEM::appear(float wx, float wy)
{
	Chara.hp = game()->container()->data().itemChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
}

void ITEM::update()
{
}
