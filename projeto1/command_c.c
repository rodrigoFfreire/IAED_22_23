/*
 *   File: commands_c.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Source code of the 'c' command functions
*/
#include "main.h"
#include <stdio.h>
#include <string.h>



void list_all_tracks(Network *system) {
	short i, j, *track_len = &(system->track_count);
	short connect_len = system->connection_count;

	for (i = 0; i < *track_len; i++) {
		printf("%s ",system->tracks[i].name);
		for (j = 0; j < connect_len; j++) {
			if (!strcmp(system->tracks[i].name,
                        system->connections[j].track.name)) {
				printf("%s %s ",
					system->tracks[i].first.name,
					system->tracks[i].last.name
				);
				break;
			}
		}
		printf("%d %.2f %.2f\n",
			system->tracks[i].n_stops,
			system->tracks[i].total_cost,
			system->tracks[i].total_duration
		);
	}
}


int create_track_list_stops(Network *system, char name[],int invert,int arg2) {
	short i;
	short *track_len = &(system->track_count);
	short connection_len = system->connection_count;

	if (arg2 && !invert) {
		return 0;
	} else {
		for (i = 0; i < *track_len; i++) {
			if (!strcmp(name, system->tracks[i].name)) {
				list_stops(system, name, invert, connection_len);
				return 1;
			}
		}
		create_track(system, name, track_len);
	}
	return 1;
}


void list_stops(Network *system, char name[], int invert, short len) {
	short j, last_stop;
	if (!invert) {
		for (j = 0; j < len; j++) {
			if (!strcmp(name, system->connections[j].track.name)) {
				last_stop = j;
				printf("%s, ", system->connections[j].start.name);
			}
		}
		printf("%s\n", system->connections[last_stop].end.name);
	} else {
		for (j = len - 1; j >= 0; j--) {
			if (!strcmp(name, system->connections[j].track.name)) {
				last_stop = j;
				printf("%s, ", system->connections[j].end.name);
			}
		}
		printf("%s\n", system->connections[last_stop].start.name);
	}
}


void create_track(Network *system, char name[], short *len) {
	if (*len < MAX_TRACKS) {
		*len += 1;
		strcpy(system->tracks[*len - 1].name, name);
        system->tracks[*len - 1].n_stops = 0;
		system->tracks[*len - 1].total_cost = 0;
		system->tracks[*len - 1].total_duration = 0;
	}
}
