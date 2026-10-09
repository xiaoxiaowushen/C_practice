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
    printf("name:%s score:%d",
    s.name,s.score);
}
void show2(students *s)
{
    printf("grade:%d cls:%d",
    s->grade,s->cls);
}
students make(void)
{
    students s = {0};//
    printf("Enter your imformation:name,score,grade,cls\n");
    scanf("%s %d %d %d",
        s.name,&s.score,&s.grade,&s.cls);
        return s;
}
students *pick(students *arr,int n );//
{
    int i;
    students *best = &arr[0];//best 是一个指针，指向一个学生；一开始让它指向 arr[0]
    for(i=0;i<n;i++){//
        if(arr[i].score > best->score){//
            // └──┬──┘         └──┬───┘
            //  东西 用 .       地址 用 ->
            best = &arr[i];//
            //students  *best;       /* best 是【指针】 → 用 -> */
            //students   b;          /* b  是【变量】   → 用 .  */
        }
    } 
    return best;
}
int main(void)
{
    students arr[4] = {
                      {"wx",90,1,3,},
                      {"li",92,2,3,},
                      {"ls",98,4,3,},
                      {"lz",91,1,3,}
                    };
    students *best = pick(arr,4);//
    printf("Best score:\n");//
    show1(*best);//
    students s2 = make();//
    show1(s2);
    show2(&s2);
    return 0;

}
