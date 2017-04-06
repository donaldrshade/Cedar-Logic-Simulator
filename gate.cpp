//
//  Gate.cpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#include "gate.h"

BasicGate(int d, Wire* w, int c){
    delay = d;
    output = w;
    creationCount = c;
}
void setOutput(Wire* w){
    output = w;
}
void setDelay(int d){
    delay = d;
}
int getDelay(){
    return delay;
}
int getCreationCount(){
    return creationCount;
}
Wire* getOutput(){
    return output;
}
void createEvent(queue* q, int currentTime){
    
}
