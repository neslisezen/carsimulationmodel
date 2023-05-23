/*! \file main.cpp
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
 * \version 2023-05-14(NS)
 * alle Variablen und Funktionen getrennt von main.cpp geschrieben

*/

#include"statemachine.cpp"

    int main()
    {
      //testVehicleSimulation();
        char driverInput;
        //initVehicle(1.,0.,10000.,500.);
        initVehicle();
            do{
                cout << "Ihre Eingabe:";
                cin >> driverInput;
                processEvent(driverInput);
                simulate();
                cout << getStateString() << endl;
              cout << getVehicleString()<<'\n'<<endl;
               }
            while (driverInput != 'e');
        return 0;


    }
