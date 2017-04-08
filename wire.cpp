/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: wire.cpp
File Purpose: To define the wire class
Date Started: April 6, 2017


*/

#include "wire.h"
Wire::Wire(string n= ""){
    name = n;
    state = UND;
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
void Wire::setName(string n){
    name = n;
}
//future edit
