/*
*相信韩信才智过人，只要让士兵先后三人一排，五人一排，七人一排地变换队形，
*而他每次只看一眼队伍尾的人数就知道总人数了，输入包含多组数据，每组数据三个数abc
*表示队尾的人数，输出总人数的最小值或报告无解，已知总人数不小于10，不大于100 输入到文件结束为止
*样例输入
*2 1 6
*2 1 3

*样例输出
*case 1：41
*case 2: No answer
*
**/
#include <stdio.h>

int main(){
    int a,b,c;
    int case = 0;
    while (scanf("%d%d%d",&a,&b,&c) != EOF){
        case++;                                   //第case种情况
        for(int i = 10; i<=100; i++){
            if ( i%3 == a && i%5 == b && i%7 == c){
                printf("case %d: %d\n",case,i );
            }
            if (i == 101) {
                printf("case %d: No answer\n",case );
            }
        }
    }

    return 0;
}
