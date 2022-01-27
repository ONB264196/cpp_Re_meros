#include"graphic.h"
#include"window.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "RANK.h"

void RANK::create()
{
	Rank = game()->container()->data().rank;
}

virtual void RANK::rank(int hp, int d, int db)
{
	if (hp == hp - d && db == 0) { return 'S'; }
	else if (hp == hp - d) { return 'A'; }
	else if (hp / d <= 2) { return 'B'; }
	else { return 'C'; }
}