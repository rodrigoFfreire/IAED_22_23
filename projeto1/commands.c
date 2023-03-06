/*
 *   File: commands.c
 *   Author: Rodrigo Freire - 106485
 *   Description: Command Functions File
*/
#include "main.h"


void get_tracks(TransportNetwork *system) {
    int i, len = system->track_count;
    for (i = 0; i < len; i++) {
        printf("%s %s %s %d %d %lf %lf",
            system->tracks[i].name,
            system->tracks[i].first,
            system->tracks[i].last,
            system->tracks[i].total_cost,
            system->tracks[i].total_duration
        );
    }
}