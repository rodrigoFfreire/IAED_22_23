/*
 *   File: commands_p.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'p' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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


int create_stop(Network *system, char name[], double lat, double lon) {
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


int line_exists(unsigned char *line_ids, unsigned char id) {
    unsigned char i, len = line_ids[0];
    for (i = 1; i <= len; i++) {
        if (line_ids[i] == id) {
            return 1;
        }
    }
    return 0;
}

void update_stop(Network *system, short stop_id) {
    short i, len = system->link_count;
    short curr_line_id;
    unsigned char *line_ids = malloc(sizeof(unsigned char));
    line_ids[0] = 0;

    for (i = 0; i < len; i++) {
        if (!strcmp(system->links[i].start->name,
                    system->stops[stop_id].name) ||
            !strcmp(system->links[i].end->name,
                    system->stops[stop_id].name)) {
            curr_line_id = get_line_id(system, system->links[i].line->name);
            if (!line_exists(line_ids, curr_line_id)) {
                line_ids = realloc(
                    line_ids,
                    (line_ids[0] + 2)*sizeof(unsigned char)
                );
                line_ids[0]++;
                line_ids[line_ids[0]] = curr_line_id;
            }
        }
    }
    system->stops[stop_id].n_lines = line_ids[0];
    free(line_ids);
}