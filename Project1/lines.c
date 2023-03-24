/*
 *   File: lines.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for line related functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>


/* Receives a Network object and displays the names of all lines in system */
void list_all_lines(Network *system) {
    short i, j, line_len = system->line_count;
    short link_len = system->link_count;

    for (i = 0; i < line_len; i++) {
        printf("%s ",system->lines[i].name);
        for (j = 0; j < link_len; j++) {
            if (!strcmp(system->lines[i].name, system->links[j].line->name)) {
                printf("%s %s ",
                    system->lines[i].first->name,
                    system->lines[i].last->name
                );
                break;
            }
        }
        printf("%d %.2f %.2f\n",
            system->lines[i].n_stops,
            system->lines[i].total_cost,
            system->lines[i].total_duration
        );
    }
}

/*
 * Receives a Network object, the name of the line, and an invert flag
 * and checks if this line already exists and carries out the correct
 * action
*/
void check_line_exists(Network *system, char *name, int invert) {
    short i, line_len = system->line_count;

    for (i = 0; i < line_len; i++) {
        if (!strcmp(name, system->lines[i].name)) {
            list_stops(system, name, invert);
            return;
        }
    }
    if (!invert)
        create_line(system, name);
}

/* 
 * Receives a Network object, the name of the line and an invert flag
 * and lists in the according order (invert = true || false) the stops
 * that belong to the line
*/
void list_stops(Network *system, char *name, int invert) {
    short link_len = system->link_count;
    short j, last_stop = 0;

    if (!invert && link_len > 0) {  /* Print in normal order */
        for (j = 0; j < link_len; j++) {
            if (!strcmp(name, system->links[j].line->name)) {
                last_stop = j;
                printf("%s, ", system->links[j].start->name);
            }
        }
        if (!strcmp(name, system->links[last_stop].line->name)) {
            printf("%s\n", system->links[last_stop].end->name);
        }
    } else if (link_len > 0) {  /* Print in reversed order */
        for (j = link_len - 1; j >= 0; j--) {
            if (!strcmp(name, system->links[j].line->name)) {
                last_stop = j;
                printf("%s, ", system->links[j].end->name);
            }
        }
        if (!strcmp(name, system->links[last_stop].line->name)) {
            printf("%s\n", system->links[last_stop].start->name);
        }
    }
}

/* Receives a Network object, and the name of the line and creates a new line */
void create_line(Network *system, char *name) {
    short *len = &(system->line_count);

    if (*len < MAX_LINES) { /* Overflow protection */
        *len += 1;
        strcpy(system->lines[*len - 1].name, name);
        system->lines[*len - 1].n_stops = 0;
        system->lines[*len - 1].total_cost = 0;
        system->lines[*len - 1].total_duration = 0;
    }
}

/*
 * Receives a Network object, an array of ids[3] and a init flag
 * that specifies if a line is being updated for the first time
 * and updates that line with a new link made by 2 stops
 * ids indeces:
 * 0 -> index of a line in the system->lines[]
 * 1, 2 -> indeces of stops (start, stop) in the system->stops[]
*/
void update_line(Network *system, short *ids, int init) {
    short i, count = 0, len = system->link_count;
    if (init) { /* Initialize line for the first time */
        system->lines[ids[0]].first = &system->stops[ids[1]];
        system->lines[ids[0]].last = &system->stops[ids[2]];
    }
    system->lines[ids[0]].total_cost = 0;
    system->lines[ids[0]].total_duration = 0;
    for (i = 0; i < len; i++) {
        if(!strcmp(system->links[i].line->name, system->lines[ids[0]].name)) {
            if (!count) {
                system->lines[ids[0]].first = system->links[i].start;
            } else {
                system->lines[ids[0]].last = system->links[i].end;
            }
            count++;
            system->lines[ids[0]].total_cost += system->links[i].cost;
            system->lines[ids[0]].total_duration += system->links[i].duration;
        }
    }
    system->lines[ids[0]].n_stops = ++count;  /* Each link has 2 stops */
}
