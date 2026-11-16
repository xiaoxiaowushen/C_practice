//输入一个华氏温度，要求输出摄氏温度。公式为   c=5(F-32)/9，取2位小数。
#include <stdio.h>
int main(void)
{
    float c,f;

    scanf("%f",&f);
    if (scanf("%f", &f) != 1) 
    {
    printf("input error\n");
    return 1;
    }

    c = 5.0/9 *(f-32);

    printf("%.2f",c);

    return 0;
}
