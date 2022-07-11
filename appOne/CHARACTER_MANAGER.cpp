#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"CAT.h"
#include"SHEEP.h"
#include"SPORTS_DRINK.h"
#include"FLYING_FISH.h"
#include"BOSS_BULLET.h"
#include"CHARACTER_MANAGER.h"
#include<sound.h>

CHARACTER_MANAGER::CHARACTER_MANAGER(GAME* game) : GAME_OBJECT(game)
{
}

CHARACTER_MANAGER::~CHARACTER_MANAGER()
{
	for (int i = 0; i < Total; i++) {
		delete Characters[i];
	}
	delete[] Characters;
}

void CHARACTER_MANAGER::create()
{
	CharaMng = game()->container()->data().charaMng;

	Total = 0;
	Total += CharaMng.numPlayers;
	Total += CharaMng.numPlayerBullets;
	Total += CharaMng.numBosses;
	Total += CharaMng.numBossBullets;
	Total += CharaMng.numSheeps;
	Total += CharaMng.numCats;
	Total += CharaMng.numSportsDrinks;
	Total += CharaMng.numFlyingFish;

	
	Characters = new CHARACTER * [Total];

	Player = new PLAYER(game());
	int i, j = 0;
	for (i = 0; i < CharaMng.numPlayers; i++) Characters[j++] = Player;
	for (i = 0; i < CharaMng.numPlayerBullets; i++) Characters[j++] = new PLAYER_BULLET(game());
	for (i = 0; i < CharaMng.numBosses; i++) Characters[j++] = new BOSS(game());
	for (i = 0; i < CharaMng.numBossBullets; i++) Characters[j++] = new BOSS_BULLET(game());
	for (i = 0; i < CharaMng.numCats; i++) Characters[j++] = new CAT(game());
	for (i = 0; i < CharaMng.numSheeps; i++) Characters[j++] = new SHEEP(game());
	for (i = 0; i < CharaMng.numSportsDrinks; i++) Characters[j++] = new SPORTS_DRINK(game());
	for (i = 0; i < CharaMng.numFlyingFish; i++) Characters[j++] = new FLYING_FISH(game());

	for (int i = 0; i < Total; i++) {
		Characters[i]->create();
	}
}

void CHARACTER_MANAGER::init()
{
	for (int i = 0; i < Total; i++) {
		Characters[i]->init();
	}
}

void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy)
{
	for (int i = 0; i < Total; i++) {
		if (Characters[i]->charaId() == charaId) {
			if (Characters[i]->hp() <= 0) {
				Characters[i]->appear(wx, wy, vx, vy);
				break;
			}
		}
	}
}

void CHARACTER_MANAGER::update()
{
	float time = 0;
	for (int i = 0; i < Total; i++) {
		if (Characters[i]->hp() > 0) {
			Characters[i]->update();
		}
	}

	for (int i = 0; i < Total - 1; i++) {
		if (Characters[i]->hp() == 0) {
			continue;
		}
		for (int j = i + 1; j < Total; j++) {
			if (Characters[j]->hp() == 0) {
				continue;
			}
			if (Characters[i]->groupId() == Characters[j]->groupId()) {
				continue;
			}
			if (Characters[i]->groupId() == 2 && Characters[j]->groupId() == 3 ||
				Characters[i]->groupId() == 3 && Characters[j]->groupId() == 2) {
				continue;
			}
			if (Characters[i]->charaId() == 'b' && Characters[j]->groupId() == 2 ||
				Characters[i]->groupId() == 2 && Characters[j]->charaId() == 'b') {
				continue;
			}
			if (Characters[i]->charaId() == 'b' && Characters[j]->groupId() == 3 ||
				Characters[i]->groupId() == 3 && Characters[j]->groupId() == 'b') {
				continue;
			}
			if (Characters[i]->wLeft() < Characters[j]->wRight() &&
				Characters[j]->wLeft() < Characters[i]->wRight() &&
				Characters[i]->wTop() < Characters[j]->wBottom() &&
				Characters[j]->wTop() < Characters[i]->wBottom()) {
				//プレイヤーとボス
				if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 1 ||
					Characters[i]->groupId() == 1 && Characters[j]->groupId() == 0) {
					Characters[i]->damage();
					Characters[j]->damage();
				}
				//プレイヤーとアイテム
				else if (Characters[i]->charaId() == 'a' && Characters[j]->groupId() == 2 ||
					Characters[i]->groupId() == 2 && Characters[j]->charaId() == 'a') {
					if (Characters[i]->groupId() == 2) {
						if (Characters[i]->charaId() == 'g') {
							Characters[j]->buff('g');
							playSound(CharaMng.SDSnd);
						}
						else {
							Characters[j]->buff('h');
							playSound(CharaMng.FFSnd);
						}
						Characters[i]->damage();
					}
					else {
						if (Characters[j]->charaId() == 'g') {
							Characters[i]->buff('g');
							playSound(CharaMng.SDSnd);
						}
						else {
							Characters[i]->buff('h');
							playSound(CharaMng.FFSnd);
						}
						Characters[j]->damage();
					}
				}
				//プレイヤーとデバフキャラ
				else if (Characters[i]->charaId() == 'a' && Characters[j]->groupId() == 3 ||
					Characters[i]->groupId() == 3 && Characters[j]->charaId() == 'a') {
					if (Characters[i]->groupId() == 3) {
						if (Characters[i]->charaId() == 'c') {
							Characters[j]->debuff('c');
							playSound(CharaMng.sheepSnd);
						}
						else {
							Characters[j]->debuff('d');
							playSound(CharaMng.catSnd);
						}
						Characters[i]->damage();
					}
					else {
						if (Characters[j]->charaId() == 'c') {
							Characters[i]->debuff('c');
							playSound(CharaMng.sheepSnd);
						}
						else {
							Characters[i]->debuff('d');
							playSound(CharaMng.catSnd);
						}
						Characters[j]->damage();
					}
				}
			}
		}
	}
}

void CHARACTER_MANAGER::draw()
{
	for (int i = 0; i < Total; i++) {
		if (Characters[i]->hp() > 0) {
			Characters[i]->draw();
		}
	}
}
