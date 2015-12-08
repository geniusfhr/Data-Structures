/*
* 输入两个整数的值 交换二者的值 然后输出
*样例输入
*224 16
*样例输出
*16 224
*
***/

#include <stdio.h>
int main()
{
    int a,b,t;
    scanf("%d%d", &a, &b );
    t = a;              //临时变量t 交换ab
    a = b;
    b = t;
    printf("%d %d\n",a,b);
    return 0;
}
