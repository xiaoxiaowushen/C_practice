//char *strchr（const char*s，int c） 这段话的意思是我要在字符串里找到c第一次出现的位置 返回指针
//char *strrchr（const char*s int c） strrchr表示从右边开始找过来
//返回null表示没有找到
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(void){
    char s[] = "Hello";
    char *p =strchr(s,'l');
    char *t=(char*)malloc(strlen(p)+1);
    strcpy(t,p);
    printf("%s\n",t);
    free(t);
    return 0;
}