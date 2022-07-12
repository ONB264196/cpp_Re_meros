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
#include<sound.h>

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
	TR = game()->container()->data().player.remain;
	playLoopSound(Stage.BGM);
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
	if (Stage.nextToRankTime <= 0) {
		game()->fade()->outTrigger();
	}
	if (game()->fade()->outEndFlag()) {
		game()->setCurScene(game()->clear());
		stopSound(Stage.BGM);
		if (game()->player()->r == 'S') playSound(Stage.applauseSnd);
	}
}

void STAGE::disptime(float t)
{
	int d1 = (int)t % 10;
	int d10 = ((int)t / 10) % 10;

	if (d10) {
		imageColor(0);
		if (d10 == 9) image(Stage.T9Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 8) image(Stage.T8Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 7) image(Stage.T7Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 6) image(Stage.T6Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 5) image(Stage.T5Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 4) image(Stage.T4Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 3) image(Stage.T3Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 2) image(Stage.T2Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 1) image(Stage.T1Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d10 == 0) image(Stage.T0Img, Stage.timePx - Stage.timeOfsX, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 9) image(Stage.T9Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 8) image(Stage.T8Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 7) image(Stage.T7Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 6) image(Stage.T6Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 5) image(Stage.T5Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 4) image(Stage.T4Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 3) image(Stage.T3Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 2) image(Stage.T2Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 1) image(Stage.T1Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
		if (d1 == 0) image(Stage.T0Img, Stage.timePx, Stage.timePy, 0, Stage.tImgSize);
	}
	else {
		imageColor(255, 60, 60);
		if (d1 == 9) image(Stage.T9Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 8) image(Stage.T8Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 7) image(Stage.T7Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 6) image(Stage.T6Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 5) image(Stage.T5Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 4) image(Stage.T4Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 3) image(Stage.T3Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 2) image(Stage.T2Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 1) image(Stage.T1Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
		if (d1 == 0) image(Stage.T0Img, Stage.lmtTimePx, Stage.lmtTimePy, 0, Stage.lmtTImgSize);
	}

}