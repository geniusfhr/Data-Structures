/*
*输入n,计算s = 1! + 2! + 3! + 4! ...+ n!的末6位
*
*样例输入 10
*样例输出 37913
*
*/

#include <stdio.h>
int main(){
    int n,sum  = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        int term = 1;                         //每循环一次 term都要重新置为1
        for(int j = i;j >= 1; j--){
            term *= j;
        }
        sum += term;
    }

    printf("%d\n",sum%100000 );
    return 0;
}
