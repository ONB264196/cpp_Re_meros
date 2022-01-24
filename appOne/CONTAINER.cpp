#include"graphic.h"
#include "CONTAINER.h"
#include"ANIMS.h"

CONTAINER::~CONTAINER()
{
	//単体アニメーションの開放
	//複数アニメーションの開放
	delete Data.playerChara.anims;
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
	Data.player.initVecUp = -16.0f;
	Data.player.initVecDown = 3.0f;
	Data.player.gravity = 48;
	Data.player.bulletOffsetX = 20.0f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

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
	Data.boss.rightAnimId = 0;
	Data.boss.leftAnimId = 1;
	Data.boss.jumpFlag = 0;
	Data.boss.initVecUp = -16.0f;
	Data.boss.initVecDown = 3.0f;
	Data.boss.gravity = 48;
	Data.boss.bulletOffsetX = 55.0f;
	Data.boss.damageColor = COLOR(255, 0, 0, 25);
	Data.boss.normalColor = COLOR(255, 255, 255);

	Data.bossBulletChara.charaId = MAP::BOSS_BULLET_ID;
	Data.bossBulletChara.groupId = 1;
	Data.bossBulletChara.hp = 1;
	Data.bossBulletChara.speed = 4.7f * 60;
	Data.bossBulletChara.offsetLeft =
	Data.bossBulletChara.offsetTop =
	Data.bossBulletChara.offsetRight =
	Data.bossBulletChara.offsetBottom =



	Data.sheepChara.charaId = MAP::SHEEP_ID;
	Data.sheepChara.hp = 1;
	Data.sheepChara.groupId = 3;
	Data.sheepChara.offsetLeft =
	Data.sheepChara.offsetRight =
	Data.sheepChara.offsetTop =
	Data.sheepChara.offsetBottom =
	
	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 3;
	Data.catChara.offsetLeft =
	Data.catChara.offsetRight =
	Data.catChara.offsetTop =
	Data.catChara.offsetBottom =

	Data.sports_drinkChara.charaId = MAP::SPORTS_DRINK_ID;
	Data.sports_drinkChara.hp = 1;
	Data.sports_drinkChara.groupId = 2;
	Data.sports_drinkChara.offsetLeft =
	Data.sports_drinkChara.offsetRight =
	Data.sports_drinkChara.offsetTop =
	Data.sports_drinkChara.offsetBottom =

	Data.flying_fishChara.charaId = MAP::FLYING_FISH_ID;
	Data.flying_fishChara.hp = 1;
	Data.flying_fishChara.groupId = 2;
	Data.flying_fishChara.offsetLeft =
	Data.flying_fishChara.offsetRight =
	Data.flying_fishChara.offsetTop =
	Data.flying_fishChara.offsetBottom =

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 5;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossBullets = 1;
	Data.charaMng.numSheeps = 4;
	Data.charaMng.numCats = 4;
	Data.charaMng.numSportsDrinks = 2;
	Data.charaMng.numFlyingFish = 2;
}

void CONTAINER::LoadGraphics()
{
	Data.stage.backImg = loadImage("assets\\back_wide.png");
	Data.stage.stageClearImg = loadImage("assets\\StageClear.png");
	Data.stage.gameOverImg = loadImage("assets\\GameOver.png");

	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.goalImg = loadImage("assets\\goal.png");

	Data.playerBulletChara.img = loadImage("assets\\playerBullet.png");


	//ANIMS
	Data.playerChara.anims = new ANIMS("assets\\player");
	Data.playerChara.animData.interval = 0.1f;

	Data.bossChara.anims = new ANIMS("assets\\boss");
	Data.bossChara.animData.interval = 0.1f;


	//ANIM
	//Data.batChara.anim = new ANIM("assets\\bat\\0");
	//Data.batChara.animData.interval = 0.1f;
	
	//Data.explosionChara.anim = new ANIM("assets\\explosion\\0");
	//Data.explosionChara.anim->noLoop();
	//Data.explosionChara.animData.interval = 0.032f;
}
