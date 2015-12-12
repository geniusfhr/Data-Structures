/*
*输入两个正整数n<m<10^6 输出1/n^2 + 1/(n+1)^2 + 1/(n+2)^2 +...1/m^2
*保留5位小数 输入包含多组数据，结束标记为n = m = 0
*样例输入
*2 4
*65536 655360
*0 0
*
*样例输出
*case 1:0.42361
*case 2:0.00001
*/

#include <stdio.h>
#include <math.h>
int main(){
    int n ,m,kase = 0;
    while(scanf("%d%d",&n,&m) == 2 && n!=0 && m!=0){
        double sum = 0;         //sum定义在循环中 每组数据 置0清空
        while(n <= m){
            double k = 0;
            k = 1 / pow(n++,2);
            sum += k;
        }
        printf("case %d: %.5f\n",++kase,sum);
    }
    return 0;
}
