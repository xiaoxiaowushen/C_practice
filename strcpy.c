//char *strcpy(char *restrict dst ,const char*restrict src);
//把src的字符拷贝到dst
//restrict 是关键词表示 src和dst不能重叠
//（我原来的想法：这里是不是和前面讲的指针地址有重合？比如 char *a="hello"; char *a2="hello";
//  它们的地址都指向同一个地方 —— 对！那是【编译器的字面量合并】优化
//  而 restrict 管的是"传进来的两个地址所指的【内存区间】别重叠"，比如 strcpy(s, s+6) 自己盖自己
//  两个都跟地址有关，但不是一回事）
#include<stdio.h>
#include<string.h>

char* mycpy(char*dst,const char*src)   // ← 改这里：第二个参数叫 src，不是 dst
{
    int idx = 0;//先定义一个值来存变量
    while(src[idx] !='\0')//当idx到结尾的时候跳出循环
    {
        dst[idx] = src[idx];//例子 dst[0] = src[0] dst[0]=a src[0]=a
        idx++;//idx自增 然后到\0跳出循环
    }
    dst[idx] = '\0';//因为idx已经跳出循环了 所以要在末尾给他加\0
    return dst;
}
int main(void){
    char s1[32] = "abc";      // 给足空间（比"刚好4字节"安全）
    char s2[32] = "cba";

    mycpy(s1,s2);             // ← 改这里：调用自己的，不是库里的
    printf("mycpy 之后 s1 = [%s]\n", s1);
    return 0;
}
