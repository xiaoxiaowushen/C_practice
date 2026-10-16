#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int unit = n%10;
    int tens = (n/10)%10;
    int hundreds = n/100;

    int reverseNum = unit*100 + tens*10 + hundreds;

    printf("%d\n", reverseNum);

    return 0;
}