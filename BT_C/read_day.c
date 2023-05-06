/*
* File: read_day.c
* Author: Nguyen Thanh
* Date: 31/3/2023
* Description: This is a file enter the date and year then display the day of the week, month, year
*/

#include <stdio.h>

enum Weekday {SUN, MON, TUE, WED, THU, FRI, SAT};
enum Month {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

typedef struct{
    int day;
    int month;
    int year;
}Date;

/*
* Function: getWeekday
* Description: This function to calculate the day of a specific date in the calendar based on Zeller's Congruence
* Input:
* day - a variable int 
* month - a variable int 
* year - a variable int 
* Output:
* d - a variable int
*/
int getWeekday(int day, int month, int year) {
    int y = year - (14 - month) / 12; // Tính toán giá trị của năm
    int x = y + y/4 - y/100 + y/400;  
    int m = month + 12 * ((14 - month) / 12) - 2; // Tính toán giá trị tháng
    int d = (day + x + (31*m)/12) % 7; // Tính toán giá trị của day đại diện cho ngày trong tuần, bắt đầu từ Chủ Nhật (0), Thứ Hai (1), đến Thứ Bảy (6)

    return d;
}

/*
* Function: printWeekday
* Description: This function print the value of the day of the week based on the result of getWeekday function
* Input:
* weekday - a variable int
*/
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

int main(int argc, char const *argv[])
{
    Date date;

    printf("Enter Day: ");
    scanf("%d", &date.day);

    printf("Enter Month: ");
    scanf("%d", &date.month);

    printf("Enter Year: ");
    scanf("%d", &date.year);
    
    printf("------------------------------------------------\n");
    printWeekday(getWeekday(date.day, date.month, date.year));
    printf(", %d / %d / %d ", date.day, date.month, date.year);

    return 0;
}
