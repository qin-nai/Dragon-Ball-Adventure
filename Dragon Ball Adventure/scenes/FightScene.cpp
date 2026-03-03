#include <string.h>
#include "FightScene.h"
#include "../common/GlobalDefine.h"
#include "../common/GFunction.h"
#include "../common/Audio.h"
using namespace std;

static Fighter emy_ks ={.name = "卡斯",.race = RACE_HUO,.hp = 80,.attach = 20,.befense = 9,.speed = 7};
static Fighter emy_pb ={.name = "胖布",.race = RACE_HUO,.hp = 80,.attach = 20,.befense = 9,.speed = 7};
static Fighter emy_sl ={.name = "沙龙",.race = RACE_HUO,.hp = 80,.attach = 20,.befense = 9,.speed = 7};
static Fighter emy_hl ={.name = "海勒",.race = RACE_HUO,.hp = 80,.attach = 20,.befense = 9,.speed = 7};

static Fighter emyArr[10];
static int emyCount = 0;
//创建敌人
static void createEnemy() {
	//遇到一个沙龙
	if (ifEventHappen(10.0)) {
		emyArr[0] = emy_sl;
		emyCount = 1;
		return;
	}
	//遇到三个沙龙
	if (ifEventHappen(10.0)) {
		emyArr[0] = emy_sl;
		emyArr[1] = emy_sl;
		emyArr[2] = emy_sl;
		strcpy_s(emyArr[0].name, 20, "沙龙1");
		strcpy_s(emyArr[1].name, 20, "沙龙2");
		strcpy_s(emyArr[2].name, 20, "沙龙3");
		emyCount = 3;
		return;
	}
	//遇到四个敌人
	emyArr[0] = emy_pb;
	emyArr[1] = emy_sl;
	emyArr[2] = emy_sl;
	emyArr[3] = emy_sl;
	strcpy_s(emyArr[0].name, 20, "胖布");
	strcpy_s(emyArr[1].name, 20, "沙龙1");
	strcpy_s(emyArr[2].name, 20, "沙龙2");
	strcpy_s(emyArr[3].name, 20, "沙龙3");
	emyCount = 3;
}
//敌人是否惊慌而逃
static int createEscape() {
	system("cls");
	for (int i = 0; i < emyCount; i++) {
		setCursorPosition(25, 6 + i);
		cout << emyArr[i].name;
	}
	if (!ifEventHappen(20.0)) return 0;
	setCursorPosition(25, 7 + emyCount);
	CoutText2("敌人出现，敌人惊慌而逃");
	return 1;
}
void fight_scene_loop(){
	//生成敌人数据
	
	createEnemy();
	if (createEscape())return;
	//敌人出现->敌人惊慌而逃->按任意键退出
playAudioNorepeat("./Audio/fight1.mp3");
	while (1) {

	}
}
