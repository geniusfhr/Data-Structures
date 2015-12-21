//判断质数 isPrimer.cpp
//2015.11.30

#include <stdio.h>

void isPrimer(int n) {
    if (n < 2 ) {
        printf("%d不是质数!\n",n);
        return ;
    }
    for (int i = 2; i * i <= n; i++) {              //i*i < n
        if (n % i == 0) {
            printf("%d不是质数！\n",n);              //可以除尽 有因数
            return;
        }
    }
    printf("%d是质数！\n",n);                       //结束循环 没有因数
    return ;
}  

int main(){

    for (int i  = 1; i<=100; i++) {
        isPrimer(i);
    }

    return 0;
}
