/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: circuit.cpp
File Purpose: To define the circuit class
Date Started: April 6, 2017


*/

#include "circuit.h"
#include <fstream>
#include <iostream>



void Circuit::readCircuitDescription(string f){
	string filename = f + ".txt";
	ifstream inputFile;
	inputFile.open(filename);
	string input;
	while ( getline(inputFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		if (keyword == "CIRCUIT") {
			setName(input.substr(input.find(" "), input.length()));
		}
		else if (keyword == "INPUT") {
			//create an input
		}
		else if (keyword == "OUTPUT") {
			//create an output
		}
		else if (keyword == "AND") {
			//create a gate
		}
		else if (keyword == "NAND") {
			//create a gate
		}
		else if (keyword == "OR") {
			//create a gate
		}
		else if (keyword == "NOR") {
			//create a gate
		}
		else if (keyword == "XOR") {
			//create a gate
		}
		else if (keyword == "XNOR") {
			//create a gate
		}
		else if (keyword == "NOT") {
			//create a gate
		}
	}
}

void Circuit::readVectorFile(string f){
	string filename = f + "_v.txt";
}

void Circuit::simulate(){

}

void Circuit::outputTraces(){

}

void Circuit::setName(string n){
	name = n;
}
