/*
*2-5数据统计
*输入一些整数，输出他们的最大值，最小值，平均值
*
*
**/
#include <stdio.h>
#define INF 10000

int main(){
    int a;
    float sum = 0;
    int count = 0;
    int max = -INF;
    int min = INF;
    while(scanf("%d",&a) != EOF){
        sum += a;
        count++;
        if (a > max) {
            max = a;
        }
        if (a< min) {
            min = a;
        }
    }

    printf("%3d %3d %.3f\n",max,min,sum/count );
    return 0;

}
