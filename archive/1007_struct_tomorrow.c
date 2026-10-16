#include<stdio.h>
#include <stdbool.h> 
struct date//定义一个结构体相当于图纸（规定每个房间里有 3 样东西）
{
    int month;
    int day;
    int year;
};
bool isLeap(struct date d);
//bool  isLeap ( struct date d ) ;
//└─┬─┘ └─┬──┘  └─────┬─────┘ └┬┘
//返回值  函数名  参数的【类型】名字
 //类型 //struct date  d; /* 一个 struct date 变量，叫 d */
int numberofDays(struct date d);

int main(void)
{
    struct date today,tomorrow;//定义结构体类型相当于盖了两间房，叫today和tomorrow 这两个房子里面都有三个格子 叫做month day 和year

    printf("Enter today's date(mm dd yyyy):");
    scanf("%i %i %i",&today.month,&today.day,&today.year);
    if(today.day != numberofDays(today))//如果今日的日期不等于这个月的总天数（说明今天不是月末）
    {
        tomorrow.day = today.day+1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }else if(today.month == 12){
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year +1;
    }else{
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    printf("Tomorrow date is %i %i %i\n",
    tomorrow.year,tomorrow.month,tomorrow.day);

    return 0;
}

int numberofDays(struct date d)//返回 d 这个月有几天（2 月会调用 isLeap 判断闰年）
{
    int days;

    const int daysPermonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(d.month == 2 && isLeap(d))// 如果 月份==2 并且 是闰年 → 29 天
                                // （比如 2024 年 2 月：2==2 真，isLeap 也真 → 走这里）
    {
        days = 29;
    }else{//否则 days 进入平年的表格 因为数组下标是从0开始 所以这里d.month需要减1
        days = daysPermonth[d.month -1];
    }

    return days;//把算好的天数交回调用处 —— main 里那个 numberofDays(today) 会被这个值顶替
}

bool isLeap(struct date d)
//判断 d 的年份是不是闰年：是 → true，不是 → false
//bool用途：表示只有两种答案的东西 —— 是/否、真/假、成立/不成立。 底层就是 1 和 0，但写成 true/false
{
    bool leap = false;//目前不是闰年
    if(d.year %4 == 0 && d.year %100 !=0 || d.year%400 == 0)
/*d.year % 4 == 0        年能被 4 整除
&&                     并且
d.year % 100 != 0      年不能被 100 整除
||                     或者
d.year % 400 == 0      年能被 400 整除*/
    leap = true;

    return leap;
}