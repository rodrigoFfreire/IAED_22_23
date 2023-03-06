/*
 *   File: commands.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Command Functions File
*/
#include "main.h"
#include <stdio.h>
#include <string.h>



void list_stops_aux(Network *system, char name[], int inverted, short len) {
	short j, last_stop;
	if (!inverted) {
		for (j = 0; j < len; j++) {
			if (!strcmp(name, system->connections[j].track.name)) {
				last_stop = j;
				printf("%s, ", system->connections[j].start.name);
			}
		}
		printf("%s", system->connections[last_stop].end.name);
	} else {
		for (j = len - 1; j >= 0; j--) {
			if (!strcmp(name, system->connections[j].track.name)) {
				last_stop = j;
				printf("%s, ", system->connections[j].end.name);
			}
		}
		printf("%s", system->connections[last_stop].start.name);
	}
}

void create_track_list_stops(Network *system, char name[], int inverted) {
	short i;
	short *track_len = &(system->track_count);
	short connection_len = system->connection_count;
	short last_stop;
	for (i = 0; i < *track_len; i++) {
		if (!strcmp(name, system->tracks[i].name)) {
			list_stops_aux(system, name, inverted, connection_len);
			printf("Showing stops of %s", name);
			return;
		}
	}
	*track_len += 1;
	strcpy(system->tracks[*track_len - 1].name, name);
}

void list_all_tracks(Network *system) {
	return;
}

void list_all_stops(Network *system) {
	return;
}