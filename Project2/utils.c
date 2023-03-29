#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Receives a Network object and initializes the link, stop and line arrays */
void setup_system(Network *system) {
    system->line_count = 0, system->link_count = 0, system->stop_count = 0;
    system->lines = (Line*) safe_calloc(1, sizeof(Line));
    system->links = (Link*) safe_calloc(1, sizeof(Link));
    system->stops = (Stop*) safe_calloc(1, sizeof(Stop));
}

/*
 * This function receives the size of a block to be safelly allocated
 * If there is no memory available the program will free all memory and
 * terminate
*/
void* safe_calloc(_size_t n, _size_t size) {
    void* pointer = calloc(n, size);
    if (pointer != NULL) return pointer;

    printf(ERROR_NO_MEMORY);
    exit(EXIT_FAILURE); /* exit also frees all allocated memory */
    return NULL;
}

void* safe_realloc(void* p, _size_t size) {
    p = realloc(p, size);
    if (p != NULL) return p;

    printf(ERROR_NO_MEMORY);
    exit(EXIT_FAILURE);
    return NULL;
}

int* add_to_filtered_array(int *array, int id, int *array_len) {
    int i;
    for (i = 0; i < *array_len; i++) {
        if (array[i] == id) {
            return array;
        }
    }
    array[*array_len] = id;
    (*array_len)++;
    array = safe_realloc(array, (*array_len + 1)*sizeof(int));

    return array;
}

void free_system(Network *system) {
    int x, i = system->line_count;
    int j = system->stop_count;

    for (x = 0; x < i; x++) {
        free(system->lines[x].name);
    }
    for (x = 0; x < j; x++) {
        free(system->stops[x].name);
    }
    free(system->lines);
    free(system->links);
    free(system->stops);
}

void free_str_arr(char **arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        free(arr[i]);
    }
    free(arr);
}