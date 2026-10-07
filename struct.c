#include<stdio.h>
struct LED
{
    int pin;
    int state;
};
void led_off(struct LED *p)
{
    p->state = 0;
}
void led_on(struct LED *p) /* 在【声明】里：* 表示"p 是指针" */
{
    p->state = 1; /* 在【使用】时：访问它指向的东西 */
}
void led_print(struct LED *p)
{
    printf("LED on pin %d is ",p->pin); 
    if(p->state == 0)
    {
        printf("OFF\n");
    }else{
        printf("ON\n");
    }
}
int main(void)
{
    struct LED led1;
    led1.state = 0;
    led1.pin =13;
    led_print(&led1);
    led_on(&led1);
    led_print(&led1);
    led_off(&led1);
    led_print(&led1);

    return 0;
}