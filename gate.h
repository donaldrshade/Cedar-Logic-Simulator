//
//  Gate.hpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#ifndef gate_h
#define gate_h

#include <stdio.h>
#include "event.h"

class BasicGate(){
public:
    BasicGate(int d=0, Wire* w= NULL, int c = -1);
    void setOutput(Wire* w);
    void setDelay(int d);
    int getDelay();
    int getCreationCount();
    Wire* getOutput();
    void createEvent(queue* q, int currentTime);
    
private:
    int delay;
    int creationCount;
    Wire* output;
    
};

#endif /* gate_h */
