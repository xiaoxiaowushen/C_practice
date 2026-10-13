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
    return a;
}

void array_free(Array*a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int array_size(const Array*a)
{
    return a->size;
}

int* array_at(Array*a,int index)
{
    if(index >= a->size)
    {
        array_inflate(a,//a在这里是结构体指针，指向上面的结构体
            (index/BLOCK_SIZE+1)*BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}

void array_inflate(Array*a,int more_size)
{
    int new_total = a->size + more_size;
    int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
    int i;
    for(i=0;i<a->size;i++)
    {
        p[i] = a->array[i];
    }
    free(a->array);
    a->size = new_total;
    a->array = p;
}

int main (void)
{
    Array a = array_create(100);
    printf("%d\n",array_size(&a));

    *array_at(&a,0) = 10;
    // - `&a`：取主函数里结构体变量`a`的地址，传给形参`Array *a`
    // - `0`：传给形参`index`
    //在array_at 返回的是地址  return &(a->array[index]);  所以这里需要用*来解开 拿到这个地址对应的内存空间，用来赋值。
    printf("%d\n", *array_at(&a,0));

    int number=0;
    int cnt=0;
    while (number != -1)
    {
        scanf("%d",&number);
        if(number != -1)
        {
            *array_at(&a,cnt++)=number;
        }
    }
    printf("========all date========\n");
    for(int j = 0;j < cnt;j++)
    {
         printf("%d ", *array_at(&a,j));
    }
    return 0;
}
