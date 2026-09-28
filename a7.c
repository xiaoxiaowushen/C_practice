#include<stdio.h>
int main(){
    const int number = 10;//define length
    int x;
    int count[number];
    int i;

    for(i=0;i<number;i++){//from 0 to 9
        count[i]=0;//初始化数组，数组未定义里面的数字都是随机的
    }
    scanf("%d",&x);//输入数字
    while(x !=-1){//在x不是-1之前循环
        if(x>=0 && x<=9){//同时满足x大于等于0和x小于等于9这个区间 缺一不可
            count[x]++;//数字 x 又出现了一次，把它对应的计数器 +1
        }
        scanf("%d",&x);//继续循环 直到-1之前都需要输入 
    }
    for(i=0;i<number;i++){//遍历0到9
        printf("%d:%d\n",i,count[i]);
    }//输出"数字i : 出现次数" 
    return 0;
}