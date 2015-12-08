/*
*
*输入正整数n，n<360，输出n度的正弦余弦值。
*
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n ;
    double si,co;
    scanf("%d",&n);             //n是弧度 不是角度
    si = sin(n);                //<math.h>
    co = cos(n);
    printf("sin%d = %f cos%d= %f\n",n,si,n,co);
    return 0;
}
