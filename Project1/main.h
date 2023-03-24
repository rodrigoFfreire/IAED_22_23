/*
 *   File: main.h
 *   Author: Rodrigo Freire - 106485
 *   Description: Main header file
 */
#ifndef MAIN_H
#define MAIN_H


/* CONSTANTS */
/* Maximum name lengths*/
#define LINE_NAME_MAX 21
#define STOP_NAME_MAX 51
/* Maximum array elements*/
#define MAX_LINES 200
#define MAX_STOPS 10000
#define MAX_LINKS 30000
/* Number of arguments read by each command */
#define CMD_C_ARGS 2
#define CMD_P_ARGS 3
#define CMD_L_ARGS 5
/* Error codes */
#define ERROR_CODE_NO_LINE -1
#define ERROR_CODE_NO_STOP_START -2
#define ERROR_CODE_NO_STOP_END -3
#define ERROR_CODE_LINK -4
#define ERROR_CODE_ILLEGAL_VALUE -5
#define ERROR_CODE_INVALID_ID -6
#define ERROR_CODE_OTHER -7
/* Other constants */
#define INVERSO_LENGTH 9     /* Maximum string length for INVERSO argument */
#define DOUBLE_LEN 18    /* Maximum string length when converting to double */
#define INVERSO_ABV_LIMIT 3    /* INVERSO argument abbreviation limit */
/* String constants */
#define INVERSO "inverso"
#define ERROR_SORT_OPTION "incorrect sort option.\n"
#define	ERROR_STOP_EXISTS "stop already exists.\n"
#define ERROR_NO_STOP "no such stop.\n"
#define ERROR_NO_LINE "no such line.\n"
#define ERROR_LINK "link cannot be associated with bus line.\n"
#define ERROR_ILLEGAL_VALUE "negative cost or duration.\n"


/* STRUCTS */
typedef struct {
    char name[STOP_NAME_MAX];
    unsigned char n_lines;
    double latitude;
    double longitude;
} Stop;

typedef struct {
    char name[LINE_NAME_MAX];
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
} Network;  /* Contains the Line, Stop, Link arrays (global system) */


/* ENUMS */
enum bool{false, true};


/* FUNCTIONS */
/* main.c Functions */
int command_handler(Network *system);

void command_add_list_lines(Network *system);

void command_add_list_stops(Network *system);

void command_add_links(Network *system);

void command_list_intersections(Network *system);

int tokenize(char **tokens, int *sizes, int len);

int used_tokens_len(char **tokens, int len);

int check_inverso(char *inv);

void setup_system(Network *system, Stop *stop0, Line *line0, Link *link0);

/* lines.c Functions */
void list_stops(Network *system, char *name, int invert);

void create_line(Network *system, char *name);

void check_line_exists(Network *system, char *name, int invert);

void list_all_lines(Network *system);

void update_line(Network *system, short *ids, int init);

/* stops.c Functions */
void list_all_stops(Network *system);

int get_stop(Network *system, char *name, char print);

int create_stop(Network *system, char *name, double lat, double lon);

void update_stop(Network *system, short stop_id);

int line_exists_in(unsigned char *line_ids, unsigned char n);

/* links.c Functions */
int check_link_args(Network *system, char **tokens);

int add_link(Network *system, char **names, double *cost_dur);

void add_link_aux(Network *system, char **names, double *cost_dur, char pos);

short get_line_id(Network *system, char *name);

short get_stop_id(Network *system, char *name);

void configure_link(Network *system, short *ids, double *cost_dur, short pos);

void move_links(Network *system, short pos);

void compact_ids(Network *system, short *ids, char **names);

/* intersections.c functions */
void print_intersections(Network *system, char *stop_name);

int line_name_exists(char lines[][LINE_NAME_MAX], char *name, short len);

void selection_sort(char arr[][LINE_NAME_MAX], short len);

#endif
