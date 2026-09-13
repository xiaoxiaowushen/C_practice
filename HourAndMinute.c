#include <stdio.h>   // Include the standard I/O library for printf and scanf

int main()
{
    int start_time,add_minutes;   // start_time: the start time as HHMM (e.g. 1120); add_minutes: minutes to add
    scanf("%d %d",&start_time,&add_minutes);   // Read the two integers from the keyboard

    int hour = start_time / 100;     // The hour is the first two digits: 1120 / 100 = 11
    int minute = start_time % 100;   // The minute is the last two digits: 1120 % 100 = 20

    int total = hour * 60 + minute;   // Convert the start time into total minutes (11*60 + 20 = 680)
    total = total + add_minutes;      // Add the elapsed minutes to get the total minutes of the new time

    int new_hour = total / 60;      // Integer division gives the new hour: 790 / 60 = 13
    int new_minute = total % 60;    // The remainder gives the new minute: 790 % 60 = 10

    printf("%02d%02d\n",new_hour,new_minute);   // Print as HHMM; %02d pads with a leading zero when needed
    return 0;   // Return 0 means the program ends normally

}
