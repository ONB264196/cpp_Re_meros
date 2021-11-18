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
	Move();
	CollisionWithMap();
}

void SHEEP::Move()
{
	//落下
	if (Sheep.fallFlag) {
		Chara.vy += Sheep.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
	//現在位置の保存
	Sheep.curWx = Chara.wx;
	//左右移動
	Chara.wx += Chara.vx * (Chara.speed * delta);
}

void SHEEP::CollisionWithMap()
{
	MAP* map = game()->map();
	//壁で反転
	if (Sheep.fallFlag == 0) {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
			map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.animId = 1 - Chara.animId;
			Chara.vx = -Chara.vx;
			Chara.wx = Sheep.curWx;
		}
	}
	//接地チェック
	if (map->collisionCharaBottom(Sheep.curWx, Chara.wy)) {
		Sheep.fallFlag = 0;
		Chara.vy = 0;
		Chara.wx = (int)Chara.wx / map->chipSize() * (float)map->chipSize();
	}
	//落とす
	else {
		Sheep.fallFlag = 1;
	}
	//画面外
	if (Chara.wx < map->wDispLeft()) {
		Chara.hp = 0;
	}
}
