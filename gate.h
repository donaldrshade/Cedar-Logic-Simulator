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

#include <iostream>
#include "event.h"
#include "wire.h"

class Gate {
public:
    Gate(int d=0,Wire* in1=nullptr, Wire* in2=nullptr,Wire* out=nullptr);
	void setInput1(Wire *in);
	void setInput2(Wire *in);
    void setDelay(int d);
	void createEvent(priority_queue<Event> q, int currentTime);

    int getDelay();
    State getOutputState();
	State getInput1State();
	State getInput2State();

protected:
	virtual void setOutput() = 0;
	Wire *input1, *input2, *output;
    int delay;
};

#endif 
