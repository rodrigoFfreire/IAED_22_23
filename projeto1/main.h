/*
 *   File: project1.h
 *   Author: Rodrigo Freire - 106485
 *   Description: Main header file
 */

/* CONSTANTS */
#ifndef MAIN_H
#define MAIN_H


#define TRACK_NAME_MAX_SIZE 20
#define STOP_NAME_MAX_SIZE 50
#define MAX_TRACKS 200
#define MAX_STOPS 1000
#define MAX_CONNECTIONS 2000

#define INVERSO_LENGTH 8
#define INVERSO_ARGUMENT "inverso"
#define ERROR_SORT_OPTION "incorrect sort option\n"

/* STRUCTS */
typedef struct {
	char name[STOP_NAME_MAX_SIZE];
	double latitude;
	double longitude;
} Stop;

typedef struct {
	char name[TRACK_NAME_MAX_SIZE];
	double total_cost;
	double total_duration;
	Stop first;
	Stop last;
} Track;

typedef struct {
	Track track;
	Stop start;
	Stop end;
	double cost;
	double duration;
} Connection;

typedef struct {
	Track tracks[MAX_TRACKS];
	Stop stops[MAX_STOPS];
	Connection connections[MAX_CONNECTIONS];
	short track_count;
	short stop_count;
	short connection_count;
} Network;

/* Enums */
enum get_command_args_FLAGS{no_args, one_arg, more_args};
enum bool{false, true};

/* main functions */
int command_handler(Network *system);

void command_add_list_tracks(Network *system);

void command_add_list_stops(Network *system);

void command_add_list_connections(Network *system);

void command_list_intersections(Network *system);

int get_command_arguments(char arg[], int len);

int check_inverso_argument(char inv[]);

void setup_transport_system(Network *system);

/* Command functions */
void list_stops_aux(Network *system, char name[], int inverted, short len);

void create_track_list_stops(Network *system, char name[], int inverted);

void list_all_tracks(Network *system);

void list_all_stops(Network *system);

#endif
