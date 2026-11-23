// 输入两个正整数m和n，求其最大公约数和最小公倍数。
#include <stdio.h>
int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);

    int a = m, b = n;
    int t;

    while(b!=0)
    {
        t = a%b;
        a = b;
        b = t;
    }
    int gcd = a;
    
    int lcm = m/ gcd * n;

    printf("%d%d/n",gcd,lcm);

    return 0;
}
// 1. 读入 m, n
// 2. 求最大公约数：
//    - 拿两个数 a, b
//    - 只要 b 不等于 0：
//        算 a 除以 b 的余数 t
//        把 b 的值给 a
//        把 t 的值给 b
//    - 循环结束时 a 就是答案
// 3. 最小公倍数 = m 除以 gcd 再乘 n
// 4. 输出