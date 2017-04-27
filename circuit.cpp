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

Circuit::Circuit() {//basic contructor
	name = "";
	eventCount = 0;
	wires[0] = Wire("NULL",0);
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
			//finds whats left
			string left = input.substr(input.find(' '));
			cleanString(left);//removes starting spaces
			string wireName = left.substr(0, left.find(' '));//finds the name
			left = left.substr(left.find(' '));//gets past the name
			cleanString(left);
			int wireNum = stoi(left);//gets the wire num

			wires[wireNum] = Wire(wireName, wireNum);//adds new wire
			inputWires[wireName] = &wires[wireNum];//adds a pointer to the new wire to inputWires

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
			//reads in the data
			parseForGate(input, in);
			//checks for the wires
			checkForWire(stoi(in[2]));
			checkForWire(stoi(in[3]));
			checkForWire(stoi(in[4]));
			//adds the gate
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
	//while there is more inputs it will create them
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
			//finds which wire it is so we can use the appropriate wirenum
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
			//push the event onto the vector
			eventsToCome.push_back(Event(&wires[wireNum], stoi(time), s, eventCount));
			eventCount++;
		}
	}
}

void Circuit::simulate() {
	int time;
	int max = 61;
	for (time = 0; time < max; time++) {
		for(int i = 0; i < eventsToCome.size(); i++){

			if(eventsToCome[i].getTime() == time) {
				Event e = eventsToCome[i];
				Wire* w = e.getWire();
				State s = e.getState();
				w->setState(s);
				history.push_back(e);
				eventsToCome.erase(eventsToCome.begin() + i);

				for (int i = 0; i < gates.size(); i++) {//checks for updates in each gate
					if (gates[i]->includesWire(w)) {
						gates[i]->checkForUpdate(eventsToCome, time, eventCount);
					}
				}
				i--;
			}
			if (eventsToCome.size() == 0) {//reduces max so we stop
				max = time + 1;
			}
		}
		for (std::map<int, Wire>::iterator i = wires.begin();i != wires.end();++i) {
			wires[i->first].updateHistory();//updates all the wires history
		}
	}
}

void Circuit::outputTraces(){
	cout << endl << "Cicuit: " << name << endl << "Wire Traces:" << endl;
	cout << "INPUTS:" << endl;
	for (std::map<string, Wire*>::iterator i = inputWires.begin(); i != inputWires.end(); i++) {//grabs the inputs
		Wire* w = i->second;
		string name = w->getName();
		while (name.length() < 8) {
			name += " ";
		}
		string history = w->getHistory();
		cout << name << ": " << history << endl;
	}
	cout << "OUTPUTS:" << endl;
	for (std::map<string, Wire*>::iterator i = outputWires.begin(); i != outputWires.end(); i++) {//grabs the outputs
		Wire* w = i->second;
		string name = w->getName();
		while (name.length() < 8) {
			name += " ";
		}
		string history = w->getHistory();
		cout << name << ": " << history<<endl;
	}
	string outputHelp = "          0    5    0    5    0    5    0    5    0    5    0    5    0";//helps for pretty printing
	outputHelp = outputHelp.substr(0, 10 + (wires[0].getHistory()).length());//makes it the right length
	cout << outputHelp <<endl
		;
	
}

void Circuit::setName(string n){
	name = n;
}

void Circuit::cleanString(string & s){//this function removes all the spaces from the beginning of a string
	while (s[0] == ' ') {
		s = s.substr(1);
	}
}


void Circuit::checkForWire(int s){//makes sure a wire exists before is is added elsewhere
	try {
		Wire test = wires.at(s);
	}
	catch (std::out_of_range) {
		wires[s] = Wire("Internal", s);
	}
}

void Circuit::parseForGate(string input, string* s){//puts read in material into the appropriate slots so the others can read it out
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
