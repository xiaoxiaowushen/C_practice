// 有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);

    long long f[100] = {0};

    if(n<=0)
    {
        printf("error\n");
        return 0;
    }

    f[1] = 1;
    if(n>=2)f[2]=2;
    if(n>=3)f[3]=3;

    int i;
    for(i = 4;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-3];
    }
    printf("%lld\n", f[n]);
    return 0;
}
