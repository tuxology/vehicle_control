#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "bus.h"

int get_bus() {
    return IMAGING_REAR_1;
}

int get_command(int bus) {
    switch (bus)
    {
        case ECU:
            return ENGINE_ON;
            break;
        case IMAGING_REAR_1:
            return get_imaging_command();

        default:
            return 999; /* Universal Err Code */ 
    }
}

int main(void) {
    // This is expected to come from command bus
    int control_bus = get_bus();
    int bus_comm = get_command(control_bus);

    char command_buff[12];

    // This can come from another separate non-firewalled bus
    char aux_command[12];
    
    // Obtain command strings for ECU. Input should check only for ECU commands
    char* buff = get_ecu_command(bus_comm, control_bus);

    // Copy is safe (only max length is allowed)
    memcpy(command_buff, buff, 12);

    // Maintenance mode check
    if (MAINTENANCE) {
        // Example input. In real cases, it could come from the IVI System/unprotected bus
        gets(aux_command);
    }

    // Aux command is allowed to be passed unsanitized
    submit_ecu_command(command_buff, aux_command);
    log_info("[CONTROL]: Commands Send to [ECU]");
}