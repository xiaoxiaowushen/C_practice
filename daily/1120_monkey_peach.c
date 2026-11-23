// 猴子吃桃问题。猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。 第二天早上又将剩下的桃子吃掉一半，又多吃一个。以后每天早上都吃了前一天剩下的一半零一个。 到第N天早上想再吃时，见只剩下一个桃子了。求第一天共摘多少桃子。
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);

    if(n<=0)
    {
        return 0;
    }


    long long peach = 1;
    //第N天早上剩的一个，唯一确定的值

    for(int i = 1;i<n;i++)//循环
    {
        peach = (peach + 1)*2;
        //peach = peach + 1*2 ，举例n = 2，循环一次，（1+1）*2 = 4，吃掉一半，加多吃一个，剩1，以此类推。
    }

    printf("%lld\n",peach);//输出第一天剩下的量
    return 0;
}