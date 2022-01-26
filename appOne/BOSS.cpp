#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BOSS.h"

void BOSS::create()
{
	Chara = game()->container()->data().bossChara;
	Boss = game()->container()->data().boss;	
}

void BOSS::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().bossChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.vx = Boss.initVecX;
	Chara.vy = Boss.initVecY;
	Chara.animId = Boss.leftAnimId;
	Boss.fallFlag = 0;
}

void BOSS::update()
{
	Move();
	CollisionWithMap();
	ChangeColor();
}

void BOSS::Move()
{
	//落下
	if (Boss.fallFlag) {
		Chara.vy += Boss.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
	//現在の位置の保存
	Boss.curWx = Chara.wx;
	//左右移動
	Chara.wx += Chara.vx * (Chara.speed * delta);

}

void BOSS::CollisionWithMap()
{
	MAP* map = game()->map();
	//壁(マップチップ)で反転
	if (Boss.fallFlag == 0) {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
			map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.animId = 1 - Chara.animId;
			Chara.vx = -Chara.vx;
			Chara.wx = Boss.curWx;
		}
	}
	//接地チェック
	if (map->collisionCharaBottom(Boss.curWx, Chara.wy)) {
		Boss.fallFlag = 0;
		Chara.vy = 0;
		Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
	}
	else {
		//落とす
		Boss.fallFlag = 1;
	}

}

void BOSS::ChangeColor()
{
	if (Boss.damageTime > 0) {
		Boss.damageTime -= delta;
		Chara.color = Boss.damageColor;
	}
	else {
		Chara.color = Boss.normalColor;
	}

}

void BOSS::damage()
{
	if (Chara.hp > 0) {
		Boss.damageTime = Boss.damageInterval;
		Chara.hp--;
		if (Chara.hp == 0) {
			
		}
	}

}