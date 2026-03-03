#include "Audio.h"
void playAudio(const char* audioPath) {
    mciSendStringA("close mymusic", nullptr, 0, nullptr);
    // 1. 打开 MP3
    string openCmd = "open \"" + string(audioPath) + "\" type mpegvideo alias mymusic";
    MCIERROR err = mciSendStringA(openCmd.c_str(), nullptr, 0, nullptr);

    if (err != 0) {
        cout << "打开失败，错误码: " << err << " (路径/格式错误)" << endl;
        return;
    }

    // 2. 播放 MP3
    err = mciSendStringA("play mymusic repeat", nullptr, 0, nullptr);

    if (err != 0) {
        cout << "播放失败，错误码: " << err << " (驱动不识别命令)" << endl;
        mciSendStringA("close mymusic", nullptr, 0, nullptr);
        return;
    }

}

void playAudioNorepeat(const char* audioPath) {
    mciSendStringA("close mymusic", nullptr, 0, nullptr);
    // 1. 打开 MP3
    string openCmd = "open \"" + string(audioPath) + "\" type mpegvideo alias mymusic";
    MCIERROR err = mciSendStringA(openCmd.c_str(), nullptr, 0, nullptr);

    if (err != 0) {
        cout << "打开失败，错误码: " << err << " (路径/格式错误)" << endl;
        return;
    }

    // 2. 播放 MP3
    err = mciSendStringA("play mymusic", nullptr, 0, nullptr);

    if (err != 0) {
        cout << "播放失败，错误码: " << err << " (驱动不识别命令)" << endl;
        mciSendStringA("close mymusic", nullptr, 0, nullptr);
        return;
    }

}
