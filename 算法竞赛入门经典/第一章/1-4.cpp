/*
*1-4已知鸡和兔的数量为n,总腿数为m。输入n和m，依次输出鸡的数目和兔的数目
*样例输入
*14 32
*样例输出
*12 2
*
*样例输入
*10 16
*样例输出
*No answer
*
*/

#include <stdio.h>

int main(){
    int a,b,n,m;                    // a--鸡的数目 b--兔的数目  n头  m脚
    scanf("%d%d",&n,&m);
    a = (4 * n - m) / 2 ;
    b = n - a;
    if ( m % 2 == 1 || a<0 || b<0 )    //m是奇数 a b <0
    {
        printf("No anwer\n" );
    }
    else
    {
    printf("%d %d\n",a,b );
    }
return 0;
}
