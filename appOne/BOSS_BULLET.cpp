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
	Chara.vy = rand() % 4 - (float)12;
}

void BOSS_BULLET::update()
{
	
	Chara.wx += Chara.vx * (Chara.speed * delta);
	Chara.vy += game()->container()->data().bossBullet.gravity * delta;
	Chara.wy += Chara.vy * 60 * delta;

	if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
		Chara.wx < game()->map()->wDispLeft() ||
		Chara.wx > game()->map()->wDispRight()) {
		Chara.hp = 0;
	}
}
