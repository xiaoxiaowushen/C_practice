#include<stdio.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;
    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);

    int ih = hour2-hour1;
    int im = minute2-minute1;
    if(im<0)
    {
        im+=60;
        ih--;
    }
    if(ih<0)
    {
        ih+=24;
    }
    printf("%d %d",ih,im);
}