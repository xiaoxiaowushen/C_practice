#include<stdio.h>
void f(void){
    char word[8];
    char word1[8];
    scanf("%7s",word);
    scanf("%7s",word1);
    printf("##%7s##%7s",word,word1);

}
int main(void){
    f();

    return 0;
}