/*
*
*输入三角形的三条边的长度，均为正整数，判断是否能为直角三角形的三个边长
*如果可以，则输出yes，如果不能，则输出no，如果根本无法构成三角形，则输出not a triangle
*
*
*/

#include <stdio.h>
int main()
{
    int a,b,c;
    int aa,bb,cc;
    scanf("%d%d%d",&a,&b,&c );
    if ((a + b > c) && (a + c > b))                 //两边之和大于第三边
    {//满足三角形
        aa = a * a;
        bb = b * b;
        cc = c * c;
        if (aa == bb+cc || bb == aa+cc || cc == aa+bb)
        {//满足勾股定理
            printf("yes\n" );
        }
        else
        {//不满足勾股
            printf("no\n" );
        }

    }
    else
    {//不满足三角形
        printf("not a triangle\n");

    }
    return 0;
}
