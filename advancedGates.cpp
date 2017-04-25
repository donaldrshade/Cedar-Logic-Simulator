/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: advancedGates.cpp
File Purpose: To define various derived gate classes
Date Started: April 6, 2017


*/

#include "advancedGates.h"
#include <vector>

Not::Not(int d,Wire* in, Wire* out):Gate(d,in,NULL,out){
	type = "NOT";
}

void Not::checkForUpdate(vector<Event> &q, int currentTime, int &eventCount) {
	if (input1->getState() == LOW && out != HIGH) {
		eventCount++;
		q.push_back(Event(output, currentTime + delay, HIGH, eventCount));
		out = HIGH;

	}
	else if (input1->getState() == HIGH && out != LOW) {
		q.push_back(Event(output, currentTime + delay, LOW,eventCount+1));
		eventCount++;
		out = LOW;
	}
	else if (input1->getState() == UND && out != UND) {
		q.push_back(Event(output, currentTime + delay, UND, eventCount+1));
		eventCount++;
		out = UND;
	}
}

And::And(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	type = "AND";
}

void And::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount){
	if (input1->getState() == HIGH && input2->getState() == HIGH) {
		if (out != HIGH) {
			q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
			eventCount++;
			out = HIGH;
		}
	}
	else if(input1->getState() == LOW || input2->getState() == LOW){
		if (out != LOW) {
			q.push_back(Event(output, currentTime + delay, LOW, eventCount+1));
			eventCount++;
			out = LOW;
		}
	}
	if (input1->getState() == UND && input2->getState() == UND) {
		if (out != UND) {
			q.push_back(Event(output, currentTime + delay, UND, eventCount+1));
			eventCount++;
			out = UND;
		}
	}
}

Or::Or(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	type = "OR";
}

void Or::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount) {
	State tempIn1 = input1->getState();
	State tempIn2 = input2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH) {
		if (out != HIGH) {
			q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
			eventCount++;
			out = HIGH;
		}
	}

	else if (tempIn1 == UND || tempIn2 == UND) {
		if (out != UND) {
			q.push_back(Event(output, currentTime + delay, UND, eventCount + 1));
			eventCount++;
			out = UND;
		}
	}
	else{
		if (out != LOW) {
			q.push_back(Event(output, currentTime + delay, LOW, eventCount + 1));
			eventCount++;
			out = LOW;
		}
	}
}

Xor::Xor(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out){
	type = "XOR";
}

void Xor::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount) {
	State tempIn1 = input1->getState();
	State tempIn2 = input2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH){
		if (tempIn1 == LOW || tempIn2 == LOW) {
			if (out != HIGH) {
				q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
				eventCount++;
				out = HIGH;
			}
		}
	}
	else if (tempIn1 == UND || tempIn2==UND){
		if (out != UND) {
			q.push_back(Event(output, currentTime + delay, UND, eventCount + 1));
			eventCount++;
			out = UND;
		}
	}
	else if (tempIn1 == tempIn2 && tempIn1 != UND) {
		if (out != LOW) {
			q.push_back(Event(output, currentTime + delay, LOW, eventCount + 1));
			eventCount++;
			out = LOW;
		}
	}
}

Xnor::Xnor(int d, Wire *in1, Wire *in2, Wire *out) :Gate(d, in1, in2, out) {
	type = "XNOR";
}

void Xnor::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount) {
	State tempIn1 = input1->getState();
	State tempIn2 = input2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH) {
		if (tempIn1 == LOW || tempIn2 == LOW) {
			if (out != LOW) {
				q.push_back(Event(output, currentTime + delay, LOW, eventCount + 1));
				eventCount++;
				out = LOW;
			}
		}
	}
	else if (tempIn1 == UND || tempIn2 == UND) {
		if (out != UND) {
			q.push_back(Event(output, currentTime + delay, UND, eventCount + 1));
			eventCount++;
			out = UND;
		}
	}
	else if (tempIn1 == tempIn2 && tempIn1 != UND) {
		if (out != HIGH) {
			q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
			eventCount++;
			out = HIGH;
		}
	}
}


Nand::Nand(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	type = "NAND";
}

void Nand::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount) {
	State tempIn1 = input1->getState();
	State tempIn2 = input2->getState();
	if (tempIn1 == LOW || tempIn2 == LOW) {
		if (out != HIGH) {
			q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
			eventCount++;
			out = HIGH;
		}
	}
	else {
		if (out != LOW) {
			q.push_back(Event(output, currentTime + delay, LOW, eventCount + 1));
			eventCount++;
			out = LOW;
		}
	}
}

Nor::Nor(int d, Wire *in1, Wire *in2, Wire *out):Gate(d,in1,in2,out) {
	type = "NOT";
}

void Nor::checkForUpdate(vector<Event>& q, int currentTime, int &eventCount) {
	State tempIn1 = input1->getState();
	State tempIn2 = input2->getState();
	if (tempIn1 == HIGH || tempIn2 == HIGH) {
		if (out != LOW) {
			q.push_back(Event(output, currentTime + delay, LOW, eventCount + 1));
			eventCount++;
			out = LOW;
		}
	}
	else {
		if (out != HIGH) {
			q.push_back(Event(output, currentTime + delay, HIGH, eventCount + 1));
			eventCount++;
			out = HIGH;
		}
	}
}