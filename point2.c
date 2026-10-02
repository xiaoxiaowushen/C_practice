#include<stdio.h>
void minmax(int a[],int len,int *max,int *min);

int main(void){
    int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};//17 number
    int min,max;//定义两个变量
    minmax(a,sizeof(a)/sizeof a[0],&max,&min);//调用函数minmax 然后用sizeof查询数组在内存中占的字节 然后除以每个数字在内存中的字节也就是4个字节 用来得出准确的数字总量
    printf("min=%d,max=%d\n",min,max);//输出min和max的值

    return 0;
}

void minmax(int a[],int len,int *max,int *min){// 在数组 a 里找最小值和最大值
// 通过两个指针参数把结果【送回】调用者（C 只能 return 一个值，所以第二个用指针带出）

    int i;//定义整型变量i
    *min = *max =a[0];//赋值从右往左赋值 a[0]里的数是1，然后对这个地址*max里的变量做赋值 然后*max又对*min赋值 
    for(i=1;i<len;i++){//进入for循环，i=1 小于这个len也是就是a[]里数字的总数 就加加
        if(a[i]<*min){// 如果 a[i] 比当前最小值还小（此时 *min 是 1）
            *min = a[i];//那么就把a[i]的值赋给*min这个地址里的变量
            
        }
        if(a[i]>*max){//下面同上
            *max =a[i];
        }// 走完一遍循环体，i++ 后回到开头再判断，直到 i<len 不成立
    }
}