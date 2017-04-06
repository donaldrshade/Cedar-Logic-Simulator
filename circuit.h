//
//  circuit.hpp
//  HW6-Term Project
//
//  Created by Donald Shade on 4/6/17.
//
//

#ifndef circuit_h
#define circuit_h

#include <stdio.h>
#include "gate.h"
#include "wire.h"

Class Circuit(){
public:
    void readCircuitDescription();
    void readVectorFile();
    void simulate();
    void outputTraces();
private:

}

#endif /* circuit_h */
