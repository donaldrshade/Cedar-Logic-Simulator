/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: circuit.h
File Purpose: To create a circuit class that the main can use to provide easier editing
Date Started: April 6, 2017


*/

#ifndef circuit_h
#define circuit_h

#include <iostream>
#include <vector>
#include "advancedGates.h"


class Circuit{
public:
	Circuit();
	//main code functions
    void readCircuitDescription(string f);
    void readVectorFile(string f);
    void simulate();
    void outputTraces();
	//subfunctions
	void setName(string n);


private:
	string name;
	vector <Wire*> inputWires;
	vector <Wire*> outputWires;
	vector <Wire> wires;
	int numOfWires;
	int numOutputs;
	int numInputs;
	vector <Gate> gates;
	int numOfGates;
	std::priority_queue<Event> eventsToCome;
	std::priority_queue<Event> history;
	int eventCount;
};

#endif
