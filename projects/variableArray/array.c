#include "array.h"
#include<stdio.h>
#include<stdlib.h>

const int BLOCK_SIZE = 20;
// typedef struct
// {
//     int *array;
//     int size;
// }Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
//把 malloc 申请到的堆内存**首地址**，存入结构体里的指针变量 `a.array`。 
//     malloc 返回的地址类型是 `void*`
// `void*` 意思：**只知道是个地址，不知道这个地址存的是什么类型数据**。
// C 语言要求：你要用它存 int，就要强制转成 `int*`。
// `(int *)malloc(...)`：告诉编译器：这个地址指向的内存，存的是 int 类型
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size =0 ;
}
int array_size(const Array *a)
{
    return a -> size;
}
int *array_at(Array*a,int index)
//：调用`array_at`拿到数组下标 0 元素的地址，对这个地址解引用，往这个内存位置写入 10
{
    // return &(a->array[index]);
    //调用 array_at，拿到数组第 2 号元素的地址；用`*`读取这个地址里存的数字，打印这个数字。

    if(index >= a->size)//如果我想要访问的下标 index，已经超出当前数组可用容量了
    {
        array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE - a->size);
// 举例子：
// 当前 `a->size = 20`，我访问 `index=22`
// 1. `index / BLOCK_SIZE` → `22 / 20 = 1`（整数除法，丢掉小数）
// 2. `+1` → `1+1 =2`
// 3. `* BLOCK_SIZE` → `2*20 =40` → 扩容之后总容量目标是 40
// 4. `- a->size`：`40 - 20 = 20` → more_size=20
// 调用 `array_inflate(a,20)`，新增 20 个位置，总容量变成 40。
    }
    return &(a->array[index]);
}
void array_inflate(Array *a,int more_size)
{
    int new_total = a->size + more_size;
    int *p = (int*)malloc(sizeof(int)*(a->size + more_size));//开辟一块更大的堆内存，指针 p 保存这块新内存的起始地址 
    int i;
    for(i=0;i<a->size;i++)
    {
        p[i] = a->array[i];//遍历原来数组所有元素，**把旧数组全部复制到新开辟的大数组里面**。
    }
    free(a->array);
    a -> array = p;
    // p 是新内存的起始地址。
    // 把结构体里的指针 `a->array`，指向这块新的更大的堆内存。
    a -> size = new_total;
}

int main(void)
{
    Array a = array_create(100);
    printf("%d\n",array_size(&a));
    *array_at(&a,0) = 10;
    printf("%d\n", *array_at(&a,0));
    
    int number = 0;
    int cnt = 0;
    while(number != -1)
    {
        scanf("%d",&number);
        if(number != -1)
        {
            *array_at(&a,cnt++) = number;
// - `&a`：把动态数组结构体 a 的地址传给 array_at 函数
// - `cnt`：当前要存入的数组下标
// - array_at 内部：
// 如果 `cnt >= a->size`，自动调用 array_inflate 扩容；然后返回这个下标元素的地址。
//把 `number` 里面存放的那个数字，拷贝到数组对应下标位置。
        }
    }
    printf("====all date in array====\n");
for(int j = 0; j < cnt; j++)
{
    printf("%d ", *array_at(&a,j));
}
printf("\n");

    array_free(&a);

    return 0;
}
// 初始：cnt=0，a->size=20，BLOCK_SIZE=20

// 1. while：`*array_at(&a, cnt++) = number;`，cnt=0，呼叫 array_at
// 2. array_at 收到 index=0。0 >= 20？不成立，不用扩容。直接返回 & a->array [0]
// 3. 回到 while，把 number 写入下标 0；cnt 变成 1

// > 
// > 前 20 次都不会触发扩容，array_inflate 不会被调用！

// 等到 cnt=20 的时候：

// 1. while：呼叫 array_at，index=20
// 2. array_at 判断 `20 >= 20` → true！需要扩容
// 3. array_at 计算 more_size=20，**呼叫 array_inflate**
// 4. array_inflate：开辟更大内存，拷贝旧数据，释放旧内存，更新 size 到 40，return 回到 array_at
// 5. array_at 返回下标 20 的地址
// 6. while 拿到地址，写入数字，cnt++ 变成 21