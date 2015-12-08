/*
*平均数 Average
*输入三个数，输出他们的平均值，保留三位小数
*
*/

#include <stdio.h>
int main()
{
    int a,b,c,sum;
    double average;
    scanf("%d%d%d",&a,&b,&c);
    sum = a + b + c;
    average = sum / 3.0;
    printf("%.3f\n",average);
    return 0;
}
