/*
 *   File: commands_c.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'c' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>



void list_all_lines(Network *system) {
    short i, j, line_len = system->line_count;
    short connect_len = system->link_count;

    for (i = 0; i < line_len; i++) {
        printf("%s ",system->lines[i].name);
        for (j = 0; j < connect_len; j++) {
            if (!strcmp(system->lines[i].name,
                        system->links[j].line->name)) {
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


int create_line_list_stops(Network *system, char *name, int invert, int arg2) {
    short i;
    short *line_len = &(system->line_count);
    short link_len = system->link_count;

    if (arg2 && !invert) {
        return 0;
    } else {
        for (i = 0; i < *line_len; i++) {
            if (!strcmp(name, system->lines[i].name)) {
                list_stops(system, name, invert, link_len);
                return 1;
            }
        }
        create_line(system, name, line_len);
    }
    return 1;
}


void list_stops(Network *system, char name[], int invert, short len) {
    short j, last_stop = 0;
    if (!invert && len > 0) {
        for (j = 0; j < len; j++) {
            if (!strcmp(name, system->links[j].line->name)) {
                last_stop = j;
                printf("%s, ", system->links[j].start->name);
            }
        }
        if (!strcmp(name, system->links[last_stop].line->name)) {
            printf("%s\n", system->links[last_stop].end->name);
        }
    } else if (len > 0) {
        for (j = len - 1; j >= 0; j--) {
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


void create_line(Network *system, char name[], short *len) {
    if (*len < MAX_LINES) {
        *len += 1;
        strcpy(system->lines[*len - 1].name, name);
        system->lines[*len - 1].n_stops = 0;
        system->lines[*len - 1].total_cost = 0;
        system->lines[*len - 1].total_duration = 0;
    }
}


void update_line(Network *system, short *ids, char init) {
    short i, count = 0, len = system->link_count;
    char first[STOP_NAME_MAX_SIZE], last[STOP_NAME_MAX_SIZE];

    if (init) {
        system->lines[ids[0]].first = &system->stops[ids[1]];
        system->lines[ids[0]].last = &system->stops[ids[2]];
    }
    system->lines[ids[0]].total_cost = 0;
    system->lines[ids[0]].total_duration = 0;
    for (i = 0; i < len; i++) {
        if(!strcmp(system->links[i].line->name, system->lines[ids[0]].name)) {
            if (!count) {
                system->lines[ids[0]].first = system->links[i].start;
                strcpy(first, system->lines[ids[0]].first->name);
            } else {
                system->lines[ids[0]].last = system->links[i].end;
                strcpy(last, system->lines[ids[0]].last->name);
            }
            count++;
            system->lines[ids[0]].total_cost += system->links[i].cost;
            system->lines[ids[0]].total_duration += system->links[i].duration;
        }
    }
    system->lines[ids[0]].n_stops = count + 1;	/* Each link has 2 stops */
}
