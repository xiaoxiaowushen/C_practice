#include<stdio.h>
int main(){
    const int size = 3;
    int board[size][size];
    int i,j;
    int num0fx;
    int num0f0;
    int result = -1;      // -1 = 还没人赢   1 = X赢   0 = O赢

    // ===================== ① 读入棋盘 =====================
    for(i=0;i<size;i++){//这里说明行有三格读入每一格
        for(j=0;j<size;j++){//j则是列，用for循环遍历每个j就是行
            scanf("%d",&board[i][j]);//输入你在行中的位置，数组下标
        }
    }

    // ===================== ② 检查每一【行】 =====================
    for(i=0;i<size && result==-1;i++){//检查行先从0开始 到3
        num0f0 = num0fx = 0;                  // 每一行开始数之前先清零 顺便做数据初始化
        for(j=0;j<size;j++){//再到列 
            if(board[i][j] == 1){//如果board[i][j]==1
                num0fx++;//就在这个位置加个x
            }else{
                num0f0++;//反之加0
            }
        }
        if(num0f0 == size){//如果在行里 0 = 3
            result = 0;//0赢 下面则反之
        }else if(num0fx == size){
            result = 1;
        }
    }

    // ===================== ③ 检查每一【列】 =====================
    // 注意：这一段是【独立】的，不是塞在行循环里面
    if(result == -1){//如果上面没有得出结果 就继续下面的循环 如果上面得出结果为0或-1则不能进入这个循环 直接省略这个环节
        for(j=0;j<size && result==-1;j++){    // 外层换成 j（列） 
            num0f0 = num0fx = 0;
            for(i=0;i<size;i++){              // 内层换成 i（行）
                if(board[i][j] == 1){
                    num0fx++;
                }else{
                    num0f0++;
                }
            }
            if(num0f0 == size){
                result = 0;
            }else if(num0fx == size){
                result = 1;
            }
        }
    }

    // ===================== ④ 检查【主对角线】 =====================
    if(result == -1){//同上一样
        num0f0 = num0fx = 0;
        for(i=0;i<size;i++){//遍历i行
            if(board[i][i] == 1){             // [0][0] [1][1] [2][2] 对角线就是数组下标
                num0fx++;
            }else{
                num0f0++;
            }
        }
        if(num0f0 == size){
            result = 0;
        }else if(num0fx == size){
            result = 1;
        }
    }

    // ===================== ⑤ 检查【反对角线】 =====================
    if(result == -1){
        num0f0 = num0fx = 0;
        for(i=0;i<size;i++){
            if(board[i][size-i-1] == 1){      // [0][2] [1][1] [2][0] 反对角线 i=0 size=3-0-1 i=1 size=3-1-1 位置没错
                num0fx++;
            }else{
                num0f0++;
            }
        }
        if(num0f0 == size){                 
            result = 0;
        }else if(num0fx == size){
            result = 1;
        }
    }

    // ===================== ⑥ 输出结果 =====================
    if(result == 1){
        printf("X wins\n");
    }else if(result == 0){
        printf("O wins\n");
    }else{
        printf("no winner\n");
    }

    return 0;
}


//         j=0      j=1      j=2
//      ┌────────┬────────┬────────┐
// i=0  │ [0][0] │ [0][1] │ [0][2] │     ← i 是行号
//      ├────────┼────────┼────────┤
// i=1  │ [1][0] │ [1][1] │ [1][2] │     ← j 是列号
//      ├────────┼────────┼────────┤
// i=2  │ [2][0] │ [2][1] │ [2][2] │
//      └────────┴────────┴────────┘