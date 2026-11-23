/*题目描述: 所给字符串正序和反序连接，形成新串并输出
输入格式 任意字符串（长度<=50）
输出格式 字符串正序和反序连接所成的新字符串
样例输入 123abc
样例输出 123abccba321*/
#include <stdio.h>
#include<string.h>

int main(void)
{
    char s[105];

    scanf("%s",s);

    int len = strlen(s);

    printf("%s",s);
    for(int i=len-1;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}
// %c：打印单个字符。需要传入一个字符变量或数组元素（如 s[i]）。

// %s：打印整个字符串。需要传入字符串的首地址（如 s 或数组名），它会一直打印直到遇到 \0。