#include <stdio.h>   // Include the standard I/O library for printf and scanf

int main()
{
    // Declare hour and minute for the two time points
    int hour1,minute1;   // First time point (hour, minute)
    int hour2,minute2;   // Second time point (hour, minute)

    // scanf reads from the keyboard: %d means integer, & means "address of" (store input into the variable)
    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);

    // Idea: convert both times to total minutes, subtract, then convert back to hours and minutes
    int t1 = hour1*60 + minute1;   // Total minutes of the first time point
    int t2 = hour2*60 + minute2;   // Total minutes of the second time point
    int t = t2 - t1;               // Time difference in minutes

    // t/60 is integer division (gives hours), t%60 is the remainder (gives minutes)
    printf("Time difference: %d hours %d minutes\n",t/60,t%60);
    return 0;   // Return 0 means the program ends normally
}
