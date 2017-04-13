/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: advancedGates.cpp
File Purpose: To define various derived gate classes
Date Started: April 6, 2017


*/

#include "advancedGates.h"

Not::Not(Wire* in, Wire* out) {
	input1 = in;
	output = out;
}

void Not::setOutput(Wire* in) {
	if (in->getState() == LOW) {
		output->setState(HIGH);
	}
	else if (in->getState() == 1) {
		output->setState(LOW);
	}
}

And::And(Wire *in1, Wire *in2, Wire *out) {
	input1 = in1;
	input2 = in2;
	output = out;
}

void And::setOutput(Wire *in1, Wire *in2) {
	if (in1->getState() == HIGH == in2->getState()) {
		output->setState(HIGH);
	}
	if (in1->getState == LOW || in2->getState() == LOW) {
		if (in2->getState() == UND || in1->getState() == UND) {
			output->setState(LOW);
		}
		if (in1->getState() == in2->getState() == LOW) {
			output->setState(LOW);
		}
	}
	if (in1->getState == HIGH || in2->getState() == HIGH) {
		if (in2->getState() == UND || in1->getState() == UND) {
			output->setState(UND);
		}
	}
}

Or::Or(Wire *in1, Wire *in2, Wire *out) {
	input1 = in1;
	input2 = in2;
	output = out;
}

void Or::setOutput(Wire *in1, Wire *in2) {
	if (in1->getState() == HIGH || in2->getState() == HIGH) {
		output->setState(HIGH);
	}
	if (in1->getState() == LOW && in2->getState() == UND || in1->getState() == UND && in2->getState == LOW) {
		output->setState(UND);
	}
	if (in1->getState() == LOW == in2->getState()) {
		output->setState(LOW);
	}
}

Xor::Xor(Wire *in1, Wire *in2, Wire *out) {
	input1 = in1;
	input2 = in2;
	output = out;
}

void Xor::setOutput(Wire *in1, Wire *in2) {
	if (in1->getState() == HIGH && in2->getState == LOW || in1->getState() == LOW && in2->getState() = HIGH) {
		output->setState(HIGH);
	}
	else if (in1->getState() == UND || in2->getState()==UND){
		output->setState(UND);
	}
	else if (in1->getState() == in2->getState()) {
		output->setState(LOW);
	}
}