#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "UserGuide.h"
#include "../common/Audio.h"
#include "../common/GFunction.h"
#include "Scene1.h"
using namespace std;


//选择了重新开始游戏
static void OnRestartGame() {
    /*
    playAudio("./Audio/guide1.mp3");
    system("cls");
    CoutText("有一天一支神秘的部队来到地球上");
    CoutText("这星球上的人还活着");
    CoutText("拉迪：有一位高能的家伙..");
    CoutText("距离4880");
    CoutText("拉迪：卡卡罗特？");
    CoutText("短笛：有种能量在靠近,是悟空？");
    CoutText("短笛：什么东西！");
    CoutText("短笛：想找死？好大的口气");
    CoutText("短笛：知道在和谁讲话吗？");
    CoutText("给你点颜色看看");
    CoutText("短笛被对方的能量压制住");
    CoutText("短笛：哎哟..哎哟");
    CoutText("还有一股能量..这次才是卡卡罗特");
    CoutText("拉迪：是不是失去了赛亚人的自豪感？卡卡罗特？");

    playAudio("./Audio/guide2.mp3");

    CoutText("那是悟空和他的儿子悟饭去了龟宫");
    CoutText("龟仙人：悟空，好久不见了！");
    CoutText("悟空：嘿嘿..");
    CoutText("龟仙人：看孩子啦？");
    CoutText("悟空：是我儿子");
    CoutText("龟仙人：你儿子？");
    CoutText("悟空：他叫悟饭");
    CoutText("龟仙人：孙悟饭！");
    CoutText("悟空：对！");
    CoutText("悟饭：你好！");
    CoutText("龟仙人：你好！帽子上的是星珠吗？");
    CoutText("悟空：星珠");
    CoutText("悟空：嘿嘿..");

    playAudio("./Audio/guidel.mp3");

    CoutText("拉迪：哈哈哈长大了..很像你父亲");
    CoutText("拉迪：卡卡罗特你的使命是毁掉人类");
    CoutText("悟空：尾..尾巴..");
    CoutText("拉迪：明白了吗？");
    CoutText("拉迪：告诉你...");
    CoutText("你出生在赔塔彗星上");
    CoutText("是宇宙最强..赛亚人族!!!");
    CoutText("拉迪：我是你兄长！");
    CoutText("龟仙人：这家伙是悟空的兄长？");
    CoutText("总算清楚了悟空的来历..");
    CoutText("拉迪：为了毁掉这个星球上的人类，才送你到这里来的");
    CoutText("拉迪：赛亚人的星球由于陨石冲击爆炸了！");
    CoutText("拉迪：因此我们需要一颗新的星球");
    CoutText("拉迪：现在还不晚");
    CoutText("我们一起消灭人类！");
    CoutText("悟空：这..这？");
    CoutText("拉迪：没办法");
    CoutText("那位是你儿子吧");
    CoutText("那条尾巴就是");
    CoutText("赛亚血统的证据");
    CoutText("这时拉迪感觉到悟饭身上隐藏的那股不可估量的能量");
    CoutText("拉迪：对不起！");
    CoutText("你儿子借给我一下！");
    CoutText("悟空：不可以！");
    CoutText("悟饭：父亲！");
    CoutText("拉迪：卡卡罗特，孩子是死是活，哈哈哈...");
    CoutText("悟空：这畜生！");
    CoutText("龟仙人：你一个打不过他");
    CoutText("短笛：你我合力打败他");
    CoutText("悟空：有道理..你为什么这样做？");
    CoutText("短笛：他是我征服世界的绊脚石");
    CoutText("悟空：联手倒是个好办法！");
    CoutText("悟空：先去布尔玛那里借一下星珠雷达");
    */
    playAudio("./Audio/scene1.mp3");

    CoutText("于是悟空和短笛组成了地球上最强的联手");
    Scene();
}

//选择了历史记录
static void OnRecored() {

}

void uesr_guide_start() {
    playAudio("./Audio/start.mp3");
    cout << "===========================================" << endl;
    cout << "||                                       ||" << endl;
    cout << "||              欢迎来到七龙珠           ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||             收集龙珠,召唤神龙         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "===========================================" << endl;
    cout << endl;
    cout << "             ";
    system("pause");
    
    int option = 0;
    playAudio("./Audio/option.mp3");
    while (1) {
        string p1 = "==>";//开始0
        string p2 = "==>";//记录1
        if (option == 0) p2 = "   ";
        if (option == 1) p1 = "   ";
        system("cls");
        cout << "=============================================" << endl;
        cout << "||                                         ||" << endl;
        cout << "||                 " << p1 << "开始                 ||" << endl;
        cout << "||                 " << p2 << "记录                 ||" << endl;
        cout << "||                                         ||" << endl;
        cout << "=============================================" << endl;
        cout << "w/s控制箭头上下，回车确定";
        int ch = _getch();
        if (ch == 119) {//w
            option = 0;
        }
        else if (ch == 115) {//s
            option = 1;
        }
        else if (ch == 13) {//回车
            break;
        }
    }

    if (option == 0) {
        OnRestartGame();
    }
    else if (option == 1) {
        OnRecored();
    }
}