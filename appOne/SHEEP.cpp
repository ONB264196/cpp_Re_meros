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
	//����
	if (Sheep.fallFlag) {
		Chara.vy += Sheep.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}
	//���݈ʒu�̕ۑ�
	Sheep.curWx = Chara.wx;
	//���E�ړ�
	Chara.wx += Chara.vx * (Chara.speed * delta);
}

void SHEEP::CollisionWithMap()
{
	MAP* map = game()->map();
	//�ǂŔ��]
	if (Sheep.fallFlag == 0) {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
			map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.animId = 1 - Chara.animId;
			Chara.vx = -Chara.vx;
			Chara.wx = Sheep.curWx;
		}
	}
	//�ڒn�`�F�b�N
	if (map->collisionCharaBottom(Sheep.curWx, Chara.wy)) {
		Sheep.fallFlag = 0;
		Chara.vy = 0;
		Chara.wx = (int)Chara.wx / map->chipSize() * (float)map->chipSize();
	}
	//���Ƃ�
	else {
		Sheep.fallFlag = 1;
	}
	//��ʊO
	if (Chara.wx < map->wDispLeft()) {
		Chara.hp = 0;
	}
}
