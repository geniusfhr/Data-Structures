/*
*输入正整数n，输出一个n层倒三角
*
**/


#include <stdio.h>
int main(){
    int n ;
    while(scanf("%d",&n) == 1){
        for(int i = n;i>=1;i--){        //从下往上第n层
            for(int j = 0; j<n-i; j++){
                printf(" ");                    //空格
            }
            for(int k = 0;k< 2*i-1;k++）{        //#
                printf("#");
            }
            printf("\n" );              //行空格
        }
        printf("\n" );
    }

    return 0;
}
