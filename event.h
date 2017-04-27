/*
Project Name: Digital Logic Simulator (Term Project)
Contributors: Jacob Moore and Donald Shade
Date Started: April 6, 2017
File Name: event.h
File Purpose: To create a event class
Date Started: April 6, 2017


*/

#ifndef event_h
#define event_h
#include "wire.h"

#include <iostream>
using namespace std;

class Event{
public:

	Event(Wire* w=NULL, int t=0, State s=UND, int eventCount=0);
	
	Wire* getWire();
	int getTime() const ;
	State getState();
	int getEventCount();

private:
	int time;
    Wire* wire;
    State state;
    int eventCount;
    
};

#endif
