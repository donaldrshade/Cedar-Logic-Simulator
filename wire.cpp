/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: wire.cpp
File Purpose: To define the wire class
Date Started: April 6, 2017


*/

#include "wire.h"
Wire::Wire(string n,int num){
    name = n;
	wireNumber = num;
    state = UND;
	history = "";
}
State Wire::getState(){
    return state;
}
void Wire::setState(State s){
    state = s;
}
string Wire::getName(){
    return name;
}
void Wire::updateHistory(){
	if (state == HIGH) {
		history += "-";
	}
	else if (state == LOW) {
		history += "_";
	}
	else {
		history += "X";
	}
}
string Wire::getHistory(){
	return history;
}
void Wire::setName(string n){
    name = n;
}
//future edit
