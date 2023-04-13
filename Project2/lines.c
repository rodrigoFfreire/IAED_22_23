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
void list_all_lines(Network* system) {
    int i, j, line_len = system->line_count;
    int link_len = system->link_count;

    for (i = 0; i < line_len; i++) {
        printf("%s ",system->lines[i].name);
        for (j = 0; j < link_len; j++) {
            if (system->lines[i].id_first > -1 &&
                    system->lines[i].id_last > -1) {
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
int get_line_id(Network* system, char* name) {
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
void check_line_exists(Network* system, char* name, int invert) {
    int line_id = get_line_id(system, name);

    if (line_id == ERROR_CODE_INVALID_ID) {
        if (!invert)
            create_line(system, name);
    } else {
        list_stops(system, line_id, invert);
    }
}

/*
 * Receives a Network object, the name of the line and an invert flag
 * and lists in the according order (invert = true || false) the stops
 * that belong to the line
*/
void list_stops(Network* system, int line_id, int invert) {
    int link_len = system->link_count;
    int j, last_stop = 0;

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
void create_line(Network* system, char* name) {
    int* len = &(system->line_count);
    short name_len = strlen(name) + 1;

    system->lines[*len].name = (char*)safe_calloc(name_len, sizeof(char));
    strcpy(system->lines[*len].name, name);
    system->lines[*len].total_cost = 0;
    system->lines[*len].total_duration = 0;
    system->lines[*len].n_stops = 0;
    system->lines[*len].id_first = system->lines[*len].id_last = -1;

    (*len)++;
    system->lines = (Line*) safe_realloc(system->lines,
        (*len + 2)*sizeof(Line));
}

/*
 * Receives a Network object, and an array of ids[3]
 * and updates that line with a new link made by 2 stops
 * ids indeces:
 * 0 -> index of a line in the system->lines[]
 * 1, 2 -> indeces of stops (start, stop) in the system->stops[]
*/
void update_line(Network* system, int* ids) {
    int i, count = 0, len = system->link_count;

    system->lines[ids[0]].total_cost = 0;
    system->lines[ids[0]].total_duration = 0;
    for (i = 0; i < len; i++) {
        if(system->links[i].id_line == ids[0]) {
            if (!count)
                system->lines[ids[0]].id_first = system->links[i].id_start;
            system->lines[ids[0]].id_last = system->links[i].id_finish;

            count++;
            system->lines[ids[0]].total_cost += system->links[i].cost;
            system->lines[ids[0]].total_duration += system->links[i].duration;
        }
    }
    if (count > 0) {
        system->lines[ids[0]].n_stops = count + 1;
    } else {
        system->lines[ids[0]].n_stops = 0;
        system->lines[ids[0]].id_first = system->lines[ids[0]].id_last = -1;
    }
}

/* Receives a Network object and a line name and deletes that line */
int delete_line(Network* system, char* name) {
    int i, line_id = get_line_id(system, name);
    int links_count = 0, stops_len = 0;
    int* updated_stops = (int*) safe_calloc(1, sizeof(int));
    Link* new_links = (Link*) safe_calloc(1, sizeof(Link));

    if (line_id == ERROR_CODE_INVALID_ID) {
        free(updated_stops), free(new_links);
        return ERROR_CODE_NO_LINE;
    }
    for (i = 0; i < system->link_count; i++) {
        if (system->links[i].id_line != line_id) {
            new_links[links_count++] = system->links[i];
            new_links = safe_realloc(new_links, (links_count+1)*sizeof(Link));
        } else {
            updated_stops = add_to_filtered_array(updated_stops,
                system->links[i].id_start, &stops_len);
            updated_stops = add_to_filtered_array(updated_stops,
                system->links[i].id_finish, &stops_len);
        }
    }
    /* Update stop information */
    for (i = 0; i < stops_len; i++)
        system->stops[updated_stops[i]].n_lines--;
    update_arrays_line(system, line_id, new_links, links_count);
    free(updated_stops);
    return true;
}

/*
 * Receives a Network object the id of the line that is being deleted
 * the new Link array and its length.
 * The function shifts the elements of the lines array after 'l_id' to
 * the left, updates the id values after the shift and frees memory
*/
void update_arrays_line(Network* system, int l_id, Link* new, int new_count) {
    int i, *line_len = &(system->line_count);
    int* link_len = &(system->link_count);

    free(system->lines[l_id].name);
    memmove(
        &(system->lines[l_id]),
        &(system->lines[l_id + 1]),
        ((*line_len)-l_id)*sizeof(Line)
    );
    system->lines = (Line*)safe_realloc(system->lines, *line_len*sizeof(Line));
    (*line_len)--;
    free(system->links);
    system->links = new, system->link_count = new_count;

    for (i = 0; i < *link_len; i++)
        if (system->links[i].id_line > l_id) system->links[i].id_line--;
}