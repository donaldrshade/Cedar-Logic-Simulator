/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: wire.h
File Purpose: To create a wire class
Date Started: April 6, 2017


*/

#ifndef wire_h
#define wire_h

#include <stdio.h>
#include <string>
using namespace std;

enum State {HIGH, UND, LOW};

class Wire{
    public:
        Wire(string n= "");
        State getState();
        void setState(State s);
        string getName();
        void setName(string n);
    private:
        string name;
        int index;
        State state;
    
};

#endif