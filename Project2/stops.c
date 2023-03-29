/*
 *   File: stops.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for stop related functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 
 * Receives a Network object and displays information
 * about all stops stored in system
*/
void list_all_stops(Network *system) {
    int i, *len = &(system->stop_count);

    for (i = 0; i < *len; i++) {
        printf("%s: %16.12f %16.12f %d\n",
            system->stops[i].name,
            system->stops[i].latitude,
            system->stops[i].longitude,
            system->stops[i].n_lines
        );
    }
}

/*
 * Receives a Network object, a stop name and a print flag
 * If found, displays the stops coordinates
 * This function also determines if a stop with a certain name exists.
 * print flag is used to silence output when checking if stop exists
 * Return Values:
 * 0 -> stop doesnt exist
 * 1 -> stop exists
*/
int check_stop_exists(Network *system, char *name, char print) {
    int i, *len = &(system->stop_count);

    for (i = 0; i < *len; i++) {
        if (!strcmp(name, system->stops[i].name)) {
            if (print)
                printf("%16.12f %16.12f\n",
                    system->stops[i].latitude,
                    system->stops[i].longitude
                );
            return true;
        }
    }
    return false;
}

/* 
 * Receives a Network object and the name of a stop and returns the index
 * of system->stop[] that corresponds to the name of the stop
*/
int get_stop_id(Network *system, char *name) {
    int i, len = system->stop_count;
    for (i = 0; i < len; i++) {
        if (!strcmp(system->stops[i].name, name)) {
            return i;
        }
    }
    return ERROR_CODE_INVALID_ID;
}

/* 
 * Receives a Network object, a stop name and its coordinates and creates
 * a new stop in the system
*/
int create_stop(Network *system, char *name, double lat, double lon) {
    int *len = &(system->stop_count);
    short name_len = strlen(name) + 1;

    if (!check_stop_exists(system, name, false)) {
        system->stops[*len].name = (char*)safe_calloc(name_len, sizeof(char));
        strcpy(system->stops[*len].name, name);
        system->stops[*len].latitude = lat;
        system->stops[*len].longitude = lon;
        system->stops[*len].n_lines = 0;

        (*len)++;
        system->stops = safe_realloc(system->stops, (*len + 1)*sizeof(Stop));
        return true;
    } 
    return false;
}

/* 
 * Receives a Network object and a stop_id that that equals the
 * index of that stop in the system->stops[] and updates it with new
 * information
*/
void update_stop(Network *system, int stop_id) {
    int i, array_len = 0, link_len = system->link_count;
    int curr_line_id;
    int* line_ids = (int*) safe_calloc(1, sizeof(int));

    for (i = 0; i < link_len; i++) {
        if (system->links[i].id_start == stop_id ||
                system->links[i].id_finish == stop_id) {
            curr_line_id = system->links[i].id_line;
            /* Filter duplicate values */
            line_ids = add_to_filtered_array(line_ids, curr_line_id, &array_len);
        }
    }
    system->stops[stop_id].n_lines = array_len;
    free(line_ids);
}