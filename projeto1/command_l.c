/*
 *   File: commands_l.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'l' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int create_link(Network *system, char **names, double *cost_dur) {
    short result, *len = &system->link_count;
    short lineId = get_line_id(system, names[0]);
    short stop_startId = get_stop_id(system, names[1]);
    short stop_endId = get_stop_id(system, names[2]);

    if (*len < MAX_LINKS) {
        if (lineId == -1) {
            return -1;
        } else if (stop_startId == -1) {
            return -2;
        } else if (stop_endId == -1) {
            return -3;
        } else if (cost_dur[0] < 0 || cost_dur[1] < 0) {
            return -5;
        }
        result = add_link(system, names, cost_dur);
        if (result == -1) {
            return -4;
        }
    }
    return 1;
}


int add_link(Network *system, char **names, double *cost_dur) {
    short i, *len = &(system->link_count);
    *len += 1;
    for (i = 0; i < *len; i++) {
        if (!strcmp(system->links[i].line->name, names[0])) {
            if (!strcmp(system->links[i].line->last->name, names[1])) {
                add_link_aux(system, names, cost_dur, true);
            } else if (!strcmp(system->links[i].line->first->name, names[2])) {
                add_link_aux(system, names, cost_dur, false);
            } else {
                return -1;
            }
            return 1;
        }
    }
    add_link_aux(system, names, cost_dur, true);
    return 1;
}


void add_link_aux(Network *system, char **names, double *cost_dur, char pos) {
    short i = 0, len = system->link_count;
    short ids[3];
    compact_ids(system, ids, names);

    if (strcmp(names[1], names[2])) {
        if (pos) {
            configure_link(system, ids, cost_dur, len);
        } else {
            while (i < len && strcmp(system->links[i].line->name,
                                    system->lines[ids[0]].name)) {
                i++;
            }
            move_links(system, i);
            configure_link(system, ids, cost_dur, i + 1);
        }
        if (!system->lines[ids[0]].n_stops) {
            update_line(system, ids, true);
        } else {
            update_line(system, ids, false);
        }
        update_stop(system, ids[1]);
        update_stop(system, ids[2]);
    }
}


short get_line_id(Network *system, char *name) {
    short i, len = system->line_count;
    for (i = 0; i < len; i++) {
        if (!strcmp(system->lines[i].name, name)) {
            return i;
        }
    }
    return -1;
}


short get_stop_id(Network *system, char *name) {
    short i, len = system->stop_count;
    for (i = 0; i < len; i++) {
        if (!strcmp(system->stops[i].name, name)) {
            return i;
        }
    }
    return -1;
}


void compact_ids(Network *system, short *ids, char **names) {
    short lineId = get_line_id(system, names[0]);
    short stop_startId = get_stop_id(system, names[1]);
    short stop_endId = get_stop_id(system, names[2]);
    ids[0] = lineId, ids[1] = stop_startId, ids[2] = stop_endId;
}


void configure_link(Network *system, short *ids, double *cost_dur, short pos) {
    system->links[pos - 1].line = &system->lines[ids[0]];
    system->links[pos - 1].start = &system->stops[ids[1]];
    system->links[pos - 1].end = &system->stops[ids[2]];
    system->links[pos - 1].cost = cost_dur[0];
    system->links[pos - 1].duration = cost_dur[1];
}


void move_links(Network *system, short pos) {
    short len = system->link_count;

    memmove(
        &system->links[pos+1],
        &system->links[pos],
        (len-pos-1)*sizeof(Link)
    );
}
