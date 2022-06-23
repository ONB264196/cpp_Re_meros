#include"window.h"
#include"input.h"
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PLAYER.h"
#include"CHARACTER.h"


void PLAYER::create()
{
	Chara = game()->container()->data().playerChara;
	Player = game()->container()->data().player;
}

void PLAYER::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().playerChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.animId = Player.rightAnimId;
	Player.jumpFlag = 0;
	State = STATE::STRUGGLING;
}

void PLAYER::update()
{
	Launch();
	Move();
	CollisionWithMap();
	CheckState();
}

void PLAYER::Launch()
{
	if (isTrigger(KEY_J) || isTrigger(KEY_S) || isTrigger(KEY_DOWN)) {
		float vx = 1.0f;
		if (Chara.animId == Player.leftAnimId) vx = -1.0f;
		float wx = Chara.wx + Player.bulletOffsetX * vx;
		float wy = Chara.wy;
		game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx);
	}
}

void PLAYER::Move()
{
	//�W�����v
	if (Player.jumpFlag == 0) {
		if (isTrigger(KEY_UP) || isTrigger(KEY_K) || isTrigger(KEY_W)) {
			Chara.vy = Chara.initVecUp;
			Player.jumpFlag = 1;
		}
	}
	if (Player.jumpFlag == 1) {
		Chara.vy += Player.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}

	//���E�ړ�
	Chara.vx = 0.0f;
	if (isPress(KEY_A) || isPress(KEY_LEFT)) {
		Chara.vx = -Chara.speed * delta;
		Chara.animId = Player.leftAnimId;
	}
	if (isPress(KEY_D) || isPress(KEY_RIGHT)) {
		Chara.vx = Chara.speed * delta;
		Chara.animId = Player.rightAnimId;
	}
	//�ړ��O�̈ʒu��ۑ�
	Player.curWx = Chara.wx;
	if (Chara.vx != 0.0f) {
		Chara.wx += Chara.vx;
	}
	else {
		Chara.animData.imgIdx = 0;
		Chara.animData.elapsedTime = -delta;
	}
}

void PLAYER::CollisionWithMap()
{
	MAP* map = game()->map();
	// ��1�@�L�����E��
	if (Chara.animId == Player.rightAnimId) {
		if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.wx = Player.curWx;
		}
	}
	// ��1�@�L��������
	else {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) || Chara.wx < map->wx()) {
			Chara.wx = Player.curWx;
		}
	}
	// ��1�@�L�����㑤
	if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
		Chara.vy = Player.initVecDown;
	}
	// ��1�@�L��������
	if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
		Player.jumpFlag = 0;
		Chara.vy = 0.0f;
		Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
	}
	else {
		Player.jumpFlag = 1;
	}
}

void PLAYER::CheckState()
{
	//����
	if (Chara.wy > height + game()->map()->chipSize()) {
		game()->player()->State = STATE::FALL;
		Chara.hp = 0;
		game()->stage()->draw();
	}
	//�X�e�[�W�N���A	
	if (State == STATE::SURVIVED) {
		if (1);
		evaluation();
		Chara.hp = 0;
		game()->stage()->draw();
	}
	
}

void PLAYER::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		if (Chara.hp == 0) {
			State = STATE::DIED;
			Chara.vy = Chara.initVecUp;
		}
	}
}

void PLAYER::evaluation()
{	
	if (Chara.hp == game()->container()->data().playerChara.hp && Chara.debufCount == 0) game()->player()->r = 'S';
	else if (Chara.hp == game()->container()->data().playerChara.hp) game()->player()->r = 'A';
	else if ((float)Chara.hp >= game()->container()->data().playerChara.hp / 2.0f) game()->player()->r = 'B';
	else game()->player()->r = 'C';
}

bool PLAYER::died()
{
	if (State == STATE::DIED) {
		Chara.vy += Player.gravity * delta;
		Chara.wy += Chara.vy += 60 * delta;
		draw();
		return true;
	}
	else if (State == STATE::FALL) {
		return true;
	}
	return false;
}

bool PLAYER::survived()
{
	return State == STATE::SURVIVED;
}

float PLAYER::overCenterVx()
{
	float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
	float overCenterVx = Chara.wx - centerWx;
	if (overCenterVx < 0 || Chara.hp == 0) overCenterVx = 0;
	return overCenterVx;
}

