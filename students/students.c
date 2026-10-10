#include <stdio.h>
#include "students.h"           

void show1(students s)
{
    printf("name:%s score:%d\n",s.name,s.score);
}  
void show2(students *s)
{
    printf("cls:%d grade:%d\n",s->cls,s->grade);
}
students make(void)
{
    students s = {0};
    printf("Enter your in formation\n");
    scanf("%s %d %d %d",
    s.name,&s.score,&s.cls,&s.grade);
        return s;
}
students *pick(students *arr, int n)
{
    int i;
    students *best = &arr[0];
    for(i=0;i<n;i++){
        if(arr[i].score > best->score){
            best = &arr[i];
        }
    }
    return best;
}