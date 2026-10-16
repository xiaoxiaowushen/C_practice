#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int hight = n/16;
    int low = n%16;

    int answer = hight*10 + low;
    printf("%d\n", answer);
    return 0;
}