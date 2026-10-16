#include<stdio.h>
int main(void)
{
    struct date{
        int month;
        int day;
        int year;
    };

    struct date today;

     today.month = 05;
     today.day = 10;
     today.year = 2026;

     printf("Today is %i-%i-%i",today.year,today.month,today.day);

     return 0;
}