
#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;


time_t convert_timestamp(Date d) {
    struct tm time_s = {0};
    time_t timestamp;

    time_s.tm_year = d.year - 1900;
    time_s.tm_mon = d.month - 1;
    time_s.tm_mday = d.day;
    timestamp = mktime(&time_s);
    return timestamp;
}

int main() {
    Date date;
    time_t timestamp;
    struct tm *new_date;
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);
    
    timestamp = convert_timestamp(date) + 86400;
    new_date = localtime(&timestamp);
    printf("%02d-%02d-%02d\n",
            new_date->tm_mday,
            new_date->tm_mon + 1,
            new_date->tm_year + 1900
    );
    return 0;
}