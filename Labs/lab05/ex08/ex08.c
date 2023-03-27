
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

time_t convert_timestamp(Date d) {
    struct tm time_s = {0};
    time_t timestamp;

    time_s.tm_year = d.year - 1900;
    time_s.tm_mon = d.month - 1;
    time_s.tm_mday = d.day;
    time_s.tm_hour = d.hour;
    time_s.tm_min = d.minute;
    timestamp = mktime(&time_s);
    return timestamp;
}


int main() {
    Date date;
    time_t input_timestamp;
    int diff_min;
    scanf("%d-%d-%d %d:%d",
        &date.day, &date.month, &date.year, &date.hour, &date.minute
    );

    input_timestamp = convert_timestamp(date);
    diff_min = (input_timestamp - START_TIMESTAMP) / 60;
    printf("%d\n", diff_min);
    return 0;
}