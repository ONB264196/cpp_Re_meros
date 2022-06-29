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
#include <charconv>

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
	Stage.tSize = game()->container()->data().stage.tSize;
	Stage.timePx = game()->container()->data().stage.timePx;
	Stage.timePy = game()->container()->data().stage.timePy;
	TR = game()->container()->data().player.remain;
}

void STAGE::update()
{
	game()->characterManager()->update();
	game()->map()->update();
	if(TR >= 0)TR -= delta;
}

void STAGE::draw()
{
	BackGround();
	game()->map()->draw();
	game()->characterManager()->draw();
	disptime(TR);

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

void STAGE::disptime(float t)
{
	textSize(Stage.tSize);
	if (t >= 10.0f) fill(0);
	else fill(255, 50, 50);
	text((int)t , Stage.timePx, Stage.timePy);
}
