/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: gates.cpp
File Purpose: To define the basic gate class
Date Started: April 6, 2017


*/

#include "gate.h"

Gate::Gate(int d, Wire* in1, Wire* in2, Wire* o,string t){
	delay = d;
	input1 = in1;
	input2 = in2;
	output = o;
	out = UND;
	type = t;
}

bool Gate::includesWire(Wire *wired){//This function checks and sees if the gate contains the wire
	if (wired == input1) {
		return true;
	}
	else if (wired == input2) {
		return true;
	}
	else {
		return false;
	}
}
