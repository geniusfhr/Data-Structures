/*
*堆排序
*heap_sort.cpp
*
*/

#include <stdio.h>


//将数组a中m和n交换
void swap(int* a,int n ,int m ){
    int temp = a[n];
    a[n] = a[m];
    a[m] = temp;
}


//堆调整
void heapAdjust(int* a,int s, int m );


//将数组a进行堆排序 n为待排元素个数
void heap_sort(int* a,int n ){
    for(int i = n/2; i > 0; i--){
        heapAdjust(a,i,n);          //从n的调整到1 使整个成为一个大顶堆
    }

    for(int i = n; i > 1; i--){
        swap(a,i,1);                //将最大和堆顶最大元素进行交换  最后元素成为最大
        heapAdjust(a,1,i-1);          //重新调整第一个元素 保持最大堆
    }
}



//对a进行堆调整 s为当前调整元素 m为末尾元素下标
void heapAdjust(int* a,int s,int m ){
    int t ,j;
    t = a[s];
    for(j = 2*s; j <= m; j  = j*2){
        if(j < m && a[j] < a[j+1]){
            j++;                //找到s孩子结点中最大的那个 记录为j
        }
        if(t > a[j]){           //如果双亲结点比孩子结点最大的还大  不需要交换
            break;
        }
        a[s] = a[j];            //j翻上去
        s = j;                  //开始将j作为s待调整调整 讨论子节点
    }//退出循环 找到插入位置s

    a[s] = t;                   //将待调整元素插入位置
}



//main func
int main(){
    int a[] = {0,9,8,7,6,5,4,3,2,1};
    heap_sort(a,9);
    for(int i = 1;i < 9 ;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
