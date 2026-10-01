#include<stdio.h>

void swap(int *pa,int *pb);//声明定义两个整型

int main(){
    int a=5;
    int b=6;
    swap(&a,&b);//调用swap函数
    printf("a=%d,b=%d\n",a,b);

    return 0;
}

void swap(int *pa,int *pb){
    int t= *pa;//定义一个整型t 用来存放这个*pa的值 也就是t = 5
    *pa = *pb;//然后让*pa=*pb 也就是让a=b a = 6
    *pb = t;//最后让 b =5
}