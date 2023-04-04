/*
 *   File: intersections.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for intersection related functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 
 * Receives a Network object and a name of a stop and displays 
 * every line that intersects this stop
*/
void print_intersections(Network *system, int stop_id) {
    int i, array_len = 0, link_len = system->link_count;
    int curr_line;
    int* line_ids = (int*) safe_calloc(1, sizeof(int));

    for (i = 0; i < link_len; i++) {
        if (system->links[i].id_start == stop_id ||
                system->links[i].id_finish == stop_id) {
            curr_line = system->links[i].id_line;
            line_ids = add_to_filtered_array(line_ids, curr_line, &array_len);
        }
    }
    selection_sort(system, line_ids, array_len);
    for (i = 0; i < array_len; i++) {
        printf(" %s", system->lines[line_ids[i]].name);
    }
    free(line_ids);
}

/*
 * Standard implementation of selection sort that compares line names
 * Receives a Network object, an array of line ids and its length
*/
void selection_sort(Network *system, int *array, int len) {
    int i, j, min = 0;
    int aux;
    
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (strcmp(system->lines[array[j]].name,
                    system->lines[array[min]].name) < 0) {
                min = j;
            }
        }
        if (min != i) {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }
}
