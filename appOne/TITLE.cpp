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
	text("Re：走れメロス", width / 2 - size * 3.5f + 2, height / 2 - size * 2 + 2);
	size = 50;
	textSize(size);
	fill(5, 5, 15);
	text("'SPACE'でスタート", width / 2 - size * 4.25f + 2, height / 2 + 2);
	size = 35;
	textSize(size);
	text("左右移動・・・'A' or '←' ⇔ 'D' or '→'", size * 5 + 1, height - size * 6 + 1);
	text("ジャンプ・・・'W' or 'K' or '↓'", size * 5 + 1, height - size * 4 + 1);
	text(" 投げる ・・・'S' or 'J' or '↑'", size * 5 + 1, height - size * 2 + 1);

	size = 70;
	textSize(size);
	fill(225, 75, 60);
	text("Re：走れメロス", width / 2 - size * 3.5f, height / 2 - size * 2);
	size = 50;
	textSize(size);
	fill(31, 30, 51);
	text("'SPACE'でスタート", width / 2 - size * 4.25f, height / 2);
	size = 35;
	textSize(size);
	text("左右移動・・・'A' or '←' ⇔ 'D' or '→'", size * 5, height - size * 6);
	text("ジャンプ・・・'W' or 'K' or '↓'", size * 5, height - size * 4);
	text(" 投げる ・・・'S' or 'J' or '↑'", size * 5, height - size * 2);

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