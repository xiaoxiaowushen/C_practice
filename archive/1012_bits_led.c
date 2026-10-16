#include<stdio.h>
void led_on(int *state,int n)
{
    *state = *state | (1 << n);
}
void led_off(int *state,int n)
{
    *state = *state & ~(1 << n);
}
void led_show(int state)
{
    int i;
    for(i = 7;i >= 0;i--)
    {
        printf("%d",(state >> i) & 1);
    }
    printf("\n");
}
int led_is_on(int state,int n)//refer bits1_demo.c
{
    return (state>>n) & 1;
}

int main(void)
{
    int state = 0;
    printf("all turn off\n");
    led_show(state);

    led_on(&state,0);
    led_on(&state,3);
    printf("turn on 1 and 3\n");
    led_show(state);

    printf("LED3 is %s\n", led_is_on(state, 3) ? "ON" : "OFF");//
    printf("LED0 is %s\n", led_is_on(state, 0) ? "ON" : "OFF");//refer bits1_demo.c

    led_off(&state, 0);
    printf("extinguish after LED0 : ");
    led_show(state);        
    led_off(&state, 3);    
    led_show(state);
    return 0;

}