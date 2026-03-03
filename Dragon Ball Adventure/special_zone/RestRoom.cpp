#include "RestRoom.h"
#include "../common/GFunction.h"
#include "../common/Team.h"
#include "../common/Audio.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void rest_room_loop() {
	playAudio("rest1.mp3");
	system("cls");
	Fighter* fighter = &myFighter[g_actionIndex];
	setCursorPosition(20, 4);
	cout << "\tHp\tBP\tBE";
	setCursorPosition(20, 5);
	cout << fighter->name
		 << "\tHp" << " " << fighter->hp
		 << "\tBP" << " " << fighter->bp
		 << "\tBE" << " " << fighter->be;

	setCursorPosition(20, 8);
	CoutText("蛇女：好好休息！");
	playAudio("rest2.mp3");

	system("cls");
	Sleep(3000);
	playAudio("rest1.mp3");

	fighter->hp = fighter->maxHp;
	fighter->be = fighter->maxBe;
	
	setCursorPosition(20, 4);
	cout << "\tHp\tBP\tBE";
	setCursorPosition(20, 5);
	cout << fighter->name
		 << "\tHp" << " " << fighter->hp
		 << "\tBP" << " " << fighter->bp
		 << "\tBE" << " " << fighter->be;

	setCursorPosition(20, 8);
	CoutText("蛇女：欢迎下次再来！");

}