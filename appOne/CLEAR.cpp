#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include"FADE.h"
#include "CLEAR.h"

void CLEAR::init()
{
	game()->fade()->inTrigger();
}

void CLEAR::draw()
{
	clear();
	rectMode(CORNER);
	image(game()->container()->data().stage.backImg, 0, 0);
	float size;

	size = 50;
	textSize(size);
	fill(0);

}

void CLEAR::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->setCurScene(game()->title());
	}
}
