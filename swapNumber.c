#include <stdio.h>
int main()
{
    int a=5;//initializing a with 5
    int b=6;//initializing b with 6
    int t;//temporary variable

    t=a;//storing value of a in t
    a=b;//storing value of b in a
    b=t;//storing value of t in b

    printf("a=%d,b=%d\n",a,b);//printing the values of a and b after swapping
    return 0;//returning 0 to indicate successful execution
}