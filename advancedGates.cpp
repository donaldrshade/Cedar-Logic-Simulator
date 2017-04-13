/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: advancedGates.cpp
File Purpose: To define various derived gate classes
Date Started: April 6, 2017


*/

#include "advancedGates.h"

Not::Not(int d,Wire* in, Wire* out):Gate(d,in,NULL,out){
	//All in Base Init
}

void Not::setOutput(Wire* in) {
	if (in->getState() == LOW) {
		output->setState(HIGH);//this should be create event
	}
	else if (in->getState() == 1) {
		output->setState(LOW);
	}
}

And::And(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	//All in Base Init
}

void And::setOutput(Wire *in1, Wire *in2) {
	State tempIn1 = in1->getState();
	State tempIn2 = in2->getState();
	if (tempIn1 == HIGH == tempIn2) {
		output->setState(HIGH);
	}
	if (tempIn1 == LOW || tempIn2 == LOW) {
		if (in2->getState() == UND || in1->getState() == UND) {
			output->setState(LOW);
		}
		if (tempIn1 == tempIn2 == LOW) {
			output->setState(LOW);
		}
	}
	if (tempIn1 == HIGH || tempIn2 == HIGH) {
		if (tempIn1 == UND || tempIn2 == UND) {
			output->setState(UND);
		}
	}
}

Or::Or(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	//All in Base Init
}

void Or::setOutput(Wire *in1, Wire *in2) {
	State tempIn1 = in1->getState();
	State tempIn2 = in2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH) {
		output->setState(HIGH);
	}
	if (tempIn1 == LOW || tempIn2 == LOW) {
		if (tempIn1 == UND || tempIn2 == UND) {
			output->setState(UND);
		}
	}
	if (tempIn1 == LOW == tempIn2) {
		output->setState(LOW);
	}
}

Xor::Xor(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out){
	//All in Base Init
}

void Xor::setOutput(Wire *in1, Wire *in2) {
	State tempIn1 = in1->getState();
	State tempIn2 = in2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH){
		if (tempIn1 == LOW || tempIn2 == LOW) {
			output->setState(HIGH);`
		}
	}
	else if (tempIn1 == UND || tempIn2==UND){
		output->setState(UND);
	}
	else if (tempIn1 == tempIn2) {
		output->setState(LOW);
	}
}