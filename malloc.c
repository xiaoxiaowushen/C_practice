#include<stdio.h>
#include<stdlib.h>

int main(void){
    int number;//定义一个整形变量number
    int* a;//定义一个指针a
    int i;//定义一个整形变量i
    printf("Enter your number:");//输出文字
    scanf("%d",&number);//读取用户输入，存到number 比如我输入5 ，然后malloc点作用就是开五个int的位置 

    a = (int*)malloc(number*sizeof(int));//在堆上动态开辟一块内存，用来存 number 个 int 整数，number*sizeof举例3*4=12占用12个字节
    //malloc 返回 void* —— 一个"没有类型"的指针
          ↓
//(int*) 告诉编译器："这块内存我要当【int 数组】用"（每一步跨 4 字节）
          ↓
//这样 a[i] 才知道该跳多远 —— 正好是你 point3.c 里观察到的 sizeof 差异

    for(i=0;i<number;i++){//循环：从下标0开始，依次输入number个整数存入动态数组
        //在这几个下标中存入你的数字 比如number等于5 那么就输入 5个数字 如 1 2 3 4 5 然后循环结束
        scanf("%d",&a[i]);//输入i的数据 
    }
    for(i=number-1;i>=0;i--){//逆序打印：i从最后一个下标(number-1)开始，到下标0结束 a[4] a[3] a[2] a[1] a[0] 然后打印 5 4 3 2 1
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}
//malloc 是向操作系统申请堆内存，这块内存不会自动还给系统。
//free(a);：把 a 指向的那一块 malloc 申请出来的内存还给操作系统。