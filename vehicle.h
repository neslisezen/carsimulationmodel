#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <complex.h>
using namespace std;
/*
* Teammitglieder:
* Tim Roehrig(TR)
* Onur Guemues(OG)
* Neslihan Sezen(NS)
*/
struct Vehicle{

    double mass,dt=0.0, F_max=0.0;
    complex<double>F_akt,s, v ,a,v_mittel=0,v_alt=0.0;

};
void simulate(void);
void initVehicle(double dt_in,double s_in, double F_max_in, double mass_in);
void accel(void);
void decel (void);
void roll (void);
int getXPos(void);
int getYPos(void);
string to_string_with_precision( double number_in, int precision_in);
string getVehicleString(void);
int testVehicleSimulation(void);
//void initVehicle(void);




#endif // VEHICLE_H
