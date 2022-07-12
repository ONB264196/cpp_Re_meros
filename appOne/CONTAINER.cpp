#include"graphic.h"
#include <sound.h>
#include "CONTAINER.h"
#include"ANIMS.h"

CONTAINER::~CONTAINER()
{
	//単体アニメーションの開放
	delete Data.catChara.anim;
	delete Data.sheepChara.anim;
	delete Data.sports_drinkChara.anim;
	delete Data.flying_fishChara.anim;
	//複数アニメーションの開放
	delete Data.playerChara.anims;
	delete Data.bossChara.anim;
}

void CONTAINER::load()
{
	CreateData();
	LoadGraphics();
	LoadSound();
}

void CONTAINER::CreateData()
{
	Data.stage.backColor = COLOR(255, 255, 255, 255);
	Data.stage.gameOverColor = COLOR(255, 0, 0);
	Data.stage.stageClearColor = COLOR(255, 255, 0);
	Data.stage.logoPx = (width - 800) / 2;
	Data.stage.logoPy = 220;
	Data.stage.nextToRankTime = 2.0f;
	Data.stage.tImgSize = 0.05f;
	Data.stage.lmtTImgSize = 0.075f;
	Data.stage.timePx = 1000.0f;
	Data.stage.timeOfsX = 30.0f;
	Data.stage.lmtTimePx = 970.0f;
	Data.stage.timePy = 5.0f;
	Data.stage.lmtTimePy = 5.0f;

	Data.clear.backToTitleTime = 2.0f;

	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;

	Data.map.fileName = "assets\\map\\map0.txt";
	Data.map.fileName1 = "assets\\map\\map1.txt";
	Data.map.fileName2 = "assets\\map\\map2.txt";
	Data.map.fileName3 = "assets\\map\\map3.txt";
	Data.map.chipSize = 50;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 6;
	Data.playerChara.groupId = 0;
	Data.playerChara.speed = 3.4f * 120;
	Data.playerChara.initVecUp = -16.0f;
	Data.playerChara.offsetLeft = 10.0f;
	Data.playerChara.offsetTop = 1.0f;
	Data.playerChara.offsetRight = 40.0f;
	Data.playerChara.offsetBottom = 49.0f;
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.jumpFlag = 0;
	Data.player.initVecDown = 3.0f;
	Data.player.gravity = 36.0f;
	Data.player.bulletOffsetX = 20.0f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;
	Data.player.remain = 50.0f;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 0; 
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 12.5 * 120;
	Data.playerBulletChara.offsetLeft = 10.0f;
	Data.playerBulletChara.offsetTop = 10.0f;
	Data.playerBulletChara.offsetRight = 40.0f;
	Data.playerBulletChara.offsetBottom = 40.0f;
	Data.playerBullet.gravity = 48.0f;

	Data.bossChara.charaId = MAP::BOSS_ID;
	Data.bossChara.hp = 25;
	Data.bossChara.groupId = 1;
	Data.bossChara.speed = 1.2f * 120;
	Data.bossChara.initVecUp = -18.0f;
	Data.bossChara.offsetLeft = 25.0f;
	Data.bossChara.offsetTop = 25.0f;
	Data.bossChara.offsetRight = 25.0f;
	Data.bossChara.offsetBottom = 25.0f;
	Data.boss.TelapsedTime = 0;
	Data.boss.Tinterval = 0.04f;
	Data.boss.triggerCnt = 5;
	Data.boss.triggerInterval = 50;
	Data.boss.trigger1st = 20;
	Data.boss.trigger2nd = 22;
	Data.boss.trigger3rd = 24;
	Data.boss.trigger4th = 26;
	Data.boss.bulletCharaId = MAP::BOSS_BULLET_ID;
	Data.boss.damageTime = 0;
	Data.boss.damageInterval = 5 * 0.025f;
	Data.boss.bulletOffsetX = 20.0f;
	Data.boss.rightAnimId = 0;
	Data.boss.leftAnimId = 1;
	Data.boss.jumpFlag = 0;
	
	//ボスの移動
	Data.boss.MelapsedTime = 0;
	Data.boss.Minterval = 0.0005f;
	Data.boss.moveCnt = 160;
	Data.boss.moveInterval = 1000;
	Data.boss.move1st = 80;
	Data.boss.move2nd = 240;
	Data.boss.move3rd = 320;
	Data.boss.move4th = 510;
	Data.boss.move5th = 825;
	Data.boss.move6th = 965;
	Data.boss.initVecUp = -16.0f;
	Data.boss.initVecDown = 3.0f;
	Data.boss.gravity = 48.0f;
	Data.boss.bulletOffsetX = 55.0f;
	Data.boss.damageColor = COLOR(255, 0, 0, 25);
	Data.boss.normalColor = COLOR(255, 255, 255);

	Data.bossBulletChara.charaId = MAP::BOSS_BULLET_ID;
	Data.bossBulletChara.groupId = 1;
	Data.bossBulletChara.hp = 1;
	Data.bossBulletChara.speed = 7.75 * 120;
	Data.bossBulletChara.offsetLeft = 25.0f;
	Data.bossBulletChara.offsetTop = 25.0f;
	Data.bossBulletChara.offsetRight = 25.0f;
	Data.bossBulletChara.offsetBottom = 25.0f;
	Data.bossBullet.gravity = 48.0f;

	Data.sheepChara.charaId = MAP::SHEEP_ID;
	Data.sheepChara.hp = 1;
	Data.sheepChara.groupId = 3;
	Data.sheepChara.offsetLeft = 25.0f;
	Data.sheepChara.offsetRight = 25.0f;
	Data.sheepChara.offsetTop = 25.0f;
	Data.sheepChara.offsetBottom = 25.0f;
	Data.sheep.debuffPower = 0.707f;
	
	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 3;
	Data.catChara.offsetLeft = 25.0f;
	Data.catChara.offsetRight = 25.0f;
	Data.catChara.offsetTop = 25.0f;
	Data.catChara.offsetBottom = 25.0f;
	Data.cat.debuffPower = 0.83f;

	Data.sports_drinkChara.charaId = MAP::SPORTS_DRINK_ID;
	Data.sports_drinkChara.hp = 1;
	Data.sports_drinkChara.groupId = 2;
	Data.sports_drinkChara.offsetLeft = 25.0f;
	Data.sports_drinkChara.offsetRight = 25.0f;
	Data.sports_drinkChara.offsetTop = 25.0f;
	Data.sports_drinkChara.offsetBottom = 25.0f;
	Data.sports_drink.buffPower = 1.2247f;

	Data.flying_fishChara.charaId = MAP::FLYING_FISH_ID;
	Data.flying_fishChara.hp = 1;
	Data.flying_fishChara.groupId = 2;
	Data.flying_fishChara.offsetLeft = 25.0f;
	Data.flying_fishChara.offsetRight = 25.0f;
	Data.flying_fishChara.offsetTop = 25.0f;
	Data.flying_fishChara.offsetBottom = 25.0f;
	Data.flying_fish.buffPower = 1.0488f;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 3;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossBullets = 4;
	Data.charaMng.numSheeps = 2;
	Data.charaMng.numCats = 2;
	Data.charaMng.numSportsDrinks = 3;
	Data.charaMng.numFlyingFish = 3;
}

