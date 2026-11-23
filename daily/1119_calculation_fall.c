// 一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。 它在第N次落地时反弹多高？共经过多少米？ 保留两位小数
#include <stdio.h>
int main(void)
{
    double m;
    int n;

    scanf("%lf",&m);
    scanf("%d",&n);

    if(n<=0)
    {
        return 0;
    }

    double sum = m;
    double height = m/2;

    int i;
    for(i=2;i<=n;i++)
    {
        sum = sum +2 *height;
        height = height/2;
    }
    printf("%.2f %.2f\n",height,sum);
    

    return 0;
}