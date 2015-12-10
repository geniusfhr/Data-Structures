/*
*输入一些整数，求他们的最小值，最大值 和平均值（保留三位小数）输入保证这些数都不超过1000的整数
*输入应包含多组数据，每组第一个数据的第一行是整数个数n 第二行是n个整数。 n = 0为输入结束标记
*相邻两组数据之间输入一个空行
*样例输入
*8
*2 8 3 5 1 7 3 6
*4
*-4 6 10 0
*0
*
*样例输出
*case 1：1 8 4.375
*
*case 2:-4 10 3.000
*
*/


#include <stdio.h>
#define INF 10000;

int main(){
    int n ,a,kase = 0;
    double sum;
    int max = -INF;
    int min = INF;

    while(scanf("%d",&n) == 1 && n != 0){
        for(int i = 1; i<=n; i++){
            scanf("%d",&a);
            sum += a;
            if(a > max){
                max = a;
            }
            if(a < min){
                min = a;
            }
        }

        if(kase){
            printf("\n" );
        }

        printf("case %d: %d %d %.3f\n",++kase,max,min,(double)sum/n );
    }

    return 0;

}
