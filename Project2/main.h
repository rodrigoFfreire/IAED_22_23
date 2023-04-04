/*
 *   File: main.h
 *   Author: Rodrigo Freire - 106485
 *   Description: Main header file
 */
#ifndef MAIN_H
#define MAIN_H


/* CONSTANTS */
/* Number of arguments read by each command */
#define CMD_C_ARGS 2
#define CMD_P_ARGS 3
#define CMD_L_ARGS 5
#define CMD_R_ARGS 1
#define CMD_E_ARGS 1
/* Error Codes */
#define ERROR_CODE_NO_LINE -1
#define ERROR_CODE_NO_STOP -2
#define ERROR_CODE_NO_STOP_START -3
#define ERROR_CODE_NO_STOP_END -4
#define ERROR_CODE_LINK -5
#define ERROR_CODE_ILLEGAL_VALUE -6
#define ERROR_CODE_INVALID_ID -7
#define ERROR_CODE_OTHER -8
/* Other constants */
#define INVERSO_LENGTH 9     /* Maximum string length for INVERSO argument */
#define INVERSO_ABV_LIMIT 3    /* INVERSO argument abbreviation limit */
/* String constants */
#define INVERSO "inverso"
#define ERROR_SORT_OPTION "incorrect sort option.\n"
#define	ERROR_STOP_EXISTS "stop already exists.\n"
#define ERROR_NO_STOP "no such stop.\n"
#define ERROR_NO_LINE "no such line.\n"
#define ERROR_LINK "link cannot be associated with bus line.\n"
#define ERROR_ILLEGAL_VALUE "negative cost or duration.\n"
#define ERROR_NO_MEMORY "No memory.\n"


/* TYPEDEFS */
typedef unsigned long _size_t;

typedef struct {
    char *name;
    int n_lines;
    double latitude, longitude;
} Stop;

typedef struct {
    char *name;
    double total_cost, total_duration;
    int n_stops;
    int id_first, id_last;
} Line;

typedef struct {
    int id_line, id_start, id_finish;
    double cost, duration;
} Link;

typedef struct {
    Line *lines;
    Stop *stops;
    Link *links;
    int line_count;
    int stop_count;
    int link_count;
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

void command_delete_line(Network *system);

void command_delete_stop(Network *system);

int tokenize(char **tokens, int len);

int used_tokens_len(char **tokens, int len);

int check_inverso(char *inv);

/* lines.c Functions */
void list_stops(Network *system, char *name, int invert);

void create_line(Network *system, char *new_name);

void check_line_exists(Network *system, char *name, int invert);

int get_line_id(Network *system, char *name);

void list_all_lines(Network *system);

void update_line(Network *system, int *ids);

int delete_line(Network *system, char *name);

void update_arrays_line(Network *system, int id, int new_count, Link *new);

/* stops.c Functions */
void list_all_stops(Network *system);

int check_stop_exists(Network *system, char *name, char print);

int get_stop_id(Network *system, char *name);

int create_stop(Network *system, char *name, double lat, double lon);

void update_stop(Network *system, int stop_id);

int delete_stop(Network *system, char *name);

void build_new_links(Network *system, int stop_id, int** updated_stops, 
                        int* stops_len, int** updated_lines, int* lines_len);

void skip_over_link(Network *system, int *i, int *link_i, int link_i_n,
                        Link** new_links, int *new_link_count, int stop_id);

void update_arrays_stop(Network *system, int id, int new_count, Link *new);

int* update_stop_last(Network *system, int *array, int* len, int id, int i);

/* links.c Functions */
int check_link_args(Network *system, char **tokens);

int add_link(Network *system, int *ids , double *cost_dur);

void add_link_aux(Network *system, int *ids, double *cost_dur, char pos);

void configure_link(Network *system, int *ids, double *cost_dur, int pos);

void move_links(Network *system, int pos);

/* intersections.c functions */
void print_intersections(Network *system, int stop_id);

void selection_sort(Network *system, int *array, int len);

/* utils.c functions */
void setup_system(Network *system);

void* safe_calloc(_size_t n, _size_t size);

void* safe_realloc(void* p, _size_t size);

int* add_to_filtered_array(int *array, int id, int *array_len);

void free_str_arr(char **arr, int len);

void free_system(Network *system);

#endif
