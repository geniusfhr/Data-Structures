/*习题2-1
*水仙花数
*输出100-999中的所有水仙花数 若3位数ABC满足 ABC = A^3 + B^3 + C^3
*则其称为水仙花数 例如153 = 1^3 + 5^3 + 3^3
*
*
*
***/
#include <stdio.h>
#include <math.h>

int main()
{
    for(int i = 100; i<=999; i++){
        int a = i/100;
        int b = i/10%10;
        int c = i%10;

        if (pow(a,3) + pow(b,3) + pow(c,3) == i){
            printf("%d\n",i );
        }
    }

    return 0;
}
