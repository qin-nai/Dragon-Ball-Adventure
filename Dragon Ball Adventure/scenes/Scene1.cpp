#include <conio.h>
#include "Scene1.h"
#include "../common/Team.h"
#include "../common/GFunction.h"
#include "../common/Audio.h"
#include "FightScene.h"

#define MAP_ROW 28
#define MAP_COL 62

//+1是因为结尾还有一个\0符
static const char Map[28][62 + 1] = {
		"99999A99A99999BABABCAAAAAAA9999A99A99ACA999AAA9AAAA99A99A99999",
		"9999999A99999BBBABBCAAAAAA9999999999AACAA999999999A99999999999",
		"99A999A999BBBAABBBBCACCAAAAA9999BBBBAACC999A99999999A9999AAA99",
		"99AA999DBBAAAAABBAACCCCCAAAAA9BBBBBAAAACA999A99999999999AAIA99",
		"99999AAAAAAAABBAACCCACCAAAAAAAABBBBBAAACAA99999999999999AAAA99",
		"9A99AAAAAABABBACCCAFAACCCAAAAAE99BBAAAACCCA999999AAIAAAAAAKAA9",
		"AAAAAAAAAAABAAACCCAACCCCCAAA99999BAAAAAAACAA999AAA999999AAAAA9",
		"AAAAAAAAABBBCCCCCCCCCCCAAAAAA9999AAAAAACCCA9999A99A999999A9999",
		"AAAAAAABBBBAACCCCCCCCCCCCAAAA999AAAAAAACAAAA999A99999A99999999",
		"AAAAAABBAAACCCCCCCCCCCCCAAAA99DAAAAAAAACCCAA999A9999999999A99A",
		"AAAAABBBCCCCCCCCCCCCCCCAAAAAA999AAAAAAAAACCAA99I999A99999AA999",
		"AAFAAABBCCCCCCCCCCCCCCCCCAAAA999AAAAAAAAAACAFAAAA9999A99999A99",
		"AAGAAAABBBCCCCCCCCCCCCAAAAAA9999AAAAAAAAAACAAAAAAAA999AAA999AA",
		"AAAAAAAABACCCCCCCCCCCCCAAAAA99999AAAAAAAAACCCCCCAAAAAAA99AAAAA",
		"AAAAAABBACCCCCCCCCCCCCCCAAAAA9999AAAAAAAAAAACCACCCCCCCA999AAAA",
		"BAAAAAABCCCCCCCAACCCCCCCCCAAAAF999AAAAAAAAAAAAAAAAAAACAAA9AAAA",
		"BBBBAAAACCCCCAAHAACCCCCCCCCAAA99999AAAAAAAAAAAAAA99CCCCA99AAAA",
		"BBBBAAAAACCCCCAAAACCCCCCCAAAAA99A99AAAAAAAAAAAA9999999999999BB",
		"BBBBAAACCCCCCCAAACCCCCCCCCAAAAA9999AAAAAAAAAAAAAAAB9A99BB999BB",
		"BBAAAAAAAAACCCACCCCCCCCCAAAAAAA999A99AACCCCCCAA99BBBEEEBBD9BBB",
		"BBBAAAAAAACCCCCCCCCCCCCCAEAAAA9999999ACCAAAACCC99BBBEFEBB99BBB",
		"BBBBAAAAACCCCFACCCCCCCCAAAAAAA99999AAACAAGAAAACA9999EEE999AAAA",
		"BBBAACCCCCCCCACCCCCCCCCAAAAAAAA99AAAAACAAAAAACCCA999999AAACCCC",
		"BBAAAAACCCCCCCCCCCCCAAAAAAAAAAJ9JAAAACCAAAAAAAACAA9999AACCCCCC",
		"BBAAAACCCCCCCCCCCCCCCAAAAAAAA999A999ACAAAAAAAAACC999AAAAACCCCC",
		"BAACCCCCCCCCCCCCCCCCAAAAABBB9999999AACAAAA9AA99AC99AAACCCCCCCC",
		"ACCCCCCCCCCCCCCCCAAAAABBBBB9999999AACCCCA999999ACAAACCCCCCCCCC",
		"CCCCCCCCCCCCCCCCAAAAAABBBB9999999AAACCCCC999A9ACCAACCCCCCCCCCD",
};

