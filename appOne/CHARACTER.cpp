#include"graphic.h"
#include"window.h"
#include"input.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"CHARACTER.h"

CHARACTER::CHARACTER(GAME* game) : GAME_OBJECT(game)
{
}

void CHARACTER::create()
{
}

void CHARACTER::init()
{
	Chara.hp = 0;
}

void CHARACTER::appear(float wx, float wy, float vx, float vy)
{
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.hp = 1;
}

void CHARACTER::update()
{
	float px = Chara.wx - game()->map()->wx();
	if (px < -game()->map()->chipSize()) {
		Chara.hp = 0;
	}
}

void CHARACTER::draw()
{
	imageColor(Chara.color);
	float px = Chara.wx - game()->map()->wx();
	float py = Chara.wy - game()->map()->wy();
	if (Chara.anims) {
		Chara.anims->anim(Chara.animId)->draw(&Chara.animData,
			px, py, Chara.angle, Chara.scale);
	}
	else if (Chara.anim) {
		Chara.anim->draw(&Chara.animData,
			px, py, Chara.angle, Chara.scale);
	}
	else {
		image(Chara.img, px, py, Chara.angle, Chara.scale);
	}
}

void CHARACTER::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
	}
}

void CHARACTER::buff(char Id)
{
	//スポーツドリンク
	if (Id == 'g') {
		Chara.speed *= game()->container()->data().sports_drink.buffPower;
	}
	//トビウオ
	else if (Id == 'h') {
		Chara.initVecUp *= game()->container()->data().flying_fish.buffPower;
	}
}

void CHARACTER::debuff(char Id)
{
	//ヒツジ
	//インターバルで管理(3秒)
	if (Id == 'c') {
		float elapsedTime = 0;
		Chara.speed = game()->container()->data().playerChara.speed;
		Chara.initVecUp = game()->container()->data().playerChara.initVecUp;

		Chara.speed *= game()->container()->data().sheep.debuffPower;;
		elapsedTime += delta;
		if (elapsedTime >= game()->container()->data().sheep.duration) {
			Chara.speed = game()->container()->data().playerChara.speed;
		}
	}
	//猫
	//レバガチャで管理(30回)
	else if (Id == 'd') {
		Chara.speed = game()->container()->data().playerChara.speed;
		Chara.initVecUp = game()->container()->data().playerChara.initVecUp;

		Chara.speed *= game()->container()->data().cat.debuffPower;
		Chara.initVecUp *= game()->container()->data().cat.debuffPower;
		int count = game()->container()->data().cat.keyCount;
		while (count <= game()->container()->data().cat.buttonMash) {
			if (isTrigger(KEY_A) || isTrigger(KEY_D) ||
				isTrigger(KEY_LEFT) || isTrigger(KEY_RIGHT)) {
				count++;
			}
		}
		Chara.speed = game()->container()->data().playerChara.speed;
	}
}
