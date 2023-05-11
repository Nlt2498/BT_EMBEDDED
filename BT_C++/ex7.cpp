#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Date{
    private :
        uint16_t Day;
        uint16_t Month;
        uint16_t Years;
    
    public :
        Date(uint16_t Day = 0,uint16_t Month = 0,uint16_t Years = 0);

        uint16_t Get_Day() { return Date::Day; }
        uint16_t Get_Month() { return Date::Month; }
        uint16_t Get_Years() { return Date::Years; }

        void calculateAge(uint16_t currentYear);
        void checkHoliday(uint16_t checkDay,uint16_t checkMonth);
};

Date::Date(uint16_t Day,uint16_t Month,uint16_t Years)
{
    Date::Day = Day;
    Date::Month = Month;
    Date::Years = Years;
}

void Date::checkHoliday(uint16_t checkDay,uint16_t checkMonth)
{
    if(checkDay == 1 && checkMonth == 1)
    {
        printf("It is holiday\n");
    }
    else if(checkDay == 30 && checkMonth == 4)
    {
        printf("It is holiday\n");
    }
    else if(checkDay == 1 && checkMonth == 5)
    {
        printf("It is holiday\n");
    }    
    else if(checkDay == 2 && checkMonth == 9)
    {
        printf("It is holiday\n");
    }   
    else
    {
        printf("It is not holiday\n");
    }   
}

void Date::calculateAge(uint16_t Cur_Year)
{
    uint16_t age = 0;

    age = Cur_Year - Get_Years();

    printf("Age is : %d\n",age);
}

int main(int argc, char const *argv[])
{
    Date new_date(6,11,2001);

    new_date.checkHoliday(1,1);

    new_date.calculateAge(2023);

    return 0;
}