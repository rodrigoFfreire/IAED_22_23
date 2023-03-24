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
void print_intersections(Network *system, char *stop_name) {
    short i, array_len = 0, len = system->link_count;
    char curr_line[LINE_NAME_MAX];
    char line_array[MAX_LINES][LINE_NAME_MAX] = {0};

    for (i = 0; i < len; i++) {
        if (!strcmp(system->links[i].start->name, stop_name) ||
                !strcmp(system->links[i].end->name, stop_name)) {
            strcpy(curr_line, system->links[i].line->name);

            if (!line_name_exists(line_array, curr_line, array_len)) {
                strcpy(line_array[array_len], curr_line);
                array_len++;
            }
        }
    }
    selection_sort(line_array, array_len);
    for (i = 0; i < array_len; i++) {
        printf(" %s", line_array[i]);
    }
}

/* 
 * Receives an array of line names, a single line name and
 * the length of the array and checks if that line name exists in the array
*/
int line_name_exists(char line_array[][LINE_NAME_MAX], char *name, short len) {
    short i;
    for (i = 0; i < len; i++) {
        if (!strcmp(line_array[i], name)) {
            return true;
        }
    }
    return false;
}

/*
 * Standard implementation of selection sort that compares strings
 * Receives an array of line names and its length
*/
void selection_sort(char array[][LINE_NAME_MAX], short len) {
    int i, j, min = 0;
    char aux[LINE_NAME_MAX];
    
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (strcmp(array[j], array[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            strcpy(aux, array[i]);
            strcpy(array[i], array[min]);
            strcpy(array[min], aux);
        }
    }
}
