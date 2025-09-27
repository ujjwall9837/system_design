#include "desktop.hpp"
#include <iostream>

using namespace std;
void Desktop::setMonitor(string pmonitor)
{
    monitor = pmonitor;
}
void Desktop::setKeyboard(string pkeyboard)
{
    keyboard = pkeyboard;
}
void Desktop::setMouse(string pmouse)
{
    mouse = pmouse;
}
void Desktop::setSpeaker(string pspeaker)
{
    speaker = pspeaker;
}
void Desktop::setRam(string pram)
{
    ram = pram;
}
void Desktop::setProcessor(string pprocessor)
{
    processor = pprocessor;
}

void Desktop::setMotherBoard(string pmotherBoard)
{
    motherBoard = pmotherBoard;
}

void Desktop::showConfiguration()
{
    cout << "Desktop Configuration: " << endl;
    cout << "Monitor: " << monitor << endl;
    cout << "Keyboard: " << keyboard << endl;
    cout << "Mouse: " << mouse << endl;
    cout << "Speaker: " << speaker << endl;
    cout << "RAM: " << ram << endl;
    cout << "Processor: " << processor << endl;
    cout << "MotherBoard: " << motherBoard << endl;
}