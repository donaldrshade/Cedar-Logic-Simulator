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

Circuit::Circuit() {
	name = "";
	eventCount = 1;
	wires[0] = Wire("NULL",0);
	inputWires["0"] = NULL;
	outputWires["0"] = NULL;
}

void Circuit::readCircuitDescription(string f) {
	string filename = f + ".txt";
	ifstream inputFile;
	inputFile.open(filename);
	string input;
	while (getline(inputFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		if (keyword == "CIRCUIT") {
			string left = input.substr(input.find(' '));
			while (left[0] == ' ') {
				left = left.substr(1);
			}
			setName(left);
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

			wires[wireNum] = Wire(wireName, wireNum);
			inputWires[wireName] = &wires[wireNum];
			
			

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

			wires[wireNum] = Wire(wireName, wireNum);
			outputWires[wireName] = &wires[wireNum];
		
		}
		else if (keyword == "AND") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2,output;
			input1 = left.substr(0,left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0,left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			/*try {
				Wire test = wires.at(stoi(input1));
			}
			catch(std::out_of_range){
				wires[stoi(input1)] = Wire("Internal", stoi(input1));
			}
			try {
				Wire test = wires.at(stoi(input2));
			}
			catch (std::out_of_range) {
				wires[stoi(input2)] = Wire("Internal", stoi(input2));
			}
			try {
				Wire test = wires.at(stoi(output));
			}
			catch (std::out_of_range) {
				wires[stoi(output)] = Wire("Internal", stoi(output));
			}*/
			gates.push_back(And(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "NAND") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			gates.push_back(Nand(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "OR") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			gates.push_back(Or(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "NOR") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			gates.push_back(Nor(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "XOR") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			gates.push_back(Nor(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "XNOR") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			input2 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			gates.push_back(Xnor(d, &wires[stoi(input1)], &wires[stoi(input2)], &wires[stoi(output)]));
		}
		else if (keyword == "NOT") {
			string left = input.substr(input.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			while (left.find(' ') == 0) {
				left = left.substr(1);
			}
			output = left.substr(0, left.find(' '));
			try {
				Wire test = wires.at(stoi(input1));
			}
			catch (std::out_of_range) {
				wires[stoi(input1)] = Wire("Internal", stoi(input1));
			}
			try {
				Wire test = wires.at(stoi(output));
			}
			catch (std::out_of_range) {
				wires[stoi(output)] = Wire("Internal", stoi(output));
			}
			gates.push_back(Not(d, &wires[stoi(input1)],&wires[stoi(output)]));
		}
	}
	inputFile.close();
}

void Circuit::readVectorFile(string f){
	string filename = f + "_v.txt";
	ifstream vectorFile;
	vectorFile.open(filename);
	string input;
	while (getline(vectorFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		if (keyword == "INPUT") {
			string left = input.substr(input.find(' '));
			while (left[0] == ' ') {
				left = left.substr(1);
			}
			string wireName = left.substr(0, left.find(" "));
			left = left.substr(left.find(' '));
			while (left[0] == ' ') {
				left = left.substr(1);
			}
			string time = left.substr(0, left.find(" "));
			left = left.substr(left.find(' '));
			while (left[0] == ' ') {
				left = left.substr(1);
			}
			string state = left.substr(0, left.find(" "));
			int wireNum = 0;
			while (wires[wireNum].getName() != wireName) {
				wireNum++;
			}
			State s = UND;
			if (state == "0") {
				s = LOW;
			}
			if (state == "1") {
				s = HIGH;
			}
			eventsToCome.push(Event(&wires[wireNum], stoi(time), s, eventCount));
			eventCount++;
		}
	}
}

void Circuit::simulate(){

}

void Circuit::outputTraces(){

}

void Circuit::setName(string n){
	name = n;
}
