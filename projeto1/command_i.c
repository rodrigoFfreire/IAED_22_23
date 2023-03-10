/*
 *   File: commands_i.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'i' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_intersections(Network *system, char *stop_name) {
    short i, array_len = 0, len = system->link_count;
    char curr_line[LINE_NAME_MAX_SIZE];
    char **line_array = NULL;
    array_control(&line_array, &len, create);
    for (i = 0; i < len; i++) {
        if (!strcmp(system->links[i].start->name, stop_name) ||
                !strcmp(system->links[i].end->name, stop_name)) {
            strcpy(curr_line, system->links[i].line->name);

            if (!line_name_exists(line_array, curr_line, &array_len)) {
                strcpy(line_array[array_len], curr_line);
                array_control(&line_array, &array_len, expand);
            }
        }
    }
    selection_sort(line_array, array_len);
    for (i = 0; i < array_len; i++) {
        printf(" %s", line_array[i]);
    }
    printf("\n");
    array_control(&line_array, &array_len, delete);
}


int line_name_exists(char **line_array, char *name, short *len) {
    short i;
    for (i = 0; i < *len; i++) {
        if (!strcmp(line_array[i], name)) {
            return 1;
        }
    }
    return 0;
}


void array_control(char ***array, short *len, int mode) {
    short i;
    if (mode == 0) {
        *array = (char **) malloc(sizeof(char *));
        (*array)[0] = (char *) malloc(LINE_NAME_MAX_SIZE * sizeof(char));
    } else if (mode == 1) {
        *len += 1;
        *array = (char**) realloc(*array, (*len + 1)*sizeof(char *));
        (*array)[*len] = malloc(LINE_NAME_MAX_SIZE * sizeof(char));
    } else if (mode == 2) {
        for (i = 0; i <= *len; i++) {
            free((*array)[i]);
        }
        free(*array);
    }
}


void selection_sort(char **array, short len) {
    int i, j, j_min = 0;
    char k[LINE_NAME_MAX_SIZE];
    for (i = 0; i < len - 1; i++) {
        j_min = i;
        for (j = i + 1; j < len; j++) {
            if (strcmp(array[j], array[j_min]) < 0) {
                j_min = j;
            }
        }
        if (j_min != i) {
            strcpy(k, array[i]);
            strcpy(array[i], array[j_min]);
            strcpy(array[j_min], k);
        }
    }
}
