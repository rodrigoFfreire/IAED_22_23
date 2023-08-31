/*
 *   File: utils.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code for useful and memory related functions
*/
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Receives a Network object and initializes the link, stop and line arrays */
void setup_system(Network* system) {
    system->line_count = 0, system->link_count = 0, system->stop_count = 0;
    system->lines = (Line*) safe_calloc(1, sizeof(Line));
    system->links = (Link*) safe_calloc(1, sizeof(Link));
    system->stops = (Stop*) safe_calloc(1, sizeof(Stop));
}

/*
 * Checks if `inverso` argument is correct
 * Return Values:
 * 1 -> argument is correct
 * 0 -> argument not correct
*/
int check_inverso(char* inv) {
    int i, len = strlen(inv) + 1;
    for (i = 0; inv[i] != '\0'; i++) {
        if (len <= INVERSO_ABV_LIMIT || len > INVERSO_LENGTH) {
            return false;
        } else {
            if (inv[i] != INVERSO[i]) {
                return false;
            }
        }
    }
    return true;
}

/*
 * Auxiliary Function returns the amount of tokens
 * that were populated by the tokenize function
*/
int used_tokens_len(char** tokens, int len) {
    int i, args = 0;
    for (i = 0; i < len; i++) {
        if (tokens[i][0] != '\0')
            args++;
    }
    return args;
}

/*
 * Populates the tokens array with the received command arguments
 * Return Value: Number of used tokens
*/
int tokenize(char** tokens, int len) {
    /* quote keeps track if an argument is in quotes */
    int i = 0, quote = 0, j = 0;
    char c;

    while((c = getchar()) != '\n') {
        if (i < len) {
            if (c == '\"') {
                /* Enter ou exit quote mode */
                quote++;
                continue;
            }
            else if (isspace(c) && !(quote % 2) && j != 0) {
                j = 0;
                i++;
            }
            if ((j == 0 && (!isspace(c) || (quote % 2))) || j != 0) {
                tokens[i][j++] = c;
                tokens[i] = safe_realloc(tokens[i], j + 1);
                tokens[i][j] = '\0';
            }
        }
    }
    return used_tokens_len(tokens, len);
}

/*
 * This function receives the size of a block to be safelly allocated
 * If there is no memory available the program will free all memory and
 * terminate safelly
*/
void* safe_calloc(_size_t n, _size_t size) {
    void* pointer = calloc(n, size);
    if (pointer != NULL) return pointer;

    printf(ERROR_NO_MEMORY);
    exit(EXIT_FAILURE);
    return NULL;
}

/*
 * This function receives the new size of a block to be safelly reallocated
 * If there is no memory available the program will free all memory and
 * terminate safelly
*/
void* safe_realloc(void* p, _size_t size) {
    p = realloc(p, size);
    if (p != NULL) return p;

    printf(ERROR_NO_MEMORY);
    exit(EXIT_FAILURE);
    return NULL;
}

/*
 * Receives a int array, its length and an id.
 * Only adds id to the array if it doesnt exist yet
*/
int* add_to_filtered_array(int* array, int id, int* array_len) {
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

/* Receives a Network object and frees all the memory related to system */
void free_system(Network* system) {
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

/* Receives an array of strings and its length and frees the whole array */
void free_str_arr(char** arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        free(arr[i]);
    }
    free(arr);
}