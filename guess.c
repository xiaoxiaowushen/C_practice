#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand (time(0));

    int guess;
    int secret = rand()%100+1;
    int tries = 0;

   do
    {
    printf("Enter your number:\n");
    scanf("%d",&guess);
    tries++;

        if(guess > secret)
        {
            printf("too high!\n");
        }
        else if(guess < secret){
            printf("too low\n");
        }
    }  while(guess != secret);
    printf("Bingo! You got it in %d tries.\n", tries);
    return 0;