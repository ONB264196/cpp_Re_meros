#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "SPORTS_DRINK.h"

void SPORTS_DRINK::create()
{
	Chara = game()->container()->data().spotrs_drinkChara;
	Sports_drink = game()->container()->data().sports_drink;
}

void SPORTS_DRINK::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().spotrs_drinkChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
}

void SPORTS_DRINK::update()
{

}
