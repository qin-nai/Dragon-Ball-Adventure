#include "Team.h"

Card cards[5];//队伍卡牌数量
int g_actionIndex=0;//行动者的下标
int g_fighterCount = 2;//战士的数量
Fighter myFighter[2] = {//人物数据
	//悟空	
	{
		.name = "悟空",
		.level = 1,
		.race = RACE_SHEN,
		.hp = 80,
		.maxHp = 80,
		.bp = 416,
		.be = 59,
		.maxBe = 59,
		.attach = 20,
		.befense = 9,
		.speed = 7,
		.x = 16,
		.y = 16
	},
	//短笛
	{
		.name = "短笛",
		.level = 1,
		.race = RACE_MO,
		.hp = 80,
		.maxHp = 80,
		.bp = 408,
		.be = 50,
		.maxBe = 50,
		.attach = 22,
		.befense = 8,
		.speed = 8,
		.x = 15,
		.y = 17
	}

};