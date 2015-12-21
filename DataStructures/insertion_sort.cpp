/*
*insetion_sort.cpp
*插入排序
*
*有序段不断增加 无序段元素不断减少的过程
*/

#include <stdio.h>

//先找位置 再移动插入
void my_insertion_sort(int* a,int n ){       //直接插入排序 从小到大
    for(int i = 2; i <= n; i++){
        a[0] = a[i];                     //哨兵 记录插入元素
        if(a[i] < a[i-1]){              //与有序端最后比较  需要插入
             int j;
             for( j = 1; j <= i-1; j++){
                if(a[0] <= a[j])          //找到插入的位置 j 跳出循环
                    break;
            }
  
            for(int k = i-1; k >= j; k--){      // j 到 i-1 后移一位
                a[k+1] = a[k];
            }
            a[j] = a[0];                       //插入该元素
        }
    }
}


//从小到大 直接插入排序
//比较 移动同时进行

void std_insertion_sort(int* a,int n ){
    for(int i = 2;i <= n; i++){      //从 2 到  n
        if(a[i] < a[i-1]){          //有必要插入
             a[0] = a[i];           //设立哨兵 需要插入的元素
             a[i] = a[i-1];
             int j;
             for(j = i-2; a[0] <= a[j] && j>0 ;j--){
                 a[j+1] = a[j];        //后移
             }
             a[j+1] = a[0] ;          //插入元素
        }
    }
}

int main(){
    int a[10] = {0,1,2,3,4,5};
    std_insertion_sort(a,5);
    for(int i = 1;i<=5;i++){
        printf("%d ",a[i]);
    }
    return 0;

}
