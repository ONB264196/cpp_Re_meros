#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BOSS_BULLET.h"

void BOSS_BULLET::create()
{
	Chara = game()->container()->data().bossBulletChara;
}

void BOSS_BULLET::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().bossBulletChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = vx;
}

void BOSS_BULLET::update()
{
	Chara.wx += Chara.vx * (Chara.speed * delta);

	if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
		Chara.wx < game()->map()->wDispLeft() ||
		Chara.wx > game()->map()->wDispRight()) {
		Chara.hp = 0;
	}
}
