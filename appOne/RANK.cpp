#include"window.h"
#include"input.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"CHARACTER.h"
#include "RANK.h"

void RANK::dispRank(char r)
{
	rectMode(CENTER);
	float w = width / 2;
	float h = height / 2;
	if (r == 'S') image(game()->container()->data().rank.SImg, w, h);
	else if (r == 'A') image(game()->container()->data().rank.AImg, w, h);
	else if (r == 'B') image(game()->container()->data().rank.BImg, w, h);
	else image(game()->container()->data().rank.CImg, w, h);
}
