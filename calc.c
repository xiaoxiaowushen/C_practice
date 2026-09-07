#include <stdio.h>

int main()
{
    //定义变量；两个操作数，一个运算符
    double a,b;
    char op;
    double result;
    //提示用户输入两个操作数和一个运算符

    printf("====欢迎使用计算器====\n");
    printf("请输入第一个操作数（例如3.5+2.1）：");
    //读取用户输入的两个操作数和运算符
    scanf("%lf %c %lf",&a,&op,&b);
    // 根据运算符进行计算
    switch(op)
    //判断运算符
    {
        case '+':
        result = a+ b;
        printf("结果为：%.2lf\n",result);
        break;
        case '-':
        result = a- b;
        printf("结果为：%.2lf\n",result);
        break;
        case '*':
        result = a* b;
        printf("结果为：%.2lf\n",result);
        break;
        case '/':
        if(b != 0)
        {
            result = a/ b;
            printf("结果为：%.2lf\n",result);
        }
        else
        {
            printf("错误：除数不能为零！\n");
        }
    }
}
