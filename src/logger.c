#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "engine.h"

void log_info(char* log, char* log_num)
{
    FILE * fp = fopen ( "/tmp/ecu_log", "r" );
    fprintf (fp, "== BEGIN LOG ==");  /* Non-compliant */
    int log_number = atoi(log_num);
    fprintf (fp, log);
    fclose (fp);
}