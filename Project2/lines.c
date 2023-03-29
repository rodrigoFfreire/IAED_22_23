/*
 *   File: lines.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for line related functions
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Receives a Network object and displays the names of all lines in system */
void list_all_lines(Network *system) {
    int i, j, line_len = system->line_count;
    int link_len = system->link_count;

    for (i = 0; i < line_len; i++) {
        printf("%s ",system->lines[i].name);
        for (j = 0; j < link_len; j++) {
            if (system->lines[i].id_first != -1 && 
                    system->lines[i].id_last != -1) {
                printf("%s %s ",
                    system->stops[system->lines[i].id_first].name,
                    system->stops[system->lines[i].id_last].name
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
 * Receives a Network object and the name of a line and returns the index
 * of system->lines[] that corresponds to the name of the line
*/
int get_line_id(Network *system, char *name) {
    int i, len = system->line_count;
    for (i = 0; i < len; i++) {
        if (!strcmp(system->lines[i].name, name)) {
            return i;
        }
    }
    return ERROR_CODE_INVALID_ID;
}


/*
 * Receives a Network object, the name of the line, and an invert flag
 * and checks if this line already exists and carries out the correct
 * action
*/
void check_line_exists(Network *system, char *name, int invert) {
    int i, line_len = system->line_count;

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
    int link_len = system->link_count;
    int j, last_stop = 0;
    int line_id = get_line_id(system, name);

    if (!invert && link_len > 0) {  /* Print in normal order */
        for (j = 0; j < link_len; j++) {
            if (line_id == system->links[j].id_line) {
                last_stop = j;
                printf("%s, ", system->stops[system->links[j].id_start].name);
            }
        }
        if (line_id == system->links[last_stop].id_line)
            printf("%s\n",
                    system->stops[system->links[last_stop].id_finish].name);
    } else if (link_len > 0) {  /* Print in reversed order */
        for (j = link_len - 1; j >= 0; j--) {
            if (line_id == system->links[j].id_line) {
                last_stop = j;
                printf("%s, ", system->stops[system->links[j].id_finish].name);
            }
        }
        if (line_id == system->links[last_stop].id_line)
            printf("%s\n",
                    system->stops[system->links[last_stop].id_start].name);
    }
}

/* Receives a Network object, and the name of the line and creates a new line*/
void create_line(Network *system, char *name) {
    int *len = &(system->line_count);
    short name_len = strlen(name) + 1;

    system->lines[*len].name = (char*)safe_calloc(name_len, sizeof(char));
    strcpy(system->lines[*len].name, name);
    system->lines[*len].total_cost = 0;
    system->lines[*len].total_duration = 0;
    system->lines[*len].n_stops = 0;
    system->lines[*len].id_first = system->lines[*len].id_last = -1;

    (*len)++;
    system->lines = safe_realloc(system->lines, (*len + 2)*sizeof(Line));
}

/*
 * Receives a Network object, an array of ids[3] and a init flag
 * that specifies if a line is being updated for the first time
 * and updates that line with a new link made by 2 stops
 * ids indeces:
 * 0 -> index of a line in the system->lines[]
 * 1, 2 -> indeces of stops (start, stop) in the system->stops[]
*/
void update_line(Network *system, int *ids, int init) {
    int i, count = 0, len = system->link_count;
    if (init) { /* Initialize line for the first time */
        system->lines[ids[0]].id_first = ids[1];
        system->lines[ids[0]].id_last = ids[2];
    }
    system->lines[ids[0]].total_cost = 0;
    system->lines[ids[0]].total_duration = 0;
    for (i = 0; i < len; i++) {
        if(system->links[i].id_line == ids[0]) {
            if (!count) {
                system->lines[ids[0]].id_first = system->links[i].id_start;
            } else {
                system->lines[ids[0]].id_last = system->links[i].id_finish;
            }
            count++;
            system->lines[ids[0]].total_cost += system->links[i].cost;
            system->lines[ids[0]].total_duration += system->links[i].duration;
        }
    }
    system->lines[ids[0]].n_stops = count + 1;  /* Each link has 2 stops */
}

int delete_line(Network *system, char *name) {
    int i, line_id = get_line_id(system, name);
    int links_count = 0, stops_len = 0;
    int* updated_stops = (int*) safe_calloc(1, sizeof(int));
    Link *new_links = (Link*) safe_calloc(1, sizeof(Link));

    if (line_id == ERROR_CODE_INVALID_ID)
        return ERROR_CODE_NO_LINE;
    for (i = 0; i < system->link_count; i++) {
        if (system->links[i].id_line != line_id) {
            new_links[links_count] = system->links[i];
            links_count++;
            new_links = safe_realloc(new_links, (links_count+1)*sizeof(Link));
        } else {
            updated_stops = add_to_filtered_array(updated_stops,
                system->links[i].id_start, &stops_len);
            updated_stops = add_to_filtered_array(updated_stops,
                system->links[i].id_finish, &stops_len);
        }
    }
    for (i = 0; i < stops_len; i++)
        system->stops[i].n_lines--;
    update_arrays(system, line_id, links_count, new_links);
    free(updated_stops);
    return SUCCESS;
}

void update_arrays(Network *system, int line_id, int new_count, Link *new) {
    int* len = &(system->line_count);

    free(system->lines[line_id].name);
    memmove(
        &(system->lines[line_id]),
        &(system->lines[line_id + 1]),
        ((*len)-line_id)*sizeof(Line)
    );
    system->lines = (Line*) safe_realloc(system->lines, (*len)*sizeof(Line));
    (*len)--;
    free(system->links);
    system->links = new, system->link_count = new_count;
}