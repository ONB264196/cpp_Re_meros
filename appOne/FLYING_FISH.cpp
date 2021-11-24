#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "FLYING_FISH.h"

void FLYING_FISH::create()
{
	Chara = game()->container()->data().flying_fishChara;
	Flying_fish = game()->container()->data().flying_fish;
}

void FLYING_FISH::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().flying_fishChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
}

void FLYING_FISH::update()
{
}
