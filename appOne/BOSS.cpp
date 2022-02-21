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
	Launch();
	ChangeColor();
}

void BOSS::Launch()
{
	Boss.TelapsedTime += delta;
	if (Boss.TelapsedTime >= Boss.Tinterval) {
		Boss.TelapsedTime -= Boss.Tinterval;
		++Boss.triggerCnt %= Boss.triggerInterval;
		if (Boss.triggerCnt == Boss.trigger1st ||
			Boss.triggerCnt == Boss.trigger2nd ||
			Boss.triggerCnt == Boss.trigger3rd ||
			Boss.triggerCnt == Boss.trigger4th) {
			game()->characterManager()->appear(Boss.bulletCharaId,
				Chara.wx - Boss.bulletOffsetX, Chara.wy, -1, 0);
		}
	}
}

 void BOSS::Algorithm()
{
	 srand((unsigned)time(NULL));
	 if (rand() % 2 == 0) {
		 Chara.animId = 1 - Chara.animId;
		 Chara.vx = -Chara.vx;
	 }
	 else {
		 Chara.vy = Chara.initVecUp;
	 }
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
	//インターバルで左右移動
	Boss.MelapsedTime += delta;
	if (Boss.MelapsedTime >= Boss.Minterval) {
		Boss.MelapsedTime -= Boss.Minterval;
		++Boss.moveCnt %= Boss.moveInterval;
		if (Boss.moveCnt == Boss.move1st ||
			Boss.moveCnt == Boss.move2nd ||
			Boss.moveCnt == Boss.move3rd ||
			Boss.moveCnt == Boss.move4th ||
			Boss.moveCnt == Boss.move5th ||
			Boss.moveCnt == Boss.move6th) {
			Algorithm();
		}
	}
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