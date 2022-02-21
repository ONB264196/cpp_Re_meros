#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include"FADE.h"
#include "TITLE.h"
#include "CLEAR.h"

void CLEAR::init()
{
	game()->fade()->inTrigger();
}

void CLEAR::draw()
{
	clear();
	rectMode(CORNER);
	image(game()->container()->data().clear.backImg, 0, 0);

	if (game()->container()->data().player.rank == 'S') {
		image(game()->container()->data().clear.SImg, 0, 0);
	}
	else if (game()->container()->data().player.rank == 'A') {
		image(game()->container()->data().clear.AImg, 0, 0);
	}
	else if (game()->container()->data().player.rank == 'B') {
		image(game()->container()->data().clear.BImg, 0, 0);
	}
	else {
		image(game()->container()->data().clear.CImg, 0, 0);
	}
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
