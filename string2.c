#include<stdio.h>
int main()
{
    char* month[13] = {
        "\n",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "Demceber",
    };
    int i;
    int n = 0;
    printf("Please enter your month:");
    scanf("%d",&n);
    //printf("%d",n);
  if(n >= 0 && n <= 12){                
        printf("%s\n", month[n]);       
    }else{
        printf("Invalid month\n");
    }

    return 0;

}