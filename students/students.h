#ifndef STUDENTS_H//如果没有定义这个宏的话 那么我们就定义这个宏 如果已经定义这个宏了 那么以下代码就不会再出现 现在发现studens_h没有定义过 然后到下一条定义
#define STUDENTS_H//因为上面没有定义宏 所以在这里定义宏 
//叫做标准头文件结构
#define MAX_STUDENTS 4          //定义max的最大值 = 4

typedef struct {
    char name[20];
    int  score;
    int  cls;
    int  grade;
} students;

void  show1(students s);
void  show2(students *s);
students  make(void);
students *pick(students *arr, int n);

#endif//直到这里结束