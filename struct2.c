#include<stdio.h>
struct point
{
    int x;
    int y;
};

struct point* getStruct(struct point *);
void output(struct point);
void print(const struct point *p);

int main(void)
{
    struct point y = {0,0};//y = {x=0,y=0}
    getStruct(&y);//调用函数 &y的意思是把这个地址的传给getStruct这个函数 比如输入scanf里的值  1 2然后 y = {x=1,y=2}
    output(y);//打印出来 1 ， 2
    output(*getStruct(&y));
    //嵌套调用要从内往外读
    //output(*getStruct(&y));
    //└──┬─┘└───────┬──────┘
    //第 3 步      第 1、2 步
    //这里重新scanf 3 4 y={x=3,y=4} output负责打印3和4
    //在这里*号作为运算符 用来解引用这个函数的返回地址，用 * 顺着地址找到那个结构体本身
    print(getStruct(&y));
    //也是同样 scanf输入 但是调用print输出
}

struct point* getStruct(struct point *p) //参数p收到&y的地址 
//通过指针把用户输入写进外面的结构体，然后把那个地址交回去。 在这个例子里它原样返回，所以 getStruct(&y) 其实就是 &y
//外面的意思是struct point *p 返回一个指针 指向struct point
//参数：struct point *p 一个指向结构体的指针，p 指向谁由调用方决定（这里指向 main 里的 y）。 
{
    scanf("%d",&p->x);
    //输入一个值赋给p指向的那个变量x
    //->的优先级比&高 scanf 要地址才能写进去。p->x 是值，&p->x 才是"x 那一格的地址"
    //第一步：p->x       顺着 p 找到那个结构体的 x 成员
    //第二步：&(p->x)    取 x 那个格子的【地址】
    scanf("%d",&p->y);
    printf("%d %d",p->x,p->y);
    return p;//把 p那个地址交回去，外面可以接着用它
}
void output(struct point p)//output：接收一个结构体（【值传递】，整块拷贝一份），打印它的 x 和 y
{
    printf("%d,%d",p.x,p.y);//p 是结构体【变量】，所以访问成员用 .（点）
}
void print(const struct point *p)//接受一个指针，只读不修改，这个地址指向point这个结构体
{
    printf("%d,%d",p->x,p->y);//输出用p->x
}