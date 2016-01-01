/*
*
*BinaryInsertionSort.cpp
*折半查找排序
* 从小到大
*/

#include <stdio.h>

//二分查找 插入排序
void binary_sertion_sort(int* array,n){
    for(int i = 2; i <= n; i++){    //从2 到 n 当前插入元素
        int low ,high ,mid;
        while(array[i] < array[i-1]){       //需要插入
            array[0] = array[i];            //哨兵
            low = 1, high = i-1;
            //寻找插入点
            while(low <= high){
                mid = (low + high) / 2 ;
                if(array[0] < array[mid]){      //判断查找区间
                    high = mid - 1;         //上半
                } else if (array[0] > array[mid]){
                    low = mid + 1;          //下半
                } else{
                    break;              //相等 直接退出 mid为插入点
                }
            }//whie 找到插入位置mid

            for(int k = i-1; k >= mid; k--){
                array[k+1] = array[k];      //后移
            }
            array[mid] = array[0];          //插入

        }
    }
    return 0;
 }

//main
 int main(){
     int a[6] = {0,5,4,3,2,1};
     binary_sertion_sort(a,5);
     for(int i = 1;i <= 5;i++){
         printf("%d ",a[i]);
     }
     printf("\n");
     return 0
 }
