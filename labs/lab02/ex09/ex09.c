/* iaed-23 - ist1106485 - lab02/ex09 */

#include <stdio.h>

int main()
{
    int timestamp, hours, minutes, seconds;
    scanf("%d", &timestamp);

    seconds = timestamp % 60;
    minutes = (((timestamp % 3600) - seconds) / 60) % 60;
    hours = (timestamp - (timestamp % 3600)) / 3600;

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    
    return 0;
}
