/*
 *   File: main.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Main file
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Main Loop */
int main() {
    Stop stop0 = {0};
    Line line0 = {0};
    Link link0 = {0};
    Network system = {0};
    setup_system(&system, &stop0, &line0, &link0);
    
    while (command_handler(&system));

    return 0;
}


/*
 * Handles user input
 * Return Values:
 * 1 -> Keep the program open after executing command
 * 0 -> Close the program
*/
int command_handler(Network *system) {
    char option = getchar();

    if (option == 'c') {
        command_add_list_lines(system);
    } else if (option == 'p') {
        command_add_list_stops(system);
    } else if (option == 'l') {
        command_add_links(system);
    } else if (option == 'i') {
        command_list_intersections(system);
    } else if (option == 'q') {
        return false;
    }
    return true;
}

/*
 * Function for adding and listing lines - 'c' command
 * Token indeces:
 * 0 -> line name; 1 -> inverso argument
*/
void command_add_list_lines(Network *system) {
    int args, sizes[] = {LINE_NAME_MAX, INVERSO_LENGTH};
    char tokens[CMD_C_ARGS][LINE_NAME_MAX] = {0};
    char **tokens_ptr, *sub_ptrs[CMD_C_ARGS];

    sub_ptrs[0] = &tokens[0][0], sub_ptrs[1] = &tokens[1][0];
    tokens_ptr = sub_ptrs;

    args = tokenize(tokens_ptr, sizes, CMD_C_ARGS);
    if (!args) {
        list_all_lines(system);
    } else if (args == 1) {
        check_line_exists(system, tokens[0], false);
    } else if (args == 2 && check_inverso(tokens[1])) {
        check_line_exists(system, tokens[0], true);
    } else {
        printf(ERROR_SORT_OPTION);
    }
}

/*
 * Function for adding and listing stops - 'p' command
 * Token indeces:
 * 0 -> stop name; 1 -> latitude; 2 -> longitude
*/
void command_add_list_stops(Network *system) {
    int args, result, sizes[] = {STOP_NAME_MAX, DOUBLE_LEN, DOUBLE_LEN};
    char tokens[CMD_P_ARGS][STOP_NAME_MAX] = {0};
    char **tokens_ptr, *sub_ptrs[CMD_P_ARGS];
    double lat = 0, lon = 0;

    sub_ptrs[0] = &tokens[0][0], sub_ptrs[1] = &tokens[1][0],
    sub_ptrs[2] = &tokens[2][0], tokens_ptr = sub_ptrs;

    args = tokenize(tokens_ptr, sizes, CMD_P_ARGS);
    if (!args) {
        list_all_stops(system);
    } else if (args == 1) {
        result = get_stop(system, tokens[0], true);
        if (!result) {
            printf("%s: %s", tokens[0], ERROR_NO_STOP);
        }
    } else {
        lat = atof(tokens[1]), lon = atof(tokens[2]);   /* string to double */
        result = create_stop(system, tokens[0], lat, lon);
        if (!result) {
            printf("%s: %s", tokens[0], ERROR_STOP_EXISTS);
        }
    }
}

/*
 * Function for adding and listing links between stops - 'l' command
 * Token indeces:
 * 0 -> line name; 1 -> start_stop; 2 -> end_stop; 3 -> cost; 4 -> duration
*/
void command_add_links(Network *system) {
    int args, result, sizes[] = {LINE_NAME_MAX, STOP_NAME_MAX, 
                                    STOP_NAME_MAX, DOUBLE_LEN, DOUBLE_LEN};
    char tokens[CMD_L_ARGS][STOP_NAME_MAX] = {0};
    char **tokens_ptr, *sub_ptrs[CMD_L_ARGS];

    sub_ptrs[0] = &tokens[0][0], sub_ptrs[1] = &tokens[1][0],
    sub_ptrs[2] = &tokens[2][0], sub_ptrs[3] = &tokens[3][0],
    sub_ptrs[4] = &tokens[4][0], tokens_ptr = sub_ptrs;

    args = tokenize(tokens_ptr, sizes, CMD_L_ARGS);
    if (args) {
        result = check_link_args(system, tokens_ptr);
        if (result == ERROR_CODE_NO_LINE) {
            printf("%s: %s", tokens[0], ERROR_NO_LINE);
        } else if (result == ERROR_CODE_NO_STOP_START) {
            printf("%s: %s", tokens[1], ERROR_NO_STOP);
        } else if (result == ERROR_CODE_NO_STOP_END) {
            printf("%s: %s", tokens[2], ERROR_NO_STOP);
        } else if (result == ERROR_CODE_LINK) {
            printf(ERROR_LINK);
        } else if (result == ERROR_CODE_ILLEGAL_VALUE) {
            printf(ERROR_ILLEGAL_VALUE);
        }
    }
}

/* Function for listing line intersections - 'i' command */
void command_list_intersections(Network *system) {
    short i, len = system->stop_count;
    for (i = 0; i < len; i++) {
        if (system->stops[i].n_lines > 1) {
            printf("%s %d:",system->stops[i].name, system->stops[i].n_lines);
            print_intersections(system, system->stops[i].name);
            printf("\n");
        }
    }
}

/*
 * Auxiliary Function that gets command arguments and tokenizes
 * these values into an array
 * Return Value: Number of used tokens
*/
int tokenize(char **tokens, int *sizes, int len) {
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
            if ((j == 0 && (!isspace(c) || (quote % 2))) ||
                    (j != 0 && j < sizes[i] - 1)) {
                tokens[i][j++] = c;
            }
        }
    }
    return used_tokens_len(tokens, len);
}

/*
 * Auxiliary Function returns the amount of tokens
 * that were populated by the tokenize function
*/
int used_tokens_len(char **tokens, int len) {
    int i, args = 0;
    for (i = 0; i < len; i++) {
        if (tokens[i][0] != '\0')
            args++;
    }
    return args;
}

/*
 * Checks if `inverso` argument is correct
 * Return Values:
 * 1 -> argument is correct
 * 0 -> argument not correct
*/
int check_inverso(char *inv) {
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
 * Initializes the Stop, Line, Link Arrays with default objects
 * (stop0, line0, link0) that equal to NULL
*/
void setup_system(Network *system, Stop *stop0, Line *line0, Link *link0) {
    int i;
    system->line_count = 0, system->link_count = 0, system->stop_count = 0;
    line0->first = stop0, line0->last = stop0;
    link0->line = line0, link0->start = stop0, link0->end = stop0;

    for (i = 0; i < MAX_STOPS; i++) {
        system->stops[i] = *stop0;
    }
    for (i = 0; i < MAX_LINES; i++) {
        system->lines[i] = *line0;
    }
    for (i = 0; i < MAX_LINKS; i++) {
        system->links[i] = *link0;
    }
}

