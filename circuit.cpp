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
		for (int i = 0; i < 5; i++) {
			in[i] = "";
		}
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
			gates.push_back(new And(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "NAND") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(new Nand(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "OR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(new Or(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "NOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(new Nor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "XOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(new Xor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
		}
		else if (keyword == "XNOR") {
			parseForGate(input, in);
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			gates.push_back(new Xnor(stoi(in[1]), &wires[stoi(in[2])], &wires[stoi(in[3])], &wires[stoi(in[4])]));
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
			gates.push_back(new Not(d, &wires[stoi(input1)], &wires[stoi(output)]));
		}
	}
	inputFile.close();
}

void Circuit::readVectorFile(string f) {
	string filename = f + "_v.txt";
	ifstream vectorFile;
	vectorFile.open(filename);
	string input;
	while (getline(vectorFile, input)) {
		string keyword = input.substr(0, input.find(" "));
		if (keyword == "INPUT") {
			string left = input.substr(input.find(' '));
			cleanString(left);
			string wireName = left.substr(0, left.find(" "));
			left = left.substr(left.find(' '));
			cleanString(left);
			string time = left.substr(0, left.find(" "));
			left = left.substr(left.find(' '));
			cleanString(left);
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
			eventsToCome.push_back(Event(&wires[wireNum], stoi(time), s, eventCount));
			eventCount++;
		}
	}
}

void Circuit::simulate() {
	int time;
	for (time = 0; time < 61; time++) {
		for(int i = 0; i < eventsToCome.size(); i++){

			if(eventsToCome[i].getTime() == time) {
				Event e = eventsToCome[i];
				Wire* w = e.getWire();
				State s = e.getState();
				w->setState(s);
				history.push_back(e);
				eventsToCome.erase(eventsToCome.begin() + i);
				for (int i = 0; i < gates.size(); i++) {
					if (gates[i]->includesWire(w)) {
						gates[i]->checkForUpdate(eventsToCome, time, eventCount);
					}
				}
				i--;
			}
		}
		for (std::map<int, Wire>::iterator i = wires.begin();i != wires.end();++i) {
			wires[i->first].updateHistory();
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
