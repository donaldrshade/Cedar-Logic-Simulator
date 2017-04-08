/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: gate.h
File Purpose: To create a gate class with underlying functionality for the simulator
Date Started: April 6, 2017


*/

#ifndef gate_h
#define gate_h

#include <stdio.h>
#include "event.h"

class Gate {
public:
    Gate(int d=0, Wire* w= NULL, int c = -1);
    void setOutput(Wire* w);
    void setDelay(int d);
    int getDelay();
    int getCreationCount();
    Wire* getOutput();
    void createEvent(Queue* q, int currentTime);
    
private:
    int delay;
    int creationCount;
    Wire* output;
    
};

#endif 
