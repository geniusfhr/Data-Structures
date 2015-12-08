/* P6
*  例题 1-2
*  输入一个三位数 分离出它的个位 十位 百位  反转后输出
*  样例输入
*  127
*  样例输出
*  721
*
*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int m = n%10 * 100 + n/10%10 * 10 + n/100;
    printf("%d%d%d\n", n%10,n/10%10,n/100);
    printf("%03d\n",m );                    //%3d  输出宽度为3 左边空格补齐  %-3d 左对齐  %03d 左边补0
    return 0;
}
