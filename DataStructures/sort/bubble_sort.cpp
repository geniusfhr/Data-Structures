/*
*
*bubble_sort.cpp
*冒泡排序
*
*/

#include <stdio.h>

int compare(int a,int b){
    if(a >= b)
        return 1;
    else
        return 0;
}



//exchange function
void exchange(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

//bubble sort func
void bubble_sort(int* array,int n){
    for(int i = n-1; i >= 1; i--){
        for(int j = 1;j <= i;j++){
            if(compare(array[j],array[j+1])){
                exchange(array[j],array[j+1]);
            }
        }
    }
}


int main(){
    int a[] = {0,5,4,3,2,1}
    bubble_sort(a,5);
    for(int i = 1; i <= 5; i++){
        printf("%d ",a[i]);
    }

    return 0;
}
