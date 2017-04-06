//
//  wire.cpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#include "wire.h"
Wire:Wire(string n= ""){
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
