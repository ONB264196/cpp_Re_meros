#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"CLEAR.h"
#include"FADE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"RANK.h"
#include"PLAYER_BULLET.h"
#include"SHEEP.h"
#include"CAT.h"
#include"BOSS.h"
#include "BOSS_BULLET.h"
#include"SPORTS_DRINK.h"
#include"FLYING_FISH.h"
#include"CHARACTER_MANAGER.h"
#include"TIME.h"

class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		CLEAR::DATA clear;
		FADE::DATA fade;
		MAP::DATA map;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;
		RANK::DATA rank;
		CHARACTER::DATA playerBulletChara;
		PLAYER_BULLET::DATA playerBullet;
		CHARACTER::DATA sheepChara;
		SHEEP::DATA sheep;
		CHARACTER::DATA catChara;
		CAT::DATA cat;
		CHARACTER::DATA bossChara;
		BOSS::DATA boss;
		CHARACTER::DATA bossBulletChara;
		BOSS_BULLET::DATA bossBullet;
		SPORTS_DRINK::DATA sports_drink;
		CHARACTER::DATA sports_drinkChara;
		FLYING_FISH::DATA flying_fish;
		CHARACTER::DATA flying_fishChara;
		CHARACTER_MANAGER::DATA charaMng;
		CHARACTER::DATA chara;
	};
	DATA Data;
	void CreateData();
	void LoadGraphics();
	void LoadSound();
public:
	~CONTAINER();
	void load();
	const DATA& data() { return Data; }
};
