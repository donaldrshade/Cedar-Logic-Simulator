//
//  main.cpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#include <stdio.h>
int main(){
    Circuit c;
    //1. parse the input file
    c.readCircuitDescription();
    //2. parse the vector file
    c.readVectorFile();
    //3. simulate the circuit
    c.simulate();
    //4. output the traces
    c.outputTraces();
}
