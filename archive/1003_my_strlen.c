#include<stdio.h>
#include<string.h>

size_t mylen(const char*s){
    int idx =0;
    while(s[idx]!='\0'){//读到字符串的结束 字符串结尾一般都是\0 比如"Hello\0"
        idx++;
    }
    return idx;//返回 idx的结果
}//这个函数的目的是为了拿自己写的函数来替代strlen这个库函数 

int main(void)
{
    char line[] = "Hello";
    //printf("strline=%lu\n",strlen(line)); 这个是原本调用的库函数
    printf("strline=%lu\n",mylen(line));
    printf("sizeof=%lu\n",sizeof(line));
}

/*int main(int argc, char const *argv)
│   │    └┬─┘ └──────┬───────┘
│   │     │          └─ 第二个参数 argv
│   │     └─ 第一个参数 argc
│   └─ 函数名
└─ 返回类型 */

//strlen这个函数的作用就是为了返回s的字符串长度
//如size_t strlen（const char*s）