#include <stdio.h>

//静态查找
int sequential_search(int* array,int n ,int key){      //array中 1~n 为数据元素
    int i = n;
    array[0] = key;     //哨兵
    while(array[i] != key){
        --i;
    }
    return i;       //表示查找的元素为第i个  0表示未找到
}



int main(){
    int a[]= {0,1,2,3,4,5};
    int location = sequential_search(a,5,1);
    if(location){
        printf("在第%d个位置找到了！\n",location);
    } else {
        printf("未找到该元素！\n");
    }
    return 0;
}
