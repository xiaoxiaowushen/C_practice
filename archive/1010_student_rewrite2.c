#include<stdio.h>
typedef struct
{
    char name[20];
    int age;
    int cls;
    int grade;
}students;
void show1(students s)
{
    printf("name:%s,age:%d ",s.name,s.age);
}
void show2(students *s)
{
    printf("class:%d,grade:%d",s->cls,s->grade);
}
students make(void)
{
    students s = {0};
    printf("Enter: name age cls grade\n");
    scanf("%s %d %d %d", s.name, &s.age, &s.cls, &s.grade);
    return s;                             
}
students *pick(students* arr,int n)
{
    int i;
    students *best = &arr[0];//
    for(i=0;i<n;i++){
        if(arr[i].age > best->age){//
            best = &arr[i];//
        }
    }
    return best;
}
int main(void)
{
    students arr[4]={//
        {"wz",19,3,1},
        {"w1",18,3,1},
        {"qz",19,3,1},
        {"w1",20,3,1}
    };
    students *best = pick(arr,4);//
    show1(*best);//
    students s2 = make();
    show1(s2);
    show2(&s2);

    return 0;
}