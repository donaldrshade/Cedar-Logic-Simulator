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
#include "gate.h"
#include "wire.h"

class Circuit{
public:
	//main code functions
    void readCircuitDescription(string f);
    void readVectorFile(string f);
    void simulate();
    void outputTraces();
	//subfunctions
	void setName(string n);

private:
	string name;


};

#endif /* circuit_h */
