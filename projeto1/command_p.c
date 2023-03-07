/*
 *   File: commands_p.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'p' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>



void list_all_stops(Network *system) {
    short i, *len = &(system->stop_count);

    for (i = 0; i < *len; i++) {
        printf("%s: %16.12f %16.12f %d\n",
            system->stops[i].name,
            system->stops[i].latitude,
            system->stops[i].longitude,
            system->stops[i].n_lines
        );
    }
}


int get_stop(Network *system, char name[], char print) {
    short i, *len = &(system->stop_count);

    for (i = 0; i < *len; i++) {
        if (!strcmp(name, system->stops[i].name)) {
            if (print)
                printf("%16.12f %16.12f\n",
                    system->stops[i].latitude,
                    system->stops[i].longitude
                );
            return 1;
        }
    }
    return 0;
}


int create_stop(Network *system, char name[], float lat, float lon) {
    short *len = &(system->stop_count);

    if (!get_stop(system, name, false)) {
        if (*len < MAX_STOPS) {
            *len += 1;
            strcpy(system->stops[*len - 1].name, name);
            system->stops[*len - 1].latitude = lat;
            system->stops[*len - 1].longitude = lon;
            system->stops[*len - 1].n_lines = 0;
        }
        return 1;
    } else {
        return 0;
    }
}