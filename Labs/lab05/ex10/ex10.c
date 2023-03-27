/* iaed-23 - ist1106485 - lab05/ex10 */
#include <stdio.h>
#include <time.h>

#define START_TIMESTAMP 1640995200 /* 01-01-2022 00:00 */

typedef struct {
    int hour;
    int minute;
    int day;
    int month;
    int year;
} Date;


int main() {
    time_t timestamp;
    struct tm *new_date;
    int min;
    scanf("%d", &min);

    timestamp = START_TIMESTAMP + (min * 60);
    new_date = localtime(&timestamp);
    printf("%02d-%02d-%02d %02d:%02d\n",
        new_date->tm_mday,
        new_date->tm_mon + 1,
        new_date->tm_year + 1900,
        new_date->tm_hour,
        new_date->tm_min
    );
    return 0;
}