#include <stdio.h>
class Date{
    public:
        int diffInYears(Date date2);
        int diffInMonths(Date date2);
        int diffInDays(Date date2);
        int diffInHours(Date date2);
        Date(int year,int month, int day, int hour);
    public:
        int year;
        int month;
        int day;
        int hour;
};

Date::Date(int year,int month, int day, int hour){
    (*this).year = year;
    (*this).month = month;
    (*this).day = day;
    (*this).hour = hour;
}

int Date::diffInYears(Date date2){
    return year-date2.year;
}

int Date::diffInMonths(Date date2){
    return month-date2.month;
}

int Date::diffInDays(Date date2){
    return day-date2.day;
}

int Date::diffInHours(Date date2){
    return hour-date2.hour;
}


int main(void){
    Date date1(2018,8,13,23);    
    Date date2(2009,3,6,12);
    printf("%i\n", date1.diffInYears(date2));
    printf("%i\n", date1.diffInMonths(date2));
    printf("%i\n", date1.diffInDays(date2));
    printf("%i\n", date1.diffInHours(date2));
}