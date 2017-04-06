//
//  event.hpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#ifndef event_h
#define event_h
#incl

#include <stdio.h>

class Event(){
public:
    Event(Wire* w,int t, State s, int eventCount)
private:
    Wire* wire;
    int t;
    State state;
    int eventCount;
    
};

#endif /* event_h */
