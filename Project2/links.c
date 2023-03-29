/*
 *   File: links.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for link related functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * Receives a Network object and an array of tokens that contain
 * in this order (line name, start_stop name, end_stop name) and checks if
 * the information received is correct to create a new link
 * Returns 1 if operation was successful or returns an error code
*/
int check_link_args(Network *system, char **tokens) {
    int result, ids[3];
    int lineId = get_line_id(system, tokens[0]);
    int stop_startId = get_stop_id(system, tokens[1]);
    int stop_endId = get_stop_id(system, tokens[2]);
    double cost_dur[2];

    ids[0] = lineId, ids[1] = stop_startId, ids[2] = stop_endId;
    /* Get cost and duration */
    cost_dur[0] = atof(tokens[3]), cost_dur[1] = atof(tokens[4]);
    if (lineId == ERROR_CODE_INVALID_ID) {
        return ERROR_CODE_NO_LINE;
    } else if (stop_startId == ERROR_CODE_INVALID_ID) {
        return ERROR_CODE_NO_STOP_START;
    } else if (stop_endId == ERROR_CODE_INVALID_ID) {
        return ERROR_CODE_NO_STOP_END;
    } else if (cost_dur[0] < 0 || cost_dur[1] < 0) {
        return ERROR_CODE_ILLEGAL_VALUE;
    }
    result = add_link(system, ids, cost_dur);
    if (result == ERROR_CODE_OTHER)
        return ERROR_CODE_LINK;
    return true;
}

/*
 * Receives a Network object, the names in this order of
 * (line name, start_stop name, end_stop name) and an array that contains
 * the cost and duration.
 * The function decides where to add the link in system->links[]
*/
int add_link(Network *system, int *ids, double *cost_dur) {
    int i, curr_line, len = system->link_count;
    for (i = 0; i < len; i++) {
        curr_line = system->links[i].id_line;
        if (curr_line == ids[0]) {
            if (system->lines[curr_line].id_last == ids[1]) {
                add_link_aux(system, ids, cost_dur, true);
            } else if (system->lines[curr_line].id_first == ids[2]) {
                add_link_aux(system, ids, cost_dur, false);
            } else {
                return ERROR_CODE_OTHER;
            }
            return true;
        }
    }
    /* last case add link at the end (pos = true) */
    add_link_aux(system, ids, cost_dur, true);
    return true;
}

/*
 * Receives a Network object, names in this order
 * (line name, start_stop name, end_stop name), an array that contains the
 * cost and duration, and a pos flag that specifies if the link should be added
 * and the start or at the end of the links
*/
void add_link_aux(Network *system, int *ids, double *cost_dur, char pos) {
    int i = 0, *len = &(system->link_count);

    (*len)++;
    if (pos) {
        configure_link(system, ids, cost_dur, *len);
    } else {
        /* Loop until it finds the correct index */
        for (i = 0; i < *len && system->links[i].id_line != ids[0]; i++);
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

/*
 * Receives a Network object, an array of ids of (line, stop_start, stop_end)
 * an array that contains the cost and duration and the index of where to add
 * the new link in system->links[]
*/
void configure_link(Network *system, int *ids, double *cost_dur, int pos) {
    int *len = &(system->link_count);

    system->links[pos - 1].id_line = ids[0];
    system->links[pos - 1].id_start = ids[1];
    system->links[pos - 1].id_finish = ids[2];
    system->links[pos - 1].cost = cost_dur[0];
    system->links[pos - 1].duration = cost_dur[1];

    system->links = safe_realloc(system->links, (*len + 1)*sizeof(Link));
}

/*
 * Receives a Network object and the index of where to add a new link
 * and moves every element from system-links[pos] to the right by one index
 * This is used when a link needs to be added at the start
*/
void move_links(Network *system, int pos) {
    int len = system->link_count;

    memmove(
        &system->links[pos+1],
        &system->links[pos],
        (len-pos-1)*sizeof(Link)
    );
}
