/*输入一个正整数n (1≤ n ≤6),再输入一个n 行n列的矩阵，找出该矩阵中绝对值最大的元素以及它的行下标和列下标。*/

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    //输入决定跑几行几列，1 = 1*1 元素个数 1 ，2 = 2*2 元素个数4以此类推

    int max_abs = -1;
    //最大绝对值
    int max_val = 0;
    //存放最大的一个value

    int max_i = 0;int max_j = 0;
    //最大的i和j

    for(int i=0;i<n;i++)//正整数n跑一遍遍历，n次，当前i = 当前第几行
    {
        for(int j=0;j<n;j++)//二层循环次，当前j = 当前第几列
        {
            int x;
            scanf("%d",&x);

            int abs_x = x < 0 ? -x:x;
            //用一个abs_x来存放数值，先让x进行判断，如果是负数就取表达式1变正，为负就取表达式2取原样。

            //条件 ? 表达式1 : 表达式2
            //条件成立（真）  →  取 表达式1 的值
            //条件不成立（假）→  取 表达式2 的值

            if(abs_x > max_abs)
            //在循环里判断，这里abs_x已经取了我们输入x的值，如果大于就进行下面操作
            {
                max_abs = abs_x;
                //将输入的值存入max_abs中，之后继续比较，absolute绝对值
                max_val = x;
                //同样将这次的x存入max_val之中，存入的是原值

                max_i = i;
                //然后将本次i存进max_i之中，记录这个数的行
                max_j = j;
                //记下列
            }
        }
    }
    printf("%d %d %d\n",max_val,max_i,max_j);
    return 0;
}
