#pragma once
#include <Windows.h>
#include <iostream>
//输出字体的颜色
void Color(WORD color);

//移动光标
void setCursorPosition(int x, int y);

//打印文本
void CoutText(const char* str);

void CoutText2(const char* str);

//传入一个概率，决定事件是否发生
//返回1发生  0没发生   71.35
int ifEventHappen(double rate);

