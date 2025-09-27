#include "concrete_builder.hpp"
#include <iostream>

using namespace std;

void DellBuilder::buildMonitor()
{
    desktop->setMonitor("Dell 24 inch");
    cout << "Dell Monitor built" << endl;
}

void DellBuilder::buildKeyboard()
{
    desktop->setKeyboard("Dell Keyboard");
    cout << "Dell Keyboard built" << endl;
}       
void DellBuilder::buildMouse()
{
    desktop->setMouse("Dell Mouse");
    cout << "Dell Mouse built" << endl;
}
void DellBuilder::buildSpeaker()
{
    desktop->setSpeaker("Dell Speaker");
    cout << "Dell Speaker built" << endl;
}
void DellBuilder::buildRam()
{
    desktop->setRam("16GB DDR4");
    cout << "Dell RAM built" << endl;
}
void DellBuilder::buildProcessor()
{
    desktop->setProcessor("Intel i7");
    cout << "Dell Processor built" << endl;
}



