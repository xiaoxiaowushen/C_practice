#include <stdio.h>
int main()
{
    int x;
    int one, two, five;

    scanf("%d", &x);

    // x is in yuan, so x*10 converts it to jiao
    for(one = 1; one < x*10; one++){
        for(two = 1; two < x*10/2; two++){
            for(five = 1; five < x*10/5; five++){
                if(one + two*2 + five*5 == x*10){
                    printf("You can get %d yuan by adding %d 1-jiao + %d 2-jiao + %d 5-jiao\n",
                           x, one, two, five);
                    goto out;   // found one! jump out of ALL three loops at once
                }
            }
        }
    }

out:                    // goto jumps here
    return 0;
}
