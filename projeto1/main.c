/*
 *   File: project1.c
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
	static Network system = {0};
	setup_network_system(&system);

	sizeof(Network);
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

	switch (option) {
		case 'c':
			command_add_list_lines(system);
			return 1;
			break;

		case 'p':
			command_add_list_stops(system);
			return 1;
			break;

		case 'l':
			command_add_list_links(system);
			return 1;
			break;

		case 'i':
			command_list_intersections(system);
			return 1;
			break;

		case 'q':
			return 0;
			break;

		default: /* Default Case: Unknown Commands */
			return 1;
			break;
	}
}

/*
 * Function for adding and listing lines - 'c' command
 *   
 *
*/
void command_add_list_lines(Network *system) {
	char name[LINE_NAME_MAX_SIZE];
	char inverse[INVERSO_LENGTH];
	int arg1 = 0, arg2 = 0, result;
	
	arg1 = get_command_arguments(name, LINE_NAME_MAX_SIZE);

	if (!arg1) {
		list_all_lines(system);
		return;
	} else if (arg1 == more_args) {
		arg2 = get_command_arguments(inverse, INVERSO_LENGTH + 1);
	}

	result = create_line_list_stops(system, name, check_inv(inverse), arg2);
	if (!result) {
		printf(ERROR_SORT_OPTION);
	}
}

/*
 * Function for adding and listing stops - 'p' command
 *
 *
*/
void command_add_list_stops(Network *system) {
	char name[STOP_NAME_MAX_SIZE];
	double latitude, longitude;
	int arg1, result;

	arg1 = get_command_arguments(name, STOP_NAME_MAX_SIZE);
	
	if (!arg1) {
		list_all_stops(system);
		
	} else if (arg1 == more_args) {
		scanf("%lf %lf", &latitude, &longitude);
		result = create_stop(system, name, latitude, longitude);
		if (!result) {
			printf(ERROR_STOP_EXISTS);
		}
	} else if (arg1 == one_arg) {
		result = get_stop(system, name, true);
		if (!result) {
			printf(ERROR_NO_STOP);
		}
	}
}

/*
 * Function for adding and listing links between stops - 'l' command
 *
 *
*/
void command_add_links(Network *system) {
	char name[LINE_NAME_MAX_SIZE];
	char start[STOP_NAME_MAX_SIZE], end[STOP_NAME_MAX_SIZE];
	double cost, duration;
	int arg1, result;
	char names[3] = {name, start, end};
	double cost_dur[2] = {cost, duration};

	arg1 = get_command_arguments(name, LINE_NAME_MAX_SIZE);
	scanf("%s %s %s %lf %lf", name, start, end, &cost, &duration);

	result = create_link(system, names, cost_dur);
	if (result == -1) {
		printf(ERROR_NO_LINE);
	} else if (result == -2) {
		printf(ERROR_NO_STOP);
	} else if (result == -3) {
		printf(ERROR_LINK);
	} else if (result == -4) {
		printf(ERROR_ILLEGAL_VALUE);
	}

}

/*
 * Function for listing line intersections - 'i' command
 *
 *
*/
void command_list_intersections(Network *system) {
	return;
}

/*
 * Auxiliary Function to obtain optional command arguments
 * Return Values:
 * 0 -> No arguments found
 * 1 -> One argument found
 * 2 -> More than one argument found
*/
int get_command_arguments(char arg[], int len) {
	int i = 0, quotes = 0, flag = no_args;
	char c;

	while ((c = getchar()) != EOF && c != '\n') {
		if (c == '\"') {
			quotes++;
			continue;
		}
		if (c == ' ' && quotes % 2 == 0 && i != 0) {
			flag = more_args;
			break;
		}
		if ((i == 0 && c != ' ') || (i != 0 && i < len - 1)) {
			flag = one_arg;
			arg[i] = c;
			i++;
		}
	}
	arg[i] = '\0';
	return flag;
}

/*
 * Auxiliary Function checks if `inverso` argument is correct
 * Return Values:
 * 1 -> argument is correct
 * 0 -> argument not correct
*/
int check_inv(char inv[]) {
	int i, len = strlen(inv) + 1;	/* accounting string size with '\0' */
	for (i = 0; inv[i] != '\0'; i++) {
		if (len > INVERSO_LENGTH || (len > 4 && len < INVERSO_LENGTH)) {
			return 0;
		} else {
			if (inv[i] != INVERSO[i]) {
				return 0;
			}
		}
	}
	return 1;
}



void setup_network_system(Network *system) {
	system->line_count = 0;
	system->link_count = 0;
	system->stop_count = 0;

}