#pragma once

typedef enum RACE
{
	RACE_BI,//必
	RACE_MO,//魔
	RACE_SHEN,//神
	RACE_GUI,//龟
	RACE_HUO,//惑
	RACE_JIE//界

};
//角色信息
typedef struct Fighter
{
	char name[20];
	int level;//等级
	RACE race;//0神族 1魔族 2龟 3界
	int hp;//生命值
	int maxHp;//最大生命值
	int bp;//经验值
	int be;//魔法值
	int maxBe;//最大魔法值

	int attach;//攻击
	int befense;//防御
	int speed;//速度

	int x;
	int y;
};
//卡牌信息
typedef struct Card {
	int isUsed;//是否被使用过 0未 1用
	int starCount;//卡牌星星数量
	RACE race;//卡牌所属种族
	int defense;//防御等级
};
//实时移动的位置坐标
typedef struct Positon{
	int x;
	int y;
};