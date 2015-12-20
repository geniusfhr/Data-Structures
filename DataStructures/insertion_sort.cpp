/*
*插入排序
*
*/


#include <stdio.h>
#define MAX 100
int a[MAX];



void insertion_sort(int* a,int n ){
    for(int i = 2;i <= n;i++ ){
        int key = a[i];
        int j;
        for(j = 1;j <= i-1; j++){
            if(key <= a[j]){
                break;
            }
        }
        for(int k = i-1; k >= j;k--){
            a[k+1] = a[k];
        }
        a[j] = key;
    }
}


int main(){
    int a[10] = {0,5,4,3,2,1};
    insertion_sort(a,5);
    for(int i = 1;i<=5;i++){
        printf("%d",a[i]);
    }
    return 0;
}
