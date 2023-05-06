#include <stdio.h>

/*INITIALIZE CONSTANT -------------------------------------------------*/ 

enum Weekday {SUN, MON, TUE, WED, THU, FRI, SAT};
enum Month {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

typedef struct{
    int day;
    int month;
    int year;
}Date;

/*INITIALIZE FUNCION --------------------------------------------------*/

int getWeekday(int day, int month, int year);
void printWeekday(int weekday);

/*MAIN CODE -----------------------------------------------------------*/
int main() {
    Date date;

    printf("Input Day: ");
    scanf("%d", &date.day);

    printf("Input Month: ");
    scanf("%d", &date.month);

    printf("Input Year: ");
    scanf("%d", &date.year);
    printf("");
    printWeekday(getWeekday(date.day, date.month, date.year));
    printf(", %d / %d / %d ", date.day, date.month, date.year);
    return 0;
}

int getWeekday(int day, int month, int year) {
    int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int d = (day + x + (31*m)/12) % 7;

    return d;
}

void printWeekday(int weekday) {
    switch(weekday) {
        case SUN:
            printf("SUNDAY");
            break;
        case MON:
            printf("MONDAY");
            break;
        case TUE:
            printf("TUESDAY");
            break;
        case WED:
            printf("WEDNESDAY");
            break;
        case THU:
            printf("THURSDAY");
            break;
        case FRI:
            printf("FRIDAY");
            break;
        case SAT:
            printf("SATURDAY");
            break;
        default:
            printf("INVALID");
            break;
    }
}


