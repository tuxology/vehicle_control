#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "bus.h"

typedef unsigned int UINT;

char* get_ecu_command(int bus_comm, int control_bus) {

    if (control_bus == ECU) {
        switch (bus_comm)
        {
            case ENGINE_OFF:
                return "SET_ENG_OFF";
                break;

            case ENGINE_ON:
                return "SET_ENG_ON";
                break;
        
            default:
                break;
        }
    }

    else {
        return "SET_ENGINE_OFF";
    }
}

void maintenance_mode(char* aux_buf) {
    // Run command set in aux mode which is unverified
}

void submit_ecu_command(char buff[12], char* aux_buff) {
        if(strcmp(buff, "SET_ENGINE_OFF")) {
            // run engine shutdown routine
        }
        if(strcmp(buff, "SET_ENGINE_ON")) {
            // run engine shutdown routine
        }
        else {
            if (MAINTENANCE) {
                maintenance_mode(aux_buff);
            }
        }
}