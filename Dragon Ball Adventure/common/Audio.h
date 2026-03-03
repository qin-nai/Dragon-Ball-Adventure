#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "Audio.h"
#pragma comment(lib, "winmm.lib")
#include <string>

using namespace std;
void playAudio(const char* p);
//≤ª÷ÿ∏¥
void playAudioNorepeat(const char* p);