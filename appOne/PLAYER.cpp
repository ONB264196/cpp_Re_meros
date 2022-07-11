#include"window.h"
#include"input.h"
#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PLAYER.h"
#include"CHARACTER.h"
#include <sound.h>


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
	Chara.speed = game()->container()->data().playerChara.speed;
	Chara.initVecUp = game()->container()->data().playerChara.initVecUp;
	Chara.animId = Player.rightAnimId;
	Chara.debufCount = 0;
	Player.jumpFlag = 0;
	game()->player()->State = STATE::STRUGGLING;
	
	TR = game()->container()->data().player.remain;
}

void PLAYER::update()
{
	evaluation();
	Launch();
	Move();
	CollisionWithMap();
	CheckState();
	//残り時間
	if (!game()->player()->survived() && TR > 0) TR -= delta;
	//タイムアップ
	if (TR <= 0) {
		Chara.hp = 0;
		game()->player()->State = STATE::DIED;
		game()->player()->r = 'C';
	}
	
}

void PLAYER::Launch()
{
	if (isTrigger(KEY_J) || isTrigger(KEY_S) || isTrigger(KEY_DOWN)) {
		float vx = 1.0f;
		if (Chara.animId == Player.leftAnimId) vx = -1.0f;
		float wx = Chara.wx + Player.bulletOffsetX * vx;
		float wy = Chara.wy;
		game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx);
		playSound(Player.throwSnd);
	}
}

void PLAYER::Move()
{
	//ジャンプ
	if (Player.jumpFlag == 0) {
		if (isTrigger(KEY_UP) || isTrigger(KEY_K) || isTrigger(KEY_W)) {
			Chara.vy = Chara.initVecUp;
			Player.jumpFlag = 1;
			playSound(Player.jumpSnd);
		}
	}
	if (Player.jumpFlag == 1) {
		Chara.vy += Player.gravity * delta;
		Chara.wy += Chara.vy * 60 * delta;
	}

	//左右移動
	Chara.vx = 0.0f;
	if (isPress(KEY_A) || isPress(KEY_LEFT)) {
		Chara.vx = -Chara.speed * delta;
		Chara.animId = Player.leftAnimId;
	}
	if (isPress(KEY_D) || isPress(KEY_RIGHT)) {
		Chara.vx = Chara.speed * delta;
		Chara.animId = Player.rightAnimId;
	}
	//移動前の位置を保存
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
	// ※1　キャラ右側
	if (Chara.animId == Player.rightAnimId) {
		if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.wx = Player.curWx;
		}
	}
	// ※1　キャラ左側
	else {
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) || Chara.wx < map->wx()) {
			Chara.wx = Player.curWx;
		}
	}
	// ※1　キャラ上側
	if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
		Chara.vy = Player.initVecDown;
	}
	// ※1　キャラ下側
	if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
		if (Player.jumpFlag == 1) playSound(Player.landingSnd);
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
	//落下
	if (Chara.wy > height + game()->map()->chipSize()) {
		game()->player()->State = STATE::FALL;
		game()->player()->r = 'C';
		Chara.hp = 0;
		playSound(Player.fallSnd);
		return;
	}
}

void PLAYER::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		if (Chara.hp == 0) {
			game()->player()->State = STATE::DIED;
			Chara.vy = Chara.initVecUp;
			playSound(Player.diedSnd);
			
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
	if (game()->player()->State == STATE::DIED) {
		Chara.vy += Player.gravity * delta;
		Chara.wy += Chara.vy += 60 * delta;
		draw();
		return true;
	}
	else if (game()->player()->State == STATE::FALL) {
		return true;
	}
	return false;
}

bool PLAYER::survived()
{
	return game()->player()->State == STATE::SURVIVED;
}

float PLAYER::overCenterVx()
{
	float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
	float overCenterVx = Chara.wx - centerWx;
	if (overCenterVx < 0 || Chara.hp == 0) overCenterVx = 0;
	return overCenterVx;
}

