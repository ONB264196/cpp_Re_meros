#include"graphic.h"
#include"sound.h"
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
}

void CONTAINER::CreateData()
{
	Data.stage.tSize = 30;
	Data.stage.timePx = 1000.0f;
	Data.stage.timePy = 45.0f;
	Data.stage.remain = 40.0f;
	Data.stage.backColor = COLOR(255, 255, 255, 255);
	Data.stage.gameOverColor = COLOR(255, 0, 0);
	Data.stage.stageClearColor = COLOR(255, 255, 0);
	Data.stage.logoPx = (width - 800) / 2;
	Data.stage.logoPy = 220;
	Data.stage.nextToRankTime = 2.0f;

	Data.clear.backToTitleTime = 6.0f;

	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;

	Data.map.fileName = "assets\\map.txt";
	Data.map.chipSize = 50;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 500;
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
	Data.bossChara.hp = 2;
	Data.bossChara.groupId = 1;
	Data.bossChara.speed = 1.2f * 120;
	Data.bossChara.initVecUp = -16.0f;
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
	Data.flying_fish.buffPower = 1.0247f;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 3;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossBullets = 4;
	Data.charaMng.numSheeps = 1;
	Data.charaMng.numCats = 1;
	Data.charaMng.numSportsDrinks = 2;
	Data.charaMng.numFlyingFish = 2;
}

void CONTAINER::LoadGraphics()
{
	Data.stage.backImg = loadImage("assets\\back_wide.png");
	Data.stage.stageClearImg = loadImage("assets\\StageClear.png");
	Data.stage.gameOverImg = loadImage("assets\\GameOver.png");
	Data.clear.backImg = loadImage("assets\\clear_back.png");
	
	Data.rank.SImg = loadImage("assets\\clear_S.png");
	Data.rank.AImg = loadImage("assets\\clear_A.png");
	Data.rank.BImg = loadImage("assets\\clear_B.png");
	Data.rank.CImg = loadImage("assets\\clear_C.png");	

	Data.map.blockImg = loadImage("assets\\block.png");

	Data.playerBulletChara.img = loadImage("assets\\playerBullet.png");
	Data.bossBulletChara.img = loadImage("assets\\bossBullet.png");

	//ANIMS
	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.bossChara.anims = new ANIMS("assets\\boss");
	Data.bossChara.animData.interval = 0.1f;


	//ANIM
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
	//wav・awm形式のみ再生可能
	//int snd = loadSound("ファイル名");
	//playSound(snd);
	//playLoopSound(snd);
	//この他関数はヘッダー参照
}
