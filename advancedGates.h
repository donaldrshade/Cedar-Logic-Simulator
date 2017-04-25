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
	Not(int d, Wire* input, Wire* output);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class And:public Gate{
public:
	And(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class Or:public Gate{
public:
	Or(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class Xor:public Gate{
public:
	Xor(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class Nand :public Gate {
public:
	Nand(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class Nor :public Gate {
public:
	Nor(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};

class Xnor :public Gate {
public:
	Xnor(int d, Wire *in1, Wire *in2, Wire *out);
	void checkForUpdate(vector<Event>& q, int currentTime, int &eventCount);
};
#endif
