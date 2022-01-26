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
	//����
	if (Boss.fallFlag) {
		Chara.vy += Boss.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
	//���݂̈ʒu�̕ۑ�
	Boss.curWx = Chara.wx;
	//���E�ړ�
	Chara.wx += Chara.vx * (Chara.speed * delta);

}

void BOSS::CollisionWithMap()
{
	MAP* map = game()->map();
	//��(�}�b�v�`�b�v)�Ŕ��]
	if (Boss.fallFlag == 0) {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
			map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.animId = 1 - Chara.animId;
			Chara.vx = -Chara.vx;
			Chara.wx = Boss.curWx;
		}
	}
	//�ڒn�`�F�b�N
	if (map->collisionCharaBottom(Boss.curWx, Chara.wy)) {
		Boss.fallFlag = 0;
		Chara.vy = 0;
		Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
	}
	else {
		//���Ƃ�
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