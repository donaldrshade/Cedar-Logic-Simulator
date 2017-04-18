/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: gates.cpp
File Purpose: To define the basic gate class
Date Started: April 6, 2017


*/

#include "gate.h"

Gate::Gate(int d, Wire* in1, Wire* in2, Wire* o){
	delay = d;
	input1 = in1;
	input2 = in2;
	output = o;
	out = UND;
}

void Gate::createEvent(priority_queue<Event> &q, int currentTime){
    
}
