#include <stdio.h>
#include <string.h>
#include "engine.h"

// A debug binary is accidentally compiled which releases
// maintenance code

int main(void) {

    // This is expected to come from command bus
    enum comm bus_comm = ENGINE_ON;

    char command_buff[12];
    char aux_command[12];
    
    // Obtain command strings
    char* buff = get_ecu_command(bus_comm);

    // Command is sanitized (only max length is allowed)
    memcpy(command_buff, buff, 12);

    // Maintenance mode check
    if (MAINTENANCE) {
        // Example input. In real cases, it could come from the IVI System
        gets(aux_command);
    }

    // Aux command is allowed to be passed unsanitized
    submit_ecu_command(command_buff, aux_command);
    log_info("[CONTROL]: Commands Send to [ECU]");
}