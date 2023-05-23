/*! \file stateMaschine.cpp
 *
 * Teammitglieder:
 * Tim Roehrig(TR)
 * Onur Guemues(OG)
 * Neslihan Sezen(NS)
 *
 * State-machine,c++ P2b-1 & P2b-2
 * \author Guemues,Onur(OG)
 * \version 2023-05-14(OG)
 * Zustandsautomat mit Timer programmiert
 * \author Sezen,Neslihan(NS)
 * \version 2023-05-16(NS)
 * alle Variablen und Funktionen getrennt von main.cpp geschrieben
 * default Option für getStateString Funktion hinzugefuegt
 * accel() deccel() simulate() Funktionen hinzugefuegt
*/
#include "statemachine.h"


static vehicle_states state = off_state;
static int timer1 = 0;
static const int timeout1 = 3;

string getStateString(){
    switch(state){
        case 0:{
        return "off_state";

        }
        case 1:{
        return "neutral_state";

        }
        case 2:{
        return "decel_state";

        }
        case 3:{
        return "accel_state";

        }
        default :
        return "off_state"; //(NS)
    }

}


void processEvent(char driverInput){
    switch (state){
        case off_state:{

            if(driverInput=='b'){
                state = neutral_state;

                }

            else if(driverInput=='t'){
                    timer1++;
                    if(timer1 >= timeout1){
                        state = neutral_state;

                    }

                }

        break;
        }

        case neutral_state:{


            if(driverInput=='d'){
                    down();

            }
            if(driverInput=='u'){
                    up();

            }
            if(driverInput=='r'){
                state = decel_state;
                decel();

            }

            if(driverInput=='a'){
                state = accel_state;
                accel();

            }
            if(driverInput=='e'){
                state = off_state;
            }
            break;
            }


        case decel_state:{

            if(driverInput=='r'){
            decel();

            }

            if(driverInput=='d'){
                down();

            }
            if(driverInput=='u'){
                up();

            }
            if(driverInput=='0'){
                state = neutral_state;
                roll();

            }
            if(driverInput=='e'){
                state = off_state;
            }
            break;
            }

        case accel_state:{

            if(driverInput=='a'){
            accel();
            }
            if(driverInput=='d'){
                down();
            }
            if(driverInput=='u'){
                up();
            }
            if(driverInput=='0'){
                state = neutral_state;
                roll();
            }
            if(driverInput=='e'){
                state = off_state;
            }
            break;
            }
        }
}
