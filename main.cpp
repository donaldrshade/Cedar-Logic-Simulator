/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: main.cpp
File Purpose: To run the program 
Date Started: April 6, 2017


*/

#include <stdio.h>
#include "circuit.h"

int main() {
	string filename;
	cout << "What file would you like to read from?(Filename only. No .txt or _v.txt.) ";
	cin >> filename;

	Circuit c;
	//1. parse the input file
	c.readCircuitDescription(filename);
	//2. parse the vector file
	c.readVectorFile(filename);
	//3. simulate the circuit
	c.simulate();
	//4. output the traces
	c.outputTraces();
	string wait;
	cout << "Press enter to continue...";
	cin >> wait;
	return 0;
}