//在地图上输出人物
static void coutMyFighterPosition() {
	setCursorPosition(myFighter[0].x, myFighter[0].y);
	cout << "悟";
	setCursorPosition(myFighter[1].x, myFighter[1].y);
	cout << "短";
}

//显示剩余步数
static void coutLeftStep(int step) {
	setCursorPosition(5*2, MAP_ROW + 3);
	cout << "剩余步数：" << step;
}

//选则卡牌 返回星星的数量
static int selectCards() {
	//牌往前推
	int uIndex = -1;//当前已使用的牌的下标
	for (int i = 0; i < 5; i++) {
		if (cards[i].isUsed && uIndex == -1) {
			uIndex = i;
			continue;
		}
		if (cards[i].isUsed == 0 && uIndex != -1) {
			Card temp = cards[i];
			cards[i] = cards[uIndex];
			cards[uIndex] = temp;
			uIndex++;
		}
	}
	char str1[6][4] = { "必","魔","神","龟","惑","界" };
	char str2[8][4] = { "一","二","三","四","五","六","七","八" };
	//随机卡牌
	for (int i = 0; i < 5; i++) {
		if (cards[i].isUsed == 0) { continue; }
		int num1 = rand() % 8 + 1;
		int num2 = rand() % 6;
		int num3 = rand() % 8;

		cards[i].starCount = num1;
		cards[i].race = (RACE)num2;
		cards[i].defense = num3;
		cards[i].isUsed = 0;
	}
	//打印卡牌
	for (int i = 0; i < 5; i++) {
		int num1 = cards[i].starCount;
		int num2 = cards[i].race;
		int num3 = cards[i].defense;
		setCursorPosition(i * 2, MAP_ROW + 1);
		cout << num1;
		setCursorPosition(i * 2, MAP_ROW + 2);
		cout << str1[num2];
		setCursorPosition(i * 2, MAP_ROW + 3);
		cout << str2[num3];
	}
	int index = 0;
	setCursorPosition(0, MAP_ROW + 3);
	while (1) {
		int ch = _getch();
		switch (ch) {
		case 'a':
			index--;
			if (index < 0) {index = 4;}
			setCursorPosition(index * 2, MAP_ROW + 3);
			break;
		case 'd':
			index++;
			if (index > 4) { index = 0; }
			setCursorPosition(index * 2, MAP_ROW + 3);
			break;
		case '\r':
			setCursorPosition(index * 2, MAP_ROW);
			cout << '.';
			return index;
			break;
		}
	}
}

//打印地图
static void coutMap() {
		/*
		9 : 大山（不可移动） A : 绿地 B : 丘陵，显示为黄色区 C : 大海，显示为蓝色区
		D : 显示一个【珠】   E : 修行地，地图上会显示为【修】F : 蛇女的休息点，地图上会显示为【休】
		G : 显示道观的【观】 H : 显示龟仙人的住所【龟】      I : 显示石头的【石】
		J : 显示白云的【云】 K : 显示拉迪的【迪】
		*/
	setCursorPosition(0,0);
	
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 62; j++) {
			switch (Map[i][j]) {
			case '9':
				Color(FOREGROUND_RED | FOREGROUND_INTENSITY);//红色增强
				cout << "山";
				break;
			case 'A':
				Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);//绿色增强
				cout << "绿";
				break;
			case 'B':
				Color(FOREGROUND_RED | FOREGROUND_GREEN);//黄色
				cout << "丘";
				break;
			case 'C':
				Color(FOREGROUND_BLUE | FOREGROUND_INTENSITY);//蓝色增强
				cout << "海";
				break;
			default:
				Color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//白色
				switch (Map[i][j]) {
				case 'D':cout << "珠"; break;
				case 'E':cout << "修"; break;
				case 'F':cout << "休"; break;
				case 'G':cout << "观"; break;
				case 'H':cout << "龟"; break;
				case 'I':cout << "石"; break;
				case 'J':cout << "云"; break;
				case 'K':cout << "迪"; break;
				}
			}
		}
		cout << endl;
	}
}

