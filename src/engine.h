#ifndef ENGINE_H
#define ENGINE_H

// maintainence mode is on
#define MAINTAINENCE 1

enum comm {
    ENGINE_ON = 1,
    ENGINE_OFF = 2,
};

char* get_ecu_command(int);
void maintainence_mode(char*);
void submit_ecu_command(char[], char*);

#endif /* ENGINE_H */