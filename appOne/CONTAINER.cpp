#include"graphic.h"
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
	Data.stage.time = 120;
	Data.stage.backColor = COLOR(255, 255, 255, 255);
	Data.stage.gameOverColor = COLOR(255, 0, 0);
	Data.stage.stageClearColor = COLOR(255, 255, 0);
	Data.stage.logoPx = (width - 800) / 2;
	Data.stage.logoPy = 220;
	Data.stage.backToTitleTime = 2;

	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 255 * 2;

	Data.map.fileName = "assets\\map.txt";
	Data.map.chipSize = 50;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;
	Data.playerChara.speed = 3.4f * 60;
	Data.playerChara.offsetLeft = 10.0f;
	Data.playerChara.offsetTop = 1.0f;
	Data.playerChara.offsetRight = 40.0f;
	Data.playerChara.offsetBottom = 49.0f;
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.jumpFlag = 0;
	Data.player.initVecDown = 3.0f;
	Data.player.gravity = 48.0f;
	Data.player.bulletOffsetX = 20.0f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;
	Data.player.damageCount = 0;
	Data.player.debuffCount = 0;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 0; 
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 23.5f * 60;
	Data.playerBulletChara.offsetLeft = 20.0f;
	Data.playerBulletChara.offsetTop = 20.0f;
	Data.playerBulletChara.offsetRight = 30.0f;
	Data.playerBulletChara.offsetBottom = 30.0f;

	Data.bossChara.charaId = MAP::BOSS_ID;
	Data.bossChara.hp = 30;
	Data.bossChara.groupId = 1;
	Data.bossChara.speed = 23.5f * 60;
	Data.bossChara.offsetLeft = 50.0f;
	Data.bossChara.offsetTop = 50.0f;
	Data.bossChara.offsetRight = 50.0f;
	Data.bossChara.offsetBottom = 50.0f;
	Data.boss.TelapsedTime = 0;
	Data.boss.Tinterval = 0.04f;
	Data.boss.triggerCnt = 5;
	Data.boss.triggerInterval = 25;
	Data.boss.trigger1st = 5;
	Data.boss.trigger2nd = 10;
	Data.boss.trigger3rd = 15;
	Data.boss.trigger4th = 20;
	Data.boss.bulletCharaId = MAP::BOSS_BULLET_ID;
	Data.boss.damageTime = 0;
	Data.boss.damageInterval = 5 * 0.025f;
	Data.boss.bulletOffsetX = 20.0f;
	Data.boss.rightAnimId = 0;
	Data.boss.leftAnimId = 1;
	Data.boss.jumpFlag = 0;
	
	Data.boss.MelapsedTime = 0;
	Data.boss.Minterval = 0.0005f;
	Data.boss.moveCnt = 160;
	Data.boss.moveInterval = 2000;
	Data.boss.move1st = 160;
	Data.boss.move2nd = 480;
	Data.boss.move3rd = 640;
	Data.boss.move4th = 1020;
	Data.boss.move5th = 1650;
	Data.boss.move6th = 1930;
	Data.boss.initVecUp = -16.0f;
	Data.boss.initVecDown = 3.0f;
	Data.boss.gravity = 48.0f;
	Data.boss.bulletOffsetX = 55.0f;
	Data.boss.damageColor = COLOR(255, 0, 0, 25);
	Data.boss.normalColor = COLOR(255, 255, 255);

	Data.bossBulletChara.charaId = MAP::BOSS_BULLET_ID;
	Data.bossBulletChara.groupId = 1;
	Data.bossBulletChara.hp = 1;
	Data.bossBulletChara.speed = 4.7f * 60;
	Data.bossBulletChara.offsetLeft = 50;
	Data.bossBulletChara.offsetTop = 50;
	Data.bossBulletChara.offsetRight = 50;
	Data.bossBulletChara.offsetBottom = 50;
	Data.bossBullet.gravity = 48.0f;

	Data.sheepChara.charaId = MAP::SHEEP_ID;
	Data.sheepChara.hp = 1;
	Data.sheepChara.groupId = 3;
	Data.sheepChara.offsetLeft = 50;
	Data.sheepChara.offsetRight = 50;
	Data.sheepChara.offsetTop = 50;
	Data.sheepChara.offsetBottom = 50;
	Data.sheep.debuffPower = 0.5f;
	Data.sheep.interval = 3.0f;
	
	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 3;
	Data.catChara.offsetLeft = 50;
	Data.catChara.offsetRight = 50;
	Data.catChara.offsetTop = 50;
	Data.catChara.offsetBottom = 50;
	Data.cat.debuffPower = 0;
	Data.cat.keyCount = 0;
	Data.cat.buttonMash = 30;

	Data.sports_drinkChara.charaId = MAP::SPORTS_DRINK_ID;
	Data.sports_drinkChara.hp = 1;
	Data.sports_drinkChara.groupId = 2;
	Data.sports_drinkChara.offsetLeft = 50; 
	Data.sports_drinkChara.offsetRight = 50;
	Data.sports_drinkChara.offsetTop = 50;
	Data.sports_drinkChara.offsetBottom = 50;
	Data.sports_drink.buffPower = 1.5f;

	Data.flying_fishChara.charaId = MAP::FLYING_FISH_ID;
	Data.flying_fishChara.hp = 1;
	Data.flying_fishChara.groupId = 2;
	Data.flying_fishChara.offsetLeft = 50;
	Data.flying_fishChara.offsetRight = 50;
	Data.flying_fishChara.offsetTop = 50;
	Data.flying_fishChara.offsetBottom = 50;
	Data.flying_fish.buffPower = 1.3f;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 5;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossBullets = 50;
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
	Data.clear.SImg = loadImage("assets\\clear_S.png");
	Data.clear.AImg = loadImage("assets\\clear_A.png");
	Data.clear.BImg = loadImage("assets\\clear_B.png");
	Data.clear.CImg = loadImage("assets\\clear_C.png");
	

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
