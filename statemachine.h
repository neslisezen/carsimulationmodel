#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "vehicle.cpp"
/*
* Teammitglieder:
* Tim Roehrig(TR)
* Onur Guemues(OG)
* Neslihan Sezen(NS)
*/


enum vehicle_states {off_state, neutral_state, decel_state, accel_state};
string getStateString();
void processEvent(char driverInput);

#endif // STATEMACHINE_H
