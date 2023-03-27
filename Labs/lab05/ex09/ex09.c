/* iaed-23 - ist1106485 - lab05/ex09 */
#include <stdio.h>
#include <time.h>

typedef struct {
    int minute;
    int hour;
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
    Date d1, d2;
    time_t timestamp1, timestamp2;
    int diff_min;

    scanf("%d-%d-%d %d:%d",
        &d1.day, &d1.month, &d1.year, &d1.hour, &d1.minute
    );
    scanf("%d-%d-%d %d:%d",
        &d2.day, &d2.month, &d2.year, &d2.hour, &d2.minute
    );
    timestamp1 = convert_timestamp(d1);
    timestamp2 = convert_timestamp(d2);
    diff_min = (timestamp2 - timestamp1) / 60;
    
    printf("%d\n", diff_min);
    return 0;
}