#include"window.h"
#include"graphic.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include"FADE.h"
#include "TITLE.h"
#include "CLEAR.h"

void CLEAR::init()
{
	game()->fade()->inTrigger();
	Clear.backToTitleTime = game()->container()->data().clear.backToTitleTime;
}

void CLEAR::draw()
{
	clear();
	rectMode(CORNER);
	colorMode(RGB);
	imageColor(255);
	image(game()->container()->data().clear.backImg, 0, 0);

	game()->rank()->dispRank(game()->player()->r);
	Clear.backToTitleTime -= delta;
	game()->fade()->draw();
}

void CLEAR::nextScene()
{
	if (Clear.backToTitleTime <= 0) game()->fade()->outTrigger();
	if (game()->fade()->outEndFlag()) game()->setCurScene(game()->title());
}