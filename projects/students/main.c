#include <stdio.h>
#include "students.h"

int main(void)
{
    students arr[MAX_STUDENTS] = {
        {"wt",90,3,1},
        {"xx",87,3,2},
        {"wz",60,1,3},
        {"op",70,4,1},
     };
    students *best = pick(arr,MAX_STUDENTS);
    printf("Best: ");
    show1(*best);

    students s2 = make();
    show1(s2);
    show2(&s2);

    return 0;
}