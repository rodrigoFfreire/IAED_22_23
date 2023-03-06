/*
 *   File: project1.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Main file
*/
#include "main.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Main Loop */
int main() {
	Network system;
	setup_transport_system(&system);

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
			command_add_list_tracks(system);
			return 1;
			break;

		case 'p':
			command_add_list_stops(system);
			return 1;
			break;

		case 'l':
			command_add_list_connections(system);
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
 * Function for adding and listing tracks - 'c' command
 *   
 *
*/
void command_add_list_tracks(Network *system) {
	char name[TRACK_NAME_MAX_SIZE];
	char inverse[INVERSO_LENGTH];
	int arg1, arg2;
	
	arg1 = get_command_arguments(name, TRACK_NAME_MAX_SIZE);

	if (!arg1) {
		list_all_tracks(system);
		return;
	} else if (arg1 == more_args) {
		arg2 = get_command_arguments(inverse, INVERSO_LENGTH + 1);
	}

	if (arg1 == one_arg || (arg1 == more_args && !arg2)) {
		create_track_list_stops(system, name, false);
	} else if (arg2 >= one_arg && check_inverso_argument(inverse)) {
		create_track_list_stops(system, name, true);
	} else {
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
	int arg1;

	arg1 = get_command_arguments(name, STOP_NAME_MAX_SIZE);
	if (!arg1) {
		list_all_stops(system);
	} else if (arg1 == more_args) {
		scanf("%lf %lf", &latitude, &longitude);
		printf("Adding stop with <%s> <%16.12f> <%16.12f>\n", name, latitude, longitude);
	} else if (arg1 == one_arg) {
		printf("Listing <%s> stop...\n", name);
	}
	
}

/*
 * Function for adding and listing connections between stops - 'l' command
 *
 *
*/
void command_add_list_connections(Network *system) {
	char name[TRACK_NAME_MAX_SIZE];
	char start[STOP_NAME_MAX_SIZE], end[STOP_NAME_MAX_SIZE];
	double cost, duration;
	int arg1;

	arg1 = get_command_arguments(name, TRACK_NAME_MAX_SIZE);
	scanf("%s %s %s %lf %lf", name, start, end, &cost, &duration);

}

/*
 * Function for listing track intersections - 'i' command
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
int check_inverso_argument(char inv[]) {
	int i, len = strlen(inv);
	if (len < 3 || len > INVERSO_LENGTH) {
		return 0;
	}
	for (i = 0; i < len; i++) {
		if (inv[i] != INVERSO_ARGUMENT[i]) {
			return 0;
		}
	}
	return 1;
}

void setup_transport_system(Network *system) {
	system->track_count = 0;
	system->connection_count = 0;
	system->stop_count = 0;
}