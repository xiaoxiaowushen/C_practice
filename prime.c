#include <stdio.h>
int main()
{
    int x;              // the number being tested
    int cnt = 0;        // how many primes we have found so far

    // ===== Outer loop: test every number from 2 to 99 =====
    for(x = 2; x < 100; x++){

        int i;
        int isPrime = 1;   // flag: assume x IS prime, then try to prove it wrong

        // ===== Inner loop: look for a divisor of x =====
        for(i = 2; i < x; i++){
            if(x % i == 0){     // i divides x evenly -> i is a divisor
                isPrime = 0;    // found one, so x is NOT prime
                break;          // no need to keep searching
            }
        }

        // ===== Print x only if the flag is still up =====
        if(isPrime == 1){
            printf("%d\n", x);
            cnt++;              // count this prime
        }
    }

    printf("\nTotal: %d primes\n", cnt);
    return 0;
}
