#ifndef ENGINE_H
#define ENGINE_H

// maintenance mode is on
#define MAINTENANCE 1

enum comm {
    ENGINE_ON = 1,
    ENGINE_OFF = 2,
};

char* get_ecu_command(int, int);
void maintenance_mode(char*);
void submit_ecu_command(char[], char*);

#endif /* ENGINE_H */