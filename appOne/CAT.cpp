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
	Move();
	CollisionWithMap();
}

void CAT::Move()
{
	//落下
	if (Cat.fallFlag) {
		Chara.vy += Cat.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
	//現在位置の保存
	Cat.curWx = Chara.wx;
	//左右移動
	Chara.wx += Chara.vx * (Chara.speed * delta);
}

void CAT::CollisionWithMap()
{
	MAP* map = game()->map();
	//壁で反転
	if (Cat.fallFlag == 0) {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
			map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.animId = 1 - Chara.animId;
				Chara.vx = -Chara.vx;
				Chara.wx = Cat.curWx;
		}
	}
}
