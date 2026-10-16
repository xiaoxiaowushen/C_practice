#include <stdio.h>   // Include the standard I/O library for printf and scanf

int main()
{
    int a;   // First addend
    int b;   // Second addend
    printf("Please enter two numbers: ");   // Print the prompt (no \n, cursor stays on this line)
    scanf("%d %d",&a,&b);                  // Read two integers from the keyboard into a and b
    printf("%d+%d=%d\n",a,b,a+b);          // Print the equation and its result, \n means newline

    return 0;   // Return 0 means the program ends normally
}
