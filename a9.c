#include<stdio.h>
int main(){
    const int maxNumber = 25;//定义一个不可以改变数值的量
    int isPrime[maxNumber];//让isprime使用这个量
    int i;//定义i
    int x;//定义x

    for(i=0;i<maxNumber;i++){//在0到24的格子里填1
        isPrime[i] = 1;
    }
    for(x=2;x<maxNumber;x++){//
        if(isPrime[x]){
            for(i=2;i*x<maxNumber;i++){
                isPrime[i*x]=0;//把编号 i*x 的格子，设成 0
                //到现在还是在内循环中，i=2，i<mN;i++;然后x还是=2,但i=3 i*x=6,然后继续x=2,i=4直到i=13停止循环到外循环，x++ x=3 再进入这个循环，x=3 i=2然后遍历直到i=9再重新循环 直到x=25
            }
        }
    }

    for(i=2;i<maxNumber;i++){
        if(isPrime[i]){
            printf("%d\t",i);// %d 不能少；\t 是制表符，让数字对齐
        }
    }
    printf("\n");// \n 是换行（反斜杠，不是正斜杠）

    return 0;
}
