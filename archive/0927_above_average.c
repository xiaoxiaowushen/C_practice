#include<stdio.h>
int main(){
    int x;
    double sum = 0;
    int cnt = 0;
    int number[100];
    scanf("%d",&x);
    while(x != -1){
        number[cnt]=x;//Put this number into the array
        sum += x;
        cnt++;
        scanf("%d",&x);//Until -1 stops
    }
    if(cnt >0){
        printf("%.2f\n",sum/cnt);
        int i;
        for(i=0;i<cnt;i++){
            if(number[i]>sum/cnt ){
               printf("%d\n",number[i]);
            }
        }
    }
    return 0;
}