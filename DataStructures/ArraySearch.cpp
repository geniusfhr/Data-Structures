//ArraySearch
//顺序查找
//设置哨兵

#include <iostream>
#include <stdio.h>
using namespace std;

int* initArray() {
     static int elem[10];                       //函数结束调用后 static静态变量不会被释放
    printf("请输入数据的个数:" );
    int elemNum;
    scanf("%d",&elemNum);
    printf("请依次输入元素:");
    for(int i = 1;i <= ElemType; i++){
        scanf("%d",&elem[i]);
    }
    return elem;
}

void arraySearch(int* elem) {
    printf("请输入需要查找的值:" );
    int value;
    scanf("%d",&value);
    elem[0] = value;                                            //设立哨兵elem[0]
    for(int i = 10;elem[i] != value; i--){                      //elem[i] != value 循环终止
                                                                //
    }
    // 返回i即第i个元素 返回0则未找到改数据
    printf("在第%d个位置发现了该值。\n",i);
}

int main() {
    arraySearch(initArray());
    return 0;
}
