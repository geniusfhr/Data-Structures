/*
* 1-5
*三整数排序
*输入三个整数后 从小到大排序
*
*/

#include <stdio.h>
int main()
{
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    if (a > b) {               // a b c 交换ab 使b > a
        t = a;
        a = b;
        b = t;
    }
    if (b > c) {            //比较b c  使c > b
        t = b;
        b = c;
        c = t;
    }                       //排完第一轮 c最大

    if (a > b) {
        t = a;
        a = b;
        b = t;          //交换ab  使b第二大
    }

    printf("%d %d %d\n",a,b,c);
    return 0;
}
