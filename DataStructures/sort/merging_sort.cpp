/*
*merging_sort.cpp
*归并排序
*
**/

#include <stdio.h>


//将a中m~s b中s+1~n归并到b
void Merge(int* a,int* b ,int m,int s,int n);


//对数组a中m~n 进行归并排序至b m~n
void MSort(int* a,int* b,int m ,int n){

    int c[100];
    if(m == n){             //直到分成两个元素
        b[m] = a[m];
    } else {
    int s = (m + n)/2;
    MSort(a,c,m,s);         //递归 将a中m到s归并到c中
    MSort(a,c,s+1,n);       //递归 将a中s+1到n归并到c中
    Merge(c,b,m,s,n);       //将c中已经排好序的两部分 进行归并
    }
}


//归并
void Merge(int* a,int* b ,int m,int s,int n){
    int i,j,k = m;
    for(i = m,j = s+1; i <= s && j <= n ; k++ ){
        if(a[i] < a[j]){        //如果i < j
            b[k] = a[i++];      //较小的i放入k i后移
        }else {
            b[k] = a[j++];         //反之 j放进k  j后移
        }
    }

    while(i <= s){
        b[k++] = a[i++];
    }

    while(j <= n){
        b[k++] = a[j++];
    }
}

int main(){
    int a[] = {0,9,8,7,6,5,4,3,2,1};
    int c[100];
    MSort(a,c,1,9);
    for(int i = 1;i <= 9; i++){
        printf("%d ",c[i]);
    }
    return 0;
}
