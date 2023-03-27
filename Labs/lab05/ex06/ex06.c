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

void print_oldest(Date d1, Date d2) {
    time_t timestamp1, timestamp2;
    timestamp1 = convert_timestamp(d1), timestamp2 = convert_timestamp(d2);
    
    (timestamp1 >= timestamp2) ?
        printf("%02d-%02d-%02d %02d-%02d-%02d\n",
                d2.day, d2.month, d2.year, d1.day, d1.month, d1.year
        ) :
        printf("%02d-%02d-%02d %02d-%02d-%02d\n",
                d1.day, d1.month, d1.year, d2.day, d2.month, d2.year
        ) ;
}

int main() {
    Date d1, d2;
    scanf("%d-%d-%d %d-%d-%d",
            &d1.day, &d1.month, &d1.year, &d2.day, &d2.month, &d2.year
    );
    print_oldest(d1, d2);
    return 0;
}