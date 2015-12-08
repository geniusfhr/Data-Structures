/*
*一件衣服95元，若满消费300元，可打85折，输入购买的衣服件数，输出需要支付的金额
*结果保留两位小数
*
*/

#include <stdio.h>
int main()
{
    int n ;
    double result = 0;
    scanf("%d",&n );
    result = n * 95;

    if (result >= 300) {
        result *= 0.85;
    }

    printf("%.2f\n",result );
    return 0;
}
