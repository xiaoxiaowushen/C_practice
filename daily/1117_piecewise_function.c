// 有一个函数
// y={  x      x<1
//     |  2x-1   1<=x<10
//     { 3x-11  x>=10

// 写一段程序，输入x，输出y
#include <stdio.h>
int main(void)
{
    double x,y;
    scanf("%lf",&x);

    if(x<y)
    {
        y = x;
    }else if(x<10)
    {
        y = 2*x-1;
    }else if(x>=10)
    {
        y = 3*x-11;
    }

    if (scanf("%lf", &x) != 1) 
    {
    printf("input error\n");
    return 1;
    }
    
    printf("%.2f\n",y);

    return 0;
}