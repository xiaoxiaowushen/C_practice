#include<stdio.h>
typedef struct 
{
    char name[20];
    int score;
    int grade;
    int cls;
}students;
void show1(students s)
{
    printf("name:%s,score:%d\n",s.name,s.score);
}
void show2(students* s)
{
    printf("grade:%d,class:%d\n",s->grade,s->cls);
}
students make(void)
{
    students s = {0};
    printf("Enter your imformation name,score,grade,cls:\n");
    scanf("%s %d %d %d",
    s.name,&s.score,&s.grade,&s.cls);
    //scanf("%s %d %d %d", s.name, &s.score, &s.grade, &s.cls);
    //                 └──┬─┘  └───┬───┘ └───┬───┘ └───┬───┘
    //               不用 &    要 &     要 &     要 &
    //为什么 s.name 不用 &？ 因为数组名本身就是地址
    return s;
}
students *pick(students *arr,int n)
{
    students *best = &arr[0];
    int i;
    for(i=0;i<n;i++){
        if(arr[i].score > best->score){
            best = &arr[i];
        }
    }
    return best;
}
int main(void)
{
    students arr[3] = {
        {"zs", 90, 1, 3},       
        {"ls", 85, 1, 3},        
        {"ww", 98, 1, 3}   }; 
   students *best = pick(arr,3);
   printf("best score!\n");
   show1(*best);
   students s2 = make();
   show1(s2);
   show2(&s2);
    return 0;
}

