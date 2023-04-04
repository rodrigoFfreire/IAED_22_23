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
            line_ids = add_to_filtered_array(line_ids,curr_line_id,&array_len);
        }
    }
    system->stops[stop_id].n_lines = array_len;
    free(line_ids);
}

int delete_stop(Network *system, char *name) {
    int i, stop_id = get_stop_id(system, name);
    int ids[3] = {0};
    int* updated_lines = (int*) safe_calloc(1, sizeof(int)), lines_len = 0;
    int* updated_stops = (int*) safe_calloc(1, sizeof(int)), stops_len = 0;

    if (stop_id == ERROR_CODE_INVALID_ID) {
        free(updated_lines), free(updated_stops);
        return ERROR_CODE_NO_STOP;
    }
    build_new_links(system, stop_id, &updated_stops, &stops_len, &updated_lines,
        &lines_len);

    for (i = 0; i < lines_len; i++) {
        ids[0] = updated_lines[i];
        update_line(system, ids);
    }
    for (i = 0; i < stops_len; i++)
        update_stop(system, updated_stops[i]);
    free(updated_lines), free(updated_stops);
    return true;
}

void build_new_links(Network *system, int stop_id, int** updated_stops, 
                        int* stops_len, int** updated_lines, int* lines_len) {
    int i, link_len = system->link_count;
    int new_links_count = 0, link_i = 0, link_i_n = 0;
    Link* new_links = (Link*) safe_calloc(1, sizeof(Link));

    for (i = 0; i < link_len; i++) {
        link_i_n = system->lines[system->links[i].id_line].n_stops - 2;
        if (link_i > 0 && i > 0 &&
            system->links[i].id_line != system->links[i - 1].id_line) {
            link_i = 0;
        }
        if (system->links[i].id_start != stop_id &&
                system->links[i].id_finish != stop_id) {
            new_links[new_links_count++] = system->links[i];
            new_links = safe_realloc(new_links,
                (new_links_count+1)*sizeof(Link));
        } else {
            if (link_i_n - link_i <= 1)
                *updated_stops = update_stop_last(system, *updated_stops,
                    stops_len, stop_id, i);
            skip_over_link(system, &i, &link_i, link_i_n,
                            &new_links, &new_links_count, stop_id);
            *updated_lines = add_to_filtered_array(*updated_lines,
                system->links[i].id_line, lines_len);
        }
        link_i++;
    }
    update_arrays_stop(system, stop_id, new_links_count, new_links);
}


void update_arrays_stop(Network *system, int id, int new_count, Link *new) {
    int i;
    int* len = &(system->stop_count);
    int *link_len = &(system->link_count), *line_len = &(system->line_count);

    free(system->stops[id].name);
    memmove(
        &(system->stops[id]),
        &(system->stops[id + 1]),
        ((*len)-id)*sizeof(Stop)
    );
    system->stops = (Stop*) safe_realloc(system->stops, (*len)*sizeof(Stop));
    (*len)--;
    free(system->links);
    system->links = new, system->link_count = new_count;

    for (i = 0; i < *link_len; i++) {
        if (system->links[i].id_start > id) system->links[i].id_start--;
        if (system->links[i].id_finish > id) system->links[i].id_finish--;
    }
    for (i = 0; i < *line_len; i++) {
        if (system->lines[i].id_first > id) system->lines[i].id_first--;
        if (system->lines[i].id_last > id) system->lines[i].id_last--;
    }
}

int* update_stop_last(Network *system, int *array, int* len, int id, int i) {
    if (system->links[i].id_start == id) {
        array[(*len)++] = (system->links[i].id_finish > id) ?
            system->links[i].id_finish - 1:
            system->links[i].id_finish;
    } else {
        array[(*len)++] = (system->links[i].id_start > id) ?
            system->links[i].id_start - 1:
            system->links[i].id_start;
    }
    array = safe_realloc(array, (*len + 1)*sizeof(int));
    return array;
}


void skip_over_link(Network *system, int *i, int *link_i, int link_i_n,
                        Link** new_links, int *new_link_count, int stop_id) {
    int j = -1, link_len = system->link_count;
    Link next = {0};

    if (!(!*link_i && system->links[*i].id_start == stop_id) &&
        !(*link_i == link_i_n && system->links[*i].id_finish == stop_id)) {
        for (j = *i; j < link_len - 1; j++) {
            next = system->links[j + 1];
            if (next.id_finish != stop_id && 
                next.id_line == system->links[*i].id_line) {
                j++;
                break;
            } else if (next.id_line != system->links[*i].id_line || 
                        (next.id_finish == stop_id && j == link_len - 2)) {
                j = -1;
                break;
            }
        }
        if (j != -1) {
            system->links[*i].id_finish = system->links[j].id_finish;
            system->links[*i].duration += system->links[j].duration;
            system->links[*i].cost += system->links[j].cost;
            (*new_links)[(*new_link_count)++] = system->links[*i];
            *new_links = safe_realloc(*new_links, 
                ((*new_link_count)+1)*sizeof(Link));
            *link_i += j - *i;
            *i += j - *i;
        }
    }
}