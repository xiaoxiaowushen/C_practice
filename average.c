#include <stdio.h>
int main()
{
    int number;
    int sum = 0;
    int count = 0;
    
    do{
    printf("Enter your number:\n");
    scanf("%d",&number);
    if(number!=-1){
        sum += number;
        count++;
        }
    }while(number != -1);
    printf("%.2f",1.0*sum/count);
    return 0;
}