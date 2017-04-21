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
	eventCount = 0;
	wires[0] = Wire("NULL",0);
	inputWires["0"] = NULL;
	outputWires["0"] = NULL;
}

void Circuit::readCircuitDescription(string f) {
	string filename = f + ".txt";
	ifstream inputFile;
	inputFile.open(filename);
	string input;
	string* in =  new string[5];
	while (getline(inputFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		in[0] = keyword;
		if (keyword == "CIRCUIT") {
			string left = input.substr(input.find(' '));
			cleanString(left);
			setName(left);
		}
		else if (keyword == "INPUT") {
			//create an input
			string left = input.substr(input.find(' '));
			cleanString(left);
			string wireName = left.substr(0, left.find(' '));
			left = left.substr(left.find(' '));
			cleanString(left);
			int wireNum = stoi(left);

			wires[wireNum] = Wire(wireName, wireNum);
			inputWires[wireName] = &wires[wireNum];

		}
		else if (keyword == "OUTPUT") {
			//create an output
			string left = input.substr(input.find(' '));
			cleanString(left);
			string wireName = left.substr(0, left.find(' '));
			left = left.substr(left.find(' '));
			cleanString(left);
			int wireNum = stoi(left);

			wires[wireNum] = Wire(wireName, wireNum);
			outputWires[wireName] = &wires[wireNum];
		
		}
		else if (keyword == "AND") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(And(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "NAND") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(Nand(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "OR") {
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(Or(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "NOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(Nor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "XOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(Xor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "XNOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(Xnor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "NOT") {
			string left = input.substr(input.find(' '));
			cleanString(left);
			string delay = left.substr(0, left.find("ns"));
			int d = stoi(delay);
			left = left.substr(left.find(' '));
			cleanString(left);
			string input1, input2, output;
			input1 = left.substr(0, left.find(' '));
			left = left.substr(left.find(" "));
			cleanString(left);
			output = left.substr(0, left.find(' '));
			checkForWire(stoi(input1));
			checkForWire(stoi(output));
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
	int time;
	bool done = false;
	for (time = 0; time < 61&& !done; time++) {
		while ((eventsToCome.top()).getTime() == time) {
			Event e = eventsToCome.top();
			Wire* w = e.getWire();
			State s = e.getState();
			w->setState(s);
			history.push(e);
			eventsToCome.pop();
			for (std::vector<Gate>::iterator i = gates.begin();i != gates.end();i++) {
				i->checkForUpdate(eventsToCome, time, eventCount);
			}
		}
		for (std::map<int, Wire>::iterator i = wires.begin();i != wires.end();++i) {
			wires[i->first].updateHistory();
		}
		for (std::vector<Gate>::iterator i = gates.begin();i != gates.end();i++) {
			i->checkForUpdate(eventsToCome, time, eventCount);
		}
		if (eventsToCome.empty()) {
			done = true;
		}
	}
}

void Circuit::outputTraces(){

}

void Circuit::setName(string n){
	name = n;
}

void Circuit::cleanString(string & s){
	while (s[0] == ' ') {
		s = s.substr(1);
	}
}


void Circuit::checkForWire(int s){
	try {
		Wire test = wires.at(s);
	}
	catch (std::out_of_range) {
		wires[s] = Wire("Internal", s);
	}
}

void Circuit::parseForGate(string input, string* s){
	string left = input.substr(input.find(' '));
	cleanString(left);
	s[1] = left.substr(0, left.find("ns"));
	left = left.substr(left.find(' '));
	cleanString(left);
	s[2] = left.substr(0, left.find(' '));
	left = left.substr(left.find(" "));
	cleanString(left);
	s[3] = left.substr(0, left.find(' '));
	left = left.substr(left.find(" "));
	cleanString(left);
	s[4] = left.substr(0, left.find(' '));

}
