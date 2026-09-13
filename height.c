#include <stdio.h>
int main()
{
    int cm;//define int variable cm
    scanf("%d",&cm);//read integer input from keyboard and store it in cm

    double meter=cm/100.0;//Convert centimeters to meters
    double total_inch = meter / 0.3048*12;//Convert meters to inches    

    int total=(int)total_inch;//Convert double to int
    int foot=total/12;//Convert total inches to feet
    int inch=total%12;//compute the remaining inches

    printf("%d %d\n",foot,inch);//print the foot and inches
    return 0;

}