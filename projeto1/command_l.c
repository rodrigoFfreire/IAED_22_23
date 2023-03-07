/*
 *   File: commands_p.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'l' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>



int create_link(Network *system, char *names, double *cost_dur) {
    short i, *len = &(system->link_count);
    if (get_line_id(system, names[0]) == -1) {
        return -1;
    } else if (get_stop_id(system, names[1] == -1) ||
            get_stop_id(system, names[2] == -1)) {
        return -2;
    } else if (cost_dur[0] < 0 || cost_dur[1] < 0) {
        return -4;
    }

    for (i = 0; i < len; i++) {

    }

    return -3;
}


void add_link_end(Network *system, char *names, double *cost_dur, short pos) {
    short pos = system->link_count;
    short line_id = get_line_id(system, names[0]);
    short stop_start_id = get_stop_id(system, names[1]);
    short stop_end_id = get_stop_id(system, names[2]);
    short ids[3] = {line_id, stop_start_id, stop_end_id};

    configure_link(system, ids, cost_dur, pos);
}


void add_link_start(Network *system, char *names, double *cost_dur, short pos){
    short i, len = system->link_count;
    short line_id = get_line_id(system, names[0]);
    short stop_start_id = get_stop_id(system, names[1]);
    short stop_end_id = get_stop_id(system, names[2]);
    short ids[3] = {line_id, stop_start_id, stop_end_id};

    for (i = 0; i < len; i++) {
        if (!strcmp(system->links[i].line->name, system->lines[line_id].name)){
            break;
        }
    }

    configure_link(system, ids, cost_dur, i--);
}


short get_line_id(Network *system, char *name) {
    short i, *len = &(system->line_count);
    for (i = 0; i < len; i++) {
        if (!strcmp(system->lines[i].name, name)) {
            return i;
        }
    }
    return -1;
}


short get_stop_id(Network *system, char *name) {
    short i, *len = &(system->stop_count);
    for (i = 0; i < len; i++) {
        if (!strcmp(system->stops[i].name, name)) {
            return i;
        }
    }
    return -1;
}


void configure_link(Network *system, short *ids, double *cost_dur, short pos) {
    short *len = &(system->link_count);
    if (*len < MAX_LINKS) {
        *len += 1;
        system->links[pos].line = &(system->lines[ids[0]]);
        system->links[pos].start = &(system->stops[ids[1]]);
        system->links[pos].end = &(system->stops[ids[2]]);
        system->links[pos].cost = cost_dur[0];
        system->links[pos].duration = cost_dur[1];
    }
}