#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include"FADE.h"
#include "TITLE.h"

void TITLE::init()
{
	game()->fade()->inTrigger();
}

void TITLE::draw()
{
	clear();
	rectMode(CORNER);
	imageColor(240);
	image(game()->container()->data().stage.backImg, 0, 0);
	float size;
	
	size = 70;
	textSize(size);
	fill(15, 5, 5);
	text("Re：走れメロス", width / 2 - size * 3.5f + 2, height / 2 - size * 2 + 1);
	fill(31, 30, 51);
	size = 35;
	textSize(size);
	text("左右移動・・・'A' ⇔ 'D'", size * 9 + 2, height - size * 5 + 1);
	text("ジャンプ・・・'W'", size * 9 + 2, height - size * 3 + 1);
	text(" 投げる ・・・'J'", size * 9 + 2, height - size * 1 + 1);
	size = 50;
	textSize(size);
	text(" SPACE でスタート", width / 2 - size * 4.25f + 2, height / 2 + 1);

	fill(248, 30, 51);
	size = 70;
	textSize(size);
	text("Re：走れメロス", width / 2 - size * 3.5f, height / 2 - size * 2);
	fill(220);
	size = 35;
	textSize(size);
	text("左右移動・・・'A' ⇔ 'D'", size * 9, height - size * 5);
	text("ジャンプ・・・'W'", size * 9, height - size * 3);
	text(" 投げる ・・・'J'", size * 9, height - size * 1);
	size = 50;
	textSize(size);
	text(" SPACE でスタート", width / 2 - size * 4.25f, height / 2);

	fill(31, 30, 51, 200);
	size = 20;
	textSize(size);
	text("SE : 魔王魂・効果音ラボ", width - size * 12, height - size / 2);


	game()->fade()->draw();
}

void TITLE::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->setCurScene(game()->stage());
	}
}