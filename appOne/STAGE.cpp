#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include"STAGE.h"
#include"CLEAR.h"

void STAGE::create()
{
	Stage = game()->container()->data().stage;
}

void STAGE::init()
{
	Stage.nextToRankTime = game()->container()->data().stage.nextToRankTime;
	game()->map()->init();
	game()->characterManager()->init();
	game()->fade()->inTrigger();
	Stage.remain = game()->container()->data().stage.remain;
	Stage.tSize = game()->container()->data().stage.tSize;
	Stage.timePx = game()->container()->data().stage.timePx;
	Stage.timePy = game()->container()->data().stage.timePy;
}

void STAGE::update()
{
	game()->characterManager()->update();
	game()->map()->update();
	if (!game()->player()->survived()) {
		Stage.remain -= delta;
	}
	if (Stage.remain == 0) {
		game()->player()->damage();
	}
}

void STAGE::draw()
{
	BackGround();
	game()->map()->draw();

	//Žc‚èŽžŠÔ
	textSize(Stage.tSize);
	if (Stage.remain >= 10.0f) fill(0);
	else fill(255, 50, 50);
	text((int)Stage.remain, Stage.timePx, Stage.timePy);
	game()->characterManager()->draw();

	if (game()->player()->died()) {
		Logo(Stage.gameOverImg, Stage.stageClearColor);
	}
	else if (game()->player()->survived()) {
		Logo(Stage.stageClearImg, Stage.stageClearColor);
	}
	game()->fade()->draw();
}

void STAGE::BackGround()
{
	clear();
	rectMode(CORNER);
	imageColor(Stage.backColor);
	image(Stage.backImg, 0, 0);
}

void STAGE::Logo(int img, const COLOR& color)
{
	imageColor(color);
	image(img, Stage.logoPx, Stage.logoPy);
	Stage.nextToRankTime -= delta;
}

void STAGE::nextScene()
{
	if (Stage.nextToRankTime <= 0) game()->fade()->outTrigger();
	if (game()->fade()->outEndFlag()) game()->setCurScene(game()->clear());
}
