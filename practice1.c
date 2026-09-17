#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);

    int i,j,k;
    int cut = 0;

    i = a;
    while(i <= a+3){
        j = a;
        while(j<=a+3){
            k = a;
            while(k <=a+3){
                if(i != j){
                    if(i != k){        // fixed: was a duplicate of (i != j)
                        if(j != k){
                            cut++;
                            printf("%d%d%d", i, j, k);   // fixed: variables moved outside the quotes
                            if(cut == 6){
                                printf("\n");           // fixed: /n -> \n
                                cut = 0;
                            }
                            else{
                                printf(" ");           // space between numbers on the same line
                            }
                        }
                    }
                }
                k++;    // fixed: added increment
            }
            j++;        // fixed: added increment
        }
        i++;            // fixed: added increment
    }
    return 0;           // added
}
