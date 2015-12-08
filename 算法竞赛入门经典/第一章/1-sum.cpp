/*
*
*连续和 输入整数n 输出1+2+3+4..+n的值
*
*
*/

#include <stdio.h>
int main()
{
    int sum = 0 ,n;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++ )
    {
        sum = sum + i ;
    }

    printf("%d\n",sum );
    return 0;
}
