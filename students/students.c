#include <stdio.h>
#include "students.h"         //在这里声明用上students.h这个头文件 相当于把这里的代码带入进去

//#ifndef STUDENTS_H//如果没有定义这个宏的话 那么我们就定义这个宏 如果已经定义这个宏了 那么以下代码就不会再出现
//#define STUDENTS_H//因为上面没有定义宏 所以在这里定义宏 

//#define MAX_STUDENTS 4          //定义max的最大值 = 4

/*typedef struct {
    char name[20];
    int  score;
    int  cls;
    int  grade;
} students;

void  show1(students s);
void  show2(students *s);
students  make(void);
students *pick(students *arr, int n);

#endif//直到这里结束 */ 

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