/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: advancedGates.h
File Purpose: To create derived classes from gate which will have the functionality for the simulator
Date Started: April 6, 2017


*/

#ifndef advancedGates_h
#define advancedGates_h

#include <iostream>
#include "gate.h"

class Not:public Gate{
public:
	Not(Wire* input = nullptr, Wire* output = nullptr);
	void setOutput(Wire* in);};

class And:public Gate{
public:
	And(Wire *in1 = nullptr, Wire *in2 = nullptr, Wire *out = nullptr);
	void setOutput(Wire * in1, Wire * in2);
};

class Or:public Gate{
public:
	Or(Wire *in1 = nullptr, Wire *in2 = nullptr, Wire *out = nullptr);
	void setOutput(Wire *in1, Wire *in2);
};

class Xor:public Gate{
public:
	Xor(Wire *in1 = nullptr, Wire *in2 = nullptr, Wire *out = nullptr);
	void setOutput(Wire *in1, Wire *in2);
};

#endif
