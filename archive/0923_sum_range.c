#include <stdio.h>

int sum(int begin, int end)
{
    int i;
    int s = 0;
    for(i = begin; i <= end; i++){
        s += i;
    }
    return s;
}

int main()
{
    printf("%d\n", sum(10, 20));

    int x = sum(1, 100);
    printf("%d\n", x);          

    return 0;
}
