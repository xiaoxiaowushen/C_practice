#include <stdio.h>
int main() {
    int grades;
    printf("Enter your grade:");
    scanf("%d",&grades);
    grades /= 10;
    switch(grades){
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("F");
    }
    return 0;
    
}