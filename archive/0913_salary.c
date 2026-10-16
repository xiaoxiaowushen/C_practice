#include <stdio.h>
int main()
{
    const double rate = 8.25;
    const int STANDARD= 40;
    double pay =0.0;
    int hours;

    printf("Enter the number of hours worked: ");
    scanf("%d",&hours);
    printf("\n");

    if(hours>STANDARD)
    {
        pay = STANDARD*rate + (hours-STANDARD)*rate*1.5;
    }
    else
    {
        pay = hours*rate;
    }
    printf("The gross pay is: $%.2f\n", pay);
}