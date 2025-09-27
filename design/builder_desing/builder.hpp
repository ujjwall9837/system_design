#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <string>
#include <iostream>
#include "desktop.hpp"

class Builder
{
protected:
    Desktop *desktop;

public:
    Builder()
    {
        desktop = new Desktop();
    }
    virtual void buildMonitor() = 0;
    virtual void buildKeyboard() = 0;
    virtual void buildMouse() = 0;
    virtual void buildSpeaker() = 0;
    virtual void buildRam() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMotherBoard() = 0;
    virtual Desktop *getDesktop()
    {
        return desktop;
    }
};

#endif