void CONTAINER::LoadGraphics()
{
	//背景
	Data.stage.backImg = loadImage("assets\\background\\back_wide.png");
	Data.clear.backImg = loadImage("assets\\background\\clear_back.png");
	//ロゴ
	Data.stage.stageClearImg = loadImage("assets\\logo\\StageClear.png");
	Data.stage.gameOverImg = loadImage("assets\\logo\\GameOver.png");
	//時間
	Data.stage.T0Img = loadImage("assets\\TImgs\\T0.png");
	Data.stage.T1Img = loadImage("assets\\TImgs\\T1.png");
	Data.stage.T2Img = loadImage("assets\\TImgs\\T2.png");
	Data.stage.T3Img = loadImage("assets\\TImgs\\T3.png");
	Data.stage.T4Img = loadImage("assets\\TImgs\\T4.png");
	Data.stage.T5Img = loadImage("assets\\TImgs\\T5.png");
	Data.stage.T6Img = loadImage("assets\\TImgs\\T6.png");
	Data.stage.T7Img = loadImage("assets\\TImgs\\T7.png");
	Data.stage.T8Img = loadImage("assets\\TImgs\\T8.png");
	Data.stage.T9Img = loadImage("assets\\TImgs\\T9.png");
	//ランク
	Data.rank.SImg = loadImage("assets\\RANK\\clear_S.png");
	Data.rank.AImg = loadImage("assets\\RANK\\clear_A.png");
	Data.rank.BImg = loadImage("assets\\RANK\\clear_B.png");
	Data.rank.CImg = loadImage("assets\\RANK\\clear_C.png");	
	//ブロック
	Data.map.blockImg = loadImage("assets\\map\\block.png");
	//弾
	Data.playerBulletChara.img = loadImage("assets\\bullet\\playerBullet.png");
	Data.bossBulletChara.img = loadImage("assets\\bullet\\bossBullet.png");

	//プレイヤー・ボス
	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.2f;

	Data.bossChara.anims = new ANIMS("assets\\boss");
	Data.bossChara.animData.interval = 0.2f;

	//バフ・デバフキャラ
	Data.catChara.anim = new ANIM("assets\\cat\\0");
	Data.catChara.animData.interval = 0.1f;

	Data.sheepChara.anim = new ANIM("assets\\sheep\\0");
	Data.sheepChara.animData.interval = 0.1f;

	Data.sports_drinkChara.anim = new ANIM("assets\\sportsDrink\\0");
	Data.sports_drinkChara.animData.interval = 0.1f;

	Data.flying_fishChara.anim = new ANIM("assets\\flyingFish\\0");
	Data.flying_fishChara.animData.interval = 0.1f;
	
}

void CONTAINER::LoadSound()
{
	//SE
	Data.title.startSnd = loadSound("assets\\SE\\startSND.wav");
	Data.stage.applauseSnd = loadSound("assets\\SE\\applauseSND.wav");
	Data.player.jumpSnd = loadSound("assets\\SE\\jumpSND.wav");
	Data.player.throwSnd = loadSound("assets\\SE\\throwSND.wav");
	Data.player.landingSnd = loadSound("assets\\SE\\landingSND.wav");
	Data.player.fallSnd = loadSound("assets\\SE\\fallSND.wav");
	Data.player.diedSnd = loadSound("assets\\Se\\diedSND.wav");
	Data.boss.jumpSnd = loadSound("assets\\SE\\jumpSND.wav");
	Data.boss.throwSnd = loadSound("assets\\SE\\throwSND.wav");
	Data.boss.landingSnd = loadSound("assets\\SE\\landingSND.wav");
	Data.charaMng.catSnd = loadSound("assets\\SE\\catSND.wav");
	Data.charaMng.sheepSnd = loadSound("assets\\SE\\sheepSND.wav");
	Data.charaMng.SDSnd = loadSound("assets\\SE\\sportsDrinkSND.wav");
	Data.charaMng.FFSnd = loadSound("assets\\SE\\flyingFishSND.wav");
	//BGM
	Data.stage.BGM = loadSound("assets\\BGM\\stage.wav");
}
