/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: gates.cpp
File Purpose: To define the basic gate class
Date Started: April 6, 2017


*/

#include "gate.h"

Gate::Gate(int d){
    delay = d;
}

void Gate::setInput1(Wire* in1) {
	input1->setState(in1->getState());
}

void Gate::setInput2(Wire *in2) {
	input2->setState(in2->getState());
}

void Gate::setDelay(int d){
    delay = d;
}

State Gate::getOutputState() {
	return output->getState();
}

State Gate::getInput1State() {
	return input1->getState();
}

State Gate::getInput2State() {
	return input2->getState();
}

int Gate::getDelay(){
    return delay;
}

void Gate::createEvent(queue<int*> q, int currentTime){
    
}
