#include <stdio.h>

#define MAX 100
#define MAX_CARD_NAME 50
#define MAX_NUMS 10
#define MAX_CALLS 1000

typedef struct {
    int day;
    int month;
    int year;
} Date;


typedef struct {
    Date date;
    int duration;
    int dest_num;
} Call;


typedef struct {
    int number;
    char card[MAX_CARD_NAME];
    int price;
    Call calls[MAX_CALLS];
} Phone;


typedef struct {
    unsigned long long int num;
    char name[MAX];
    char address[MAX];
    Date date;
    Phone phone_nums[MAX_NUMS]
} Client;


float valorTotal(Phone *t, int n) {
    float debt = 0;
    int i;

    for (i = 0; i < n; i++) {
        debt += t[i].price;
    }
    return debt;
}