//移动人物 
static void moveFighter(int cardIndex) {
	int starCount = cards[cardIndex].starCount;
	int leftCount = starCount;//剩余步数
	int x = myFighter[g_actionIndex].x;
	int y = myFighter[g_actionIndex].y;
	Positon posArr[9];//记录移动中的每一个位置
	posArr[0].x = x;
	posArr[0].y = y;
	setCursorPosition(x, y);
	
	while (1) {
		coutLeftStep(leftCount);
		setCursorPosition(x, y);
		int ch = _getch();
		switch (ch) {
		case 'w'://上
			if (leftCount == 0) break;//判断步数是否为0
			if (y == 0) break;//防止越界
			if (Map[y - 1][x] == '9') break;

			leftCount--;
			y = y - 1;
			setCursorPosition(x, y);
			posArr[starCount - leftCount].x = x;
			posArr[starCount - leftCount].y = y;
			break;
		case 'a'://左
			if (leftCount == 0) break;//判断步数是否为0
			if (x == 0)break;//防止越界
			if (Map[y][x-1] == '9') break;

			leftCount--;
			x = x - 1;
			setCursorPosition(x, y);
			posArr[starCount - leftCount].x = x;
			posArr[starCount - leftCount].y = y;
			break;
		case 's'://下
			if (leftCount == 0) break;//判断步数是否为0
			if (y == MAP_ROW - 1)break;//防止越界
			if (Map[y + 1][x] == '9') break;

			leftCount--;
			y = y + 1;
			setCursorPosition(x, y);
			posArr[starCount - leftCount].x = x;
			posArr[starCount - leftCount].y = y;
			break;
		case 'd'://右
			if (leftCount == 0) break;//判断步数是否为0
			if (x == MAP_COL - 1)break;//防止越界
			if (Map[y][x + 1] == '9') break;

			leftCount--;
			x = x + 1;
			setCursorPosition(x, y);
			posArr[starCount - leftCount].x = x;
			posArr[starCount - leftCount].y = y;
			break;
		case 'i'://start

			break;
		case 'j'://A
			if (starCount - leftCount == 0) { break; }
			leftCount++;
			x = posArr[starCount - leftCount].x;
			y = posArr[starCount - leftCount].y;
			setCursorPosition(x, y);
			break;
		case '\r'://B
			if (leftCount != 0) { break; }
			for (int i = 1; i <= starCount; i++) {
				myFighter[g_actionIndex].x = posArr[i].x;
				myFighter[g_actionIndex].y = posArr[i].y;
				coutMap();
				coutMyFighterPosition();
				Sleep(200);
			}
			
			cards[cardIndex].isUsed = 1;

			setCursorPosition(0, MAP_ROW);
			cout << "                       ";
			setCursorPosition(5 * 2, MAP_ROW + 3);
			cout << "                       ";

			return;
		}
	}
}

//决定人物移动后触发的事件
static void onFIghterMoved() {
	int x = myFighter[g_actionIndex].x;
	int y = myFighter[g_actionIndex].y;
	switch (Map[y][x]) {
	case'F':
		rest_room_loop();
		playAudio("./Audio/scene1.mp3");
		break;
	default:
		//30%
		if(!ifEventHappen(30))break;
		//战斗场景
		cout << "遇怪！";
		fight_scene_loop();
		playAudio("./Audio/scene1.mp3");
	}

	g_actionIndex = g_actionIndex + 1;
	g_actionIndex = g_actionIndex % g_fighterCount;
}

void Scene() {
	playAudio("./Audio/scene1.mp3");
	for (int i = 0; i < 5; i++) {
		cards[i].isUsed = 1;
	}
	system("cls");
	
	while (1) {
		coutMap();
		coutMyFighterPosition();
		int cardIndex=selectCards();
		moveFighter(cardIndex);
		onFIghterMoved();

	}
}
