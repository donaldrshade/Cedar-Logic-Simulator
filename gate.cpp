/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: gates.cpp
File Purpose: To define the basic gate class
Date Started: April 6, 2017


*/

#include "gate.h"

Gate::Gate(int d, Wire* w, int c){
    delay = d;
    output = w;
    creationCount = c;
}
void Gate::setOutput(Wire* w){
    output = w;
}
void Gate::setDelay(int d){
    delay = d;
}
int Gate::getDelay(){
    return delay;
}
int Gate::getCreationCount(){
    return creationCount;
}
Wire* Gate::getOutput(){
    return output;
}
void Gate::createEvent(queue* q, int currentTime){
    
}
