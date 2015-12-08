/*
*
*输出所有形如aabb的四位完全平方数 前两位数字相等 后两位数字相等
*
*输出结果  7744
*
*/

#include <stdio.h>
#include <math.h>
int main()
{
    for (int i = 1;i<= 9;i++)        //i from 1 to 9
    {
        for (int j = 0;j<= 9;j++)   // j from 0 to 9
        {
            int n = 1100 * i + 11 * j;
            int m = floor(sqrt(n));     // floor(n)  不超过n的最大整数
            if (m * m == n)
            {
                printf("%d\n",n);           //output
            }
        }
    }
    return 0;
}
