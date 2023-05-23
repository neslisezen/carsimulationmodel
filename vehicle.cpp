/*! \file vehicle.cpp
 *
 * Teammitglieder:
 * Tim Roehrig(TR)
 * Onur Guemues(OG)
 * Neslihan Sezen(NS)
 *
 * Fahrzeugsimulation,c++P2a
 * \author Roehrig,Tim(TR)
 * \version 2023-05-11(TR)
 * Variablen angelegt und Funktionen geschrieben
 * \author Sezen, Neslihan(NS)
 * \version 2023-05-14(NS)
 * struct Vehicle, vehicle.cpp, vehichle.h und komplexe Zahlen hinzugefuegt
*/
#include "vehicle.h"

static Vehicle vehicle1;

    void initVehicle(double dt_in=1.,double s_in=0., double F_max_in=10000., double mass_in=500.){
        vehicle1.dt = dt_in;
        vehicle1.s = complex <double> ( s_in, 0.);
        vehicle1.F_max = F_max_in;
        vehicle1.mass = mass_in;
    }


    void simulate(void){

        vehicle1.a = vehicle1.F_akt / vehicle1.mass;
        vehicle1.v = vehicle1.v + vehicle1.a * vehicle1.dt;
        vehicle1.v_mittel = (vehicle1.v_alt + vehicle1.v) / 2.0;
        vehicle1.s +=  (vehicle1.v_mittel * vehicle1.dt);
        vehicle1.F_akt = complex <double>(0,0);
    }

    void accel(void){

        vehicle1.F_akt.real(vehicle1.F_max);
    }

    void decel (void){

    vehicle1.F_akt.real(-vehicle1.F_max);    }

    void up(void){
    vehicle1.F_akt.imag(vehicle1.F_max);

    }

    void down(void){

    vehicle1.F_akt.imag(-vehicle1.F_max);

    }

    void roll (void){

        vehicle1.F_akt = 0;
    }

    int getXPos(void);

    int getYPos(void);


    string to_string_with_precision( double number_in, int precision_in){

        std::stringstream sstr1;
        sstr1 << fixed << setprecision( precision_in) << number_in;
        return sstr1.str();
    }

    string to_string_with_precision( complex<double> number_in, int precision_in){

        std::stringstream sstr1;
        sstr1 << fixed << setprecision( precision_in) << number_in;
        return sstr1.str();
    }

    string getVehicleString(void){

        string  x = " |Strecke: " + to_string_with_precision(vehicle1.s,2);
                  x += " Fahrzeugdaten|Geschwindigkeit: " + to_string_with_precision(vehicle1.v,2);
                  x += " |Beschleunigung: " + to_string_with_precision(vehicle1.a,2);
                  x += " |Masse: " + to_string_with_precision(vehicle1.mass,2);
                  x += " |MaximalKraft: " + to_string_with_precision(vehicle1.F_max,2);
                  x += " |AktuelleKraft: " + to_string_with_precision(vehicle1.F_akt,2);
//                  x += " |Richtung     : " + to_string_with_precision(vehicle1.F_akt.imag(),2);
                  x += " |VergangeneZeit: " + to_string_with_precision(vehicle1.dt,2);
             return x;
    }

    int testVehicleSimulation(void){

        initVehicle(1.,0.,10000.,500.); //Param.: (dt, s, f, m)
        cout << getVehicleString()<<'\n'<<endl;// Ausgabe: s= 0, v= 0,  …

        accel();     // Effekt: F_akt= 10000
        simulate(); // …-> a= 20 ->…-> v= 20…-> s= 10
        up();
        cout << getVehicleString()<<'\n'<<endl;// Ausgabe: s= 10, …

        roll();   // Effekt: F_akt= 0
        simulate();  // …-> a= 0 ->…-> v=v_alt= 20
        up();
        cout << getVehicleString()<<'\n'<<endl;// Ausgabe: s= 30, v= 20,…

        decel();   // Effekt: F_akt= 0
        simulate();  // …-> a= 0 ->…-> v=v_alt= 20
        cout << getVehicleString()<<'\n'<<endl;// Ausgabe: s= 30, v= 20,…

        return 1;
    }
