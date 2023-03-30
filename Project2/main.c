/*
 *   File: main.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Main file
*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Main Loop */
int main() {
    Network system = {0};
    setup_system(&system);

    while (command_handler(&system));
    free_system(&system);

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
    } else if (option == 'r') {
        command_delete_line(system);
    } else if (option == 'e') {
        command_delete_stop(system);
    } else if (option == 'a') {
        free_system(system);
        setup_system(system);
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
    int i, args;
    char **tokens = safe_calloc(CMD_C_ARGS, sizeof(char*));
    for (i = 0; i < CMD_C_ARGS; i++)
        tokens[i] = safe_calloc(1, sizeof(char));

    args = tokenize(tokens, CMD_C_ARGS);
    if (!args) {
        list_all_lines(system);
    } else if (args == 1) {
        check_line_exists(system, tokens[0], false);
    } else if (args == 2 && check_inverso(tokens[1])) {
        check_line_exists(system, tokens[0], true);
    } else {
        printf(ERROR_SORT_OPTION);
    }
    free_str_arr(tokens, CMD_C_ARGS);
}

/*
 * Function for adding and listing stops - 'p' command
 * Token indeces:
 * 0 -> stop name; 1 -> latitude; 2 -> longitude
*/
void command_add_list_stops(Network *system) {
    int i, args, result;
    double lat = 0, lon = 0;
    char **tokens = safe_calloc(CMD_P_ARGS, sizeof(char*));
    for (i = 0; i < CMD_P_ARGS; i++)
        tokens[i] = safe_calloc(1, sizeof(char));

    args = tokenize(tokens, CMD_P_ARGS);
    if (!args) {
        list_all_stops(system);
    } else if (args == 1) {
        result = check_stop_exists(system, tokens[0], true);
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
    free_str_arr(tokens, CMD_P_ARGS);
}

/*
 * Function for adding and listing links between stops - 'l' command
 * Token indeces:
 * 0 -> line name; 1 -> start_stop; 2 -> end_stop; 3 -> cost; 4 -> duration
*/
void command_add_links(Network *system) {
    int i, args, result;
    char **tokens = safe_calloc(CMD_L_ARGS, sizeof(char*));
    for (i = 0; i < CMD_L_ARGS; i++)
        tokens[i] = safe_calloc(1, sizeof(char));

    args = tokenize(tokens, CMD_L_ARGS);
    if (args) {
        result = check_link_args(system, tokens);
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
    free_str_arr(tokens, CMD_L_ARGS);
}

/* Function for listing line intersections - 'i' command */
void command_list_intersections(Network *system) {
    short i, len = system->stop_count;
    for (i = 0; i < len; i++) {
        if (system->stops[i].n_lines > 1) {
            printf("%s %d:",system->stops[i].name, system->stops[i].n_lines);
            print_intersections(system, i);
            printf("\n");
        }
    }
}

void command_delete_line(Network *system) {
    int args, result;
    char **tokens = safe_calloc(CMD_R_ARGS, sizeof(char*));
    tokens[0] = safe_calloc(1, sizeof(char));

    args = tokenize(tokens, CMD_R_ARGS);
    if (args) {
        result = delete_line(system, tokens[0]);
        if (result == ERROR_CODE_NO_LINE)
            printf("%s: %s", tokens[0], ERROR_NO_LINE);
    }
    free_str_arr(tokens, CMD_R_ARGS);
}

void command_delete_stop(Network *system) {
    int args, result;
    char **tokens = safe_calloc(CMD_E_ARGS, sizeof(char*));
    tokens[0] = safe_calloc(1, sizeof(char));

    args = tokenize(tokens, CMD_E_ARGS);
    if (args) {
        result = delete_stop(system, tokens[0]);
        if (result == ERROR_CODE_NO_STOP)
            printf("%s: %s", tokens[0], ERROR_NO_STOP);
    }
    free_str_arr(tokens, CMD_E_ARGS);
}

/*
 * Populates the tokens array with the received command arguments
 * Return Value: Number of used tokens
*/
int tokenize(char **tokens, int len) {
    /* quote keeps track if an argument is in quotes */
    int i = 0, quote = 0, j = 0, buff = 0;
    char c;

    while((c = getchar()) != '\n') {
        if (i < len && ++buff < BUFSIZ) {
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