#include <stdio.h>   // Include the standard I/O library for printf and scanf

int main()
{
    int amount;   // Amount of money the customer pays
    int money;    // Price of the product

    printf("Please enter the price (yuan): ");       // Prompt for the price
    scanf("%d",&money);                              // Read the price into money

    printf("Please enter the amount paid (yuan): "); // Prompt for the payment
    scanf("%d",&amount);                             // Read the payment into amount

    int change = amount - money;      // Change = amount paid - price
    printf("Change: %d yuan\n",change);   // Print the change, \n means newline
    return 0;   // Return 0 means the program ends normally
}
