/*
*近似计算
*计算pi/4 = 1 - 1/3 + 1/5 -1/7 + ……直到最后一项小雨10^-6
*
*
*/

#include <stdio.h>
#include <math.h>
int main()
{
    int i = 0;
    double t,result = 0;
    do{
        t = 2 * i + 1;
        if (i % 2 == 0)
        {
            result += (1/t)
        }
        else
        {
            result -= (1/t);
        }
        i++;

    }while(1.0/t >= pow(10,-6));            //直到不满足   满足的条件下继续循环

    printf("%lf\n",result );
    return 0;
}
