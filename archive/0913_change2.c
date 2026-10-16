#include <stdio.h>
int main()
{
 int price = 0;
 int bill = 0;
 printf("Enter the price of the item: ");
 scanf("%d", &price);
 printf("Enter the bill amount: ");
 scanf("%d", &bill);

 if(bill>=price)
 {
    printf("The change to be returned is: %d\n", bill - price);
 }
 else
 {
    printf("Insufficient funds.\n");
 }

}