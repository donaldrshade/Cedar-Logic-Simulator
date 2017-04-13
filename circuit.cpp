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



Circuit::Circuit(string n){
	name = n;
}

Circuit::Circuit(){
	name = "";
	numInputWires = 0;
	numOutputWires = 0;
}

void Circuit::readCircuitDescription(string f){
	string filename = f + ".txt";
	ifstream inputFile;
	inputFile.open(filename);
	string input;
	while ( getline(inputFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		if (keyword == "CIRCUIT") {
			setName(input.substr(input.find(' ')+1));
		}
		else if (keyword == "INPUT") {
			//create an input
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string wireName = left.substr(0, left.find(' '));
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			int wireNum = stoi(left);
			if (inputWires.size()==0) {
				inputWires.resize(1);
			}
			if (inputWires.size() == numInputWires) {
				inputWires.resize( inputWires.size()+1);
			}
			
			inputWires.insert(inputWires.begin()+ numInputWires, Wire(wireName,wireNum));
			numInputWires++;

		}
		else if (keyword == "OUTPUT") {
			//create an output
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string wireName = left.substr(0, left.find(' '));
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			int wireNum = stoi(left);
			if (outputWires.size() == 0) {
				outputWires.resize(1);
			}
			if (outputWires.size() == numOutputWires) {
				outputWires.resize(outputWires.size() + 1);
			}

			outputWires.insert(outputWires.begin() + numOutputWires, Wire(wireName, wireNum));
			numOutputWires++;

		}
		else if (keyword == "AND") {
			//create a gate
			/*
			int delay = stoi(input.substr(input.find("ns") - 1, 1);
			if (gates.size() == 0) {
				gates.resize(1);
			}
			if (gates.size() == numOfGates) {
				gates.resize(gates.size() + 1);
			}
			gates.insert(gates.begin()+numOfGates,And());
			*/
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
