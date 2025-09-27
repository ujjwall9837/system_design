#ifndef DELL_BUILDER_HPP
#define DELL_BUILDER_HPP
#include "builder.hpp"
#include <iostream>

class DellBuilder : public Builder
{
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();

};

#endif