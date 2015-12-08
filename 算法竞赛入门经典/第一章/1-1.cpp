/*  P4
*   立例题1-1
*   输入底面半径r和高h，输出圆柱体的表面积，保留三位小数
*   样例输入
*   3.5  9
*   Area = 274.889
*
*/

#include <stdio.h>
#include <math.h>
int main()
{
    const double PI = acos(-1.0);        //acos cos x = () 反三角函数 const 常量
    double r,h,s1,s2,area;
    scanf("%lf%lf",&r,&h);              // %lf 双精度 double  %f float 单精度

    s1 = PI * r * r;            //底面积
    s2 = 2 * PI * r * h;        //侧面积
    area = a1 * 2 + s2;         //表面积 = 侧面积 + 底面积*2

    printf("Area = %.3f\n",area);           // .3 小数点后三位
    return 0;
}
