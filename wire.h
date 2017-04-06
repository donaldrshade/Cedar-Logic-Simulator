//
//  wire.hpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#ifndef wire_h
#define wire_h

#include <stdio.h>
#include <string>

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

#endif /* wire_h*/
