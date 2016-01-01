/*
*binary_search
*折半查找
**/

#include <stdio.h>

//二分查找 a为数组 n为元素个数 key为查找的关键字
int binary_search(int* a,int n ,int key){
    int low = 0,high = n-1;
    while(low <= high){             //循环条件
        int mid = (low + high)/2;   //二分 mid
        if(key == a[mid]){
            return mid;
        } else if (key < a[mid]){   //key比中间元素小  high前移
            high = mid - 1;
        } else {                   //key比中间元素大  low后移
            low = mid + 1;
        }
    }
    return -1;                  //未找到 返回 -1

}


//主函数
int main(){
    int n ,a[100];
    printf("请输入整数的个数:\n");
    scanf("%d",&n);
    printf("请依次输入整数:\n");
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i])
    }
    int t = binary_search(a,n,5);       //二分查找
    if(t == -1){
        printf("未找到！");
    } else {
        printf("在第%d个位置找到了！",t+1);
    }
    return 0;

}
