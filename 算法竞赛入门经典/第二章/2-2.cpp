/**
*
*3n+1问题
*猜想 对于任何一个大于1的自然数 若n为奇数 则n = 3n + 1.否则变成n的一半 经过若干次这样的变换，一定会使n变为1
*输入n 输出变换次数 n<= 10^9
*样例输入 2
*样例输出 7
*/


#include <stdio.h>
int main()
{
    int n ;
    int count = 0;          //计数器
    scanf("%d",&n);
    while (n > 1)
    {
        if (n % 2 == 0 )      //偶数
            n /= 2 ;
        else
            n = 3 * n + 1;
         count++;           //+1
    }

    printf("%d\n",count);
}
