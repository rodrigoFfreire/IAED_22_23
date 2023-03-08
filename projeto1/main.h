/*
 *   File: project1.h
 *   Author: Rodrigo Freire - 106485
 *   Description: Main header file
 */

/* CONSTANTS */
#ifndef MAIN_H
#define MAIN_H


#define LINE_NAME_MAX_SIZE 20
#define STOP_NAME_MAX_SIZE 50
#define MAX_LINES 200
#define MAX_STOPS 10000
#define MAX_LINKS 30000
#define INVERSO_LENGTH 8


#define INVERSO "inverso"
#define ERROR_SORT_OPTION "incorrect sort option.\n"
#define	ERROR_STOP_EXISTS "stop already exists.\n"
#define ERROR_NO_STOP "no such stop.\n"
#define ERROR_NO_LINE "no such line.\n"
#define ERROR_LINK "link cannot be associated with bus line.\n"
#define ERROR_ILLEGAL_VALUE "negative cost or duration.\n"

/* STRUCTS */
typedef struct {
	char name[STOP_NAME_MAX_SIZE];
	unsigned char n_lines;
	double latitude;
	double longitude;
} Stop;

typedef struct {
	char name[LINE_NAME_MAX_SIZE];
	double total_cost;
	double total_duration;
	short n_stops;
	Stop *first;
	Stop *last;
} Line;

typedef struct {
	Line *line;
	Stop *start;
	Stop *end;
	double cost;
	double duration;
} Link;

typedef struct {
	Line lines[MAX_LINES];
	Stop stops[MAX_STOPS];
	Link links[MAX_LINKS];
	short line_count;
	short stop_count;
	short link_count;
} Network;

/* Enums */
enum get_command_args_FLAGS{no_args, one_arg, more_args};
enum bool{false, true};

/* main functions */

int command_handler(Network *system);

void command_add_list_lines(Network *system);

void command_add_list_stops(Network *system);

void command_add_links(Network *system);

/* void command_list_intersections(Network *system); */

int get_command_arguments(char arg[], int len);

int check_inv(char inv[]);

void setup_system(Network *system);


/* Command 'c' functions */

void list_stops(Network *system, char name[], int invert, short len);

void create_line(Network *system, char name[], short *len);

int create_line_list_stops(Network *system, char name[], int invert, int arg2);

void list_all_lines(Network *system);

void update_line(Network *system, short *ids, char init);

/* Command 'p' functions */
void list_all_stops(Network *system);

int get_stop(Network *system, char name[], char print);

int create_stop(Network *system, char name[], float lat, float lon);

/* void update_stops(Network *system, short *ids); */

/* Command 'l' functions */
int create_link(Network *system, char **names, double *cost_dur);

int add_link(Network *system, char **names, double *cost_dur);

void add_link_aux(Network *system, char **names, double *cost_dur, char pos);

short get_line_id(Network *system, char *name);

short get_stop_id(Network *system, char *name);

void configure_link(Network *system, short *ids, double *cost_dur, short pos);

void move_links(Network *system, short pos);

#endif
