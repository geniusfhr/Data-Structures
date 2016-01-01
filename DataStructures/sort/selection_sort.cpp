/*
*selection_sort
*选择排序
*
**/
#include <stdio.h>

//判断大小  a > b 返回1
int compare(int a,int b ){
    if(a > b){
        return 1;
    } else {
        return 0;
    }
}


//交换 a b
void swap(int& a, int& b ){
    int temp;
    temp = a;
    a = b;
    b = temp;
}



//从小到大   选择排序 selection_sort a待排数组  n 元素个数
void selection_sort(int* a,int n ){             // from 1 to n
    for(int i = 1; i <= n; i++ ){               //当前位置
        int min = i;
        for(int j = i ; j <= n ;j++){
            if(compare(a[min],a[j])){           //如果当前j比min小 记录下标
                min = j;
            }
        }
        swap(a[min],a[i]);                      //交换当前和以后最小值  select出了最小放在i的位置
    }
}


//main function
int main(){
    int a[] = {0,9,8,7,6,5,4};
    selection_sort(a,6);
    for(int i = 1;i <= n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
