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

/*
 * Receives a Network object, a stop name and a print flag
 * If found displays the stops coordinates
 * This function also determines if a stop with a certain name exists
 * print flag is used to silence output when checking if stop exists
 * Return Values:
 * 0 -> stop doesnt exist
 * 1 -> stop exists
*/
int get_stop(Network *system, char *name, char print) {
    short i, *len = &(system->stop_count);

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
 * Receives a Network object, a stop name and its coordinates and creates
 * a new stop in the system
*/
int create_stop(Network *system, char *name, double lat, double lon) {
    short *len = &(system->stop_count);

    if (!get_stop(system, name, false)) {
        if (*len < MAX_STOPS) {
            *len += 1;
            strcpy(system->stops[*len - 1].name, name);
            system->stops[*len - 1].latitude = lat;
            system->stops[*len - 1].longitude = lon;
            system->stops[*len - 1].n_lines = 0;
        }
        return true;
    } 
    return false;
}

/* Receives an array of indeces from system->lines[] and
 * and a single line id and checks if that id exists in the array
 * Return Values:
 * 0 -> Line if doesnt exist in array
 * 1 -> Line id exists in array
*/
int line_exists_in(unsigned char *line_ids, unsigned char id) {
    unsigned char i, len = line_ids[0];
    for (i = 1; i <= len; i++) {
        if (line_ids[i] == id) {
            return true;
        }
    }
    return false;
}

/* 
 * Receives a Network object and a stop_id that that equals the
 * index of that stop in the system->stops[] and updates it with new
 * information
*/
void update_stop(Network *system, short stop_id) {
    short i, len = system->link_count;
    short curr_line_id;
    char stop_id_name[STOP_NAME_MAX];
    /* Keeps track of all lines that intersect at the current stop */
    unsigned char line_ids[MAX_LINES + 1];

    strcpy(stop_id_name, system->stops[stop_id].name);
    line_ids[0] = 0; /* line_ids[0] keeps track of its length */
    for (i = 0; i < len; i++) {
        if (!strcmp(system->links[i].start->name, stop_id_name) ||
                !strcmp(system->links[i].end->name, stop_id_name)) {
            curr_line_id = get_line_id(system, system->links[i].line->name);
            if (!line_exists_in(line_ids, curr_line_id)) {
                line_ids[0] += 1;
                line_ids[line_ids[0]] = curr_line_id;
            }
        }
    }
    system->stops[stop_id].n_lines = line_ids[0];
}