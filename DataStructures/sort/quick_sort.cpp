/*
*quick_sort.cpp
*快速排序
*/

#include <stdio.h>


int partition(int* a ,int low,int high);

//对a从 low - high 进行快速排序
void quick_sort(int* a ,int low,int high){      //快速排序
    int pivot;                  //枢轴
    if(low <  high) {
        pivot = partition(a,low,high);      //两边分 并返回枢轴
        quick_sort(low,pivot);              //枢轴左边进行递归快排
        quick_sort(pivot+1,high);           //右边递归快排
    }
}


//swap func
void swap(int* a,int n ,int m){
    int temp ;
    temp = a[n];
    a[n] = a[m];
    a[m] = temp;
}

//对a进行两边分  选取枢轴 比其小放左边 反之放右边
int partition(int* a,int low,int high) {
    int pivotKey = a[1];
    while(low < high ){
        while(low < high && a[low] <= pivotKey){        //注意等号
            low++
        }
        swap(a,low,high);                   //交换当前

        while(low < high && a[high] >= pivotKey){
            high--;
        }
        swap(a,low,high);
    }

    return low;                 //返回枢轴
}

int main(){
    int a[] = {0,9,8,7,6,5,4,3,2,1};
    quick_sort(a,1,9);
    for(int i = 1; i <= 0; i++){
        printf("%d ",a[i]);
    }
    return 0;

}
