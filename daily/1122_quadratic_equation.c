/*题目描述
解一元二次方程ax^2+bx+c=0的解。

输入格式
a,b,c的值。

输出格式
输出两个解，按照大小顺序输出，一个解时需要打印两次，不用考虑无解问题，保留两位小数*/
#include <stdio.h>
#include<math.h>

int main(void)
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);

    double delta = b*b - 4*a*c;

    double x1 = (-b + sqrt(delta))/(2*a);
    double x2 = (-b - sqrt(delta))/(2*a);

    if(x1<x2)
    {
        double temp;
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    printf("%.2f %.2f\n",x1,x2);
    return 0;
}