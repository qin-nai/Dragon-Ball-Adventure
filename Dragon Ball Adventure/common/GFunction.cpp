#include "GFunction.h"
#include <conio.h>
using namespace std;
//输出字体的颜色
void Color(WORD color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
	SetConsoleTextAttribute(hConsole, color);
}

//移动光标
void setCursorPosition(int x, int y) {
	COORD coord;
	coord.X = x * 2;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//打印文字
void CoutText(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        cout << str[i];
        cout.flush();//刷新缓冲区
        Sleep(100);
        i++;
    }
    cout << endl;
    system("pause");
}

void CoutText2(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        cout << str[i];
        cout.flush();//刷新缓冲区
        Sleep(100);
        i++;
    }
    cout << endl;
    _getch();
}


int ifEventHappen(double rate)
{
    int num = rate * 100;
    int randNum = rand() % 10000;
    if (num > randNum) {
        return 1;
    }
    return 0;
}
