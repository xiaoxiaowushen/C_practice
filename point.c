#include<stdio.h>
void f(int*p);//我的f的函数需要一个int的指针
void g(int k);

int main(void)
{
    int i =6;//定义整型 i = 6
    printf("&i= %p\n",&i);//输出i的地址
    f(&i);//把i的地址 取出来交给f函数
    g(i);//把i的值给g

    return 0;
}

void f(int*p){
    printf("p=%p\n",p);//输出 p 的【值】—— p 里存的是一个地址
    printf("*p=%d\n",*p);//p 的【地址】 → 这是 p 这个变量自己住在哪
    *p = 26;//给这个地址里的东西赋值
}

void g(int k){
    printf("k=%d\n",k);//输出函数g的值=26
}