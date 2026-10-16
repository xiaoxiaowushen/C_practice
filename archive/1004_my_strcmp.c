/*int strcmp(const char *s1,const char *s2);
比较两个字符串，返回：
  0     : s1 == s2
  正数  : s1 > s2
  负数  : s1 < s2
*/
/*等于 → 返回 0
s1 大于 s2 → 返回【正数】
s1 小于 s2 → 返回【负数】*/
#include<stdio.h>
#include<string.h>

int mycmp(const char* s1,const char* s2)
{
    while( *s1 == *s2 && *s1 != '\0'){
        s1++;
        s2++;
    }
    return *s1-*s2;
}
int main(void)
{
    char s1[] = "abc"; //正常的字符串输出 abc\0
    char s2[] = "abc ";//下面是abc \0 会多一个空格 然后strcmp比较的时候比较不上 多一个空格 在ascii码里一个' '空格 = 32 ；所以返回他们的差值 
    printf("%d\n",mycmp(s1,s2));
}