#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>

using namespace std;
class Desktop
{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherBoard;

    public:
        void setMonitor(string monitor);
        void setKeyboard(string keyboard);
        void setMouse(string mouse);
        void setSpeaker(string speaker);
        void setRam(string ram);
        void setProcessor(string processor);
        void setMotherBoard(string motherBoard);
        void showConfiguration();
};

#endif