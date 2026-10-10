#ifndef STUDENTS_H
#define STUDENTS_H

#define MAX_STUDENTS 4          

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

#endif//