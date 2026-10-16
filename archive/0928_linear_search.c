#include<stdio.h>
int search(int key, int a[], int len){//定义一个函数search 形参定义key , a ,length
    int i ;//定义一个整型 i
    int ret = -1;//定义ret = -1 先假设没找到
    for(i=0;i<len;i++){//i 从 0 到 len-1（0~12），把每个元素都看一遍
       if(a[i] == key){//如果数组a[i]里i的数等于key 如2=2，就说明这个数存在
        ret = i;//将i的值赋给ret
        break;//不再循环
       }
    }
     return ret;//把结果交出去：找到就交位置(0~12)，没找到就交 -1
}
int main(){
    int a[]={2,4,6,7,1,3,5,9,11,13,23,14,32};
    int x;
    int loc;
    printf("Enter your number:");
    scanf("%d",&x);
    loc=search(x,a,sizeof(a)/sizeof(a[0]));//调用上面的search函数进行计算，也就是实际参数，x对应key，a对应a[]，len对应数组的长度，在这里每个数字在数组中占用4个字节 sizeof用来查询占用了多少字节，也就是52个字节除以a0的4个字节得出这个数组的长度，也就是里面有多少个数字
    if(loc != -1){//如果loc不等于-1说明上面的函数已经在数组里找到了这个数，输出结果
        printf("%d is in a %d place\n",x,loc);
    }else{//否则输出结果不存在。
        printf("%d dosen't exist\n",x);
    }
    return 0;